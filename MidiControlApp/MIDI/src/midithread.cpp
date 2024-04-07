#include "midithread.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <string>

#include <iomanip>

#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#include <algorithm>
#include <chrono>
void MIDI::Stop()
{

}

MIDI::~MIDI(){
    Stop();

}

void callback(double deltatime, std::vector< unsigned char >* message, void* _this)
{
    unsigned int nBytes = message->size();
    for (unsigned int i = 0; i < nBytes; i++)
        std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
    if (nBytes > 0)
        std::cout << "stamp = " << deltatime << std::endl;
    midiSignal midiS;
    midiS.byte[0] = message->at(0);
    midiS.byte[1] = message->at(1);
    midiS.byte[2] = message->at(2);
    midiS.byte[3] = 0;

    static_cast<MIDI*>(_this)->processInput(midiS);


}

MIDI::MIDI(string _jsonFileName):modes(), header(), json(_jsonFileName,&modes,&header)
{
    jsonFileName = _jsonFileName;
    if (json.GetLoaded())
    {
        std::cout << "initialize MidiOut" << std::endl;
        mOut = new MidiOut(json.DevName, json.DevOutput, &callback,this);
    }
    else
    {
        std::cout << "major error -- jsonParser did not load" << std::endl;
        return;
    }
    int err = 0;

    execHeader(); //execute the commands in the header
    SelectedModeIndex = json.GetSelected();
    CurrentMode = modes.at(SelectedModeIndex);
    
    processMode(CurrentMode);

}



void MIDI::execHeader()
{
    for(std::vector<Actions>::iterator it = header.begin();
        it != header.end();
        it++)
    {
        for(std::vector<devActions>::iterator devIt = it->out.begin();
            devIt != it->out.end();
            devIt++)
        {
            if(devIt->tp == midi)
            {
                mOut->send_midi(devIt->mAct.midi.byte,sizeof(midiSignal));
                if(devIt->mAct.delay > 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(devIt->mAct.delay));
                }
            }
        }
    }
}

void MIDI::processMode(ModeType m)
{
    for(std::vector<Actions>::iterator h_it =  m.header.begin();
        h_it != m.header.end();
        h_it++)
    {
        for(std::vector<devActions>::iterator out_it = h_it->out.begin();
            out_it != h_it->out.end();
            out_it++)
        {
            if(out_it->tp == devType::midi)
            {
                mOut->send_midi(out_it->mAct.midi.byte,sizeof(midiSignal));
                if(out_it->mAct.delay > 0)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(out_it->mAct.delay));
                }
            }
        }
    }
}


void MIDI::processInput(midiSignal midiS)
{
    
    {
        lock_guard<mutex> locker(locking_mechanism);

        midiActions tmp;
        tmp.midi = midiS;


        if (CurrentMode.is_active)
        {

            for (std::vector<Actions>::iterator it_act = CurrentMode.body_actions.begin(); it_act != CurrentMode.body_actions.end(); it_act++)
            {

                switch (it_act->in.mAct.midi_mode)
                {
                case midi_trigger_higher:
                {
                    if ((it_act->in.mAct.midi.byte[0] == midiS.byte[0]) &&
                        (it_act->in.mAct.midi.byte[1] == midiS.byte[1]) &&
                        (it_act->in.mAct.midi.byte[2] < midiS.byte[2]))
                    {
                        mOut->QueueOutput(it_act->out);

                        if (it_act->change_mode && it_act->change_to != -1)
                        {
                            changeMode(it_act);
                        }
                    }
                }
                break;
                case midi_trigger_lower:
                {
                    if ((it_act->in.mAct.midi.byte[0] == midiS.byte[0]) &&
                        (it_act->in.mAct.midi.byte[1] == midiS.byte[1]) &&
                        (it_act->in.mAct.midi.byte[2] > midiS.byte[2]))
                    {

                        mOut->QueueOutput(it_act->out);

                        if (it_act->change_mode && it_act->change_to != -1)
                        {
                            changeMode(it_act);
                        }
                    }
                }
                break;

                case midi_normal:
                case midi_spot:
                case midi_blink:
                {
                    if ((it_act->in.mAct.midi.byte[0] == midiS.byte[0]) &&
                        (it_act->in.mAct.midi.byte[1] == midiS.byte[1]) &&
                        (it_act->in.mAct.midi.byte[2] == midiS.byte[2]))
                    {
                        mOut->QueueOutput(it_act->out);

                        if (it_act->change_mode && it_act->change_to != -1)
                        {
                            changeMode(it_act);
                        }
                    }
                }
                break;
                }
            }
        }
    }
}

void MIDI::changeMode(std::vector<Actions>::iterator it_act)
{
    int id_dest = it_act->change_to;
    for(vector<ModeType>::iterator m_it = modes.begin();
    m_it!=modes.end();
    m_it++)
    {
        if(m_it->index == id_dest)
        {
            //Current mode must be turned off, in memory, not in file 
            vector<ModeType>::iterator l_it = modes.begin();
            l_it+=id_dest;
            l_it->is_active = false;

            //changed the mode to the newly selected one
            CurrentMode = *m_it;

            //Activete this new one
            processMode(CurrentMode);

            CurrentMode.is_active=true;

        }
    }    

}





void MIDI::Reload(){
    lock_guard<mutex> locker(locking_mechanism);
    mOut->Halt();
    header.clear();
    modes.clear();
    json.Clear();
    json.Reload(jsonFileName,&modes,&header);
    execHeader();
}




