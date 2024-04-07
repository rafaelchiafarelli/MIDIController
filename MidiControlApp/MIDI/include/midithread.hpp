/**
 * A device is a set of actions executed during boot-up and a set of actions 
 * that are taken in a by event manner.
 * Device has a personalized thread to be executed continously reading the events
 * from the phisycal device.
 * As the device sends input signals, these becomes actions and responses could
 * could be output to the keyboard or mouse, or midi responses to the sender.
 * 
 * features:
 *  - change mode: When a specific action happens (as defined in the xml). We must change
 *  the current mode (all the actions are descripted by another mode). More than that, 
 *  mode can be changed by increase, decrease or specific.
 *  - delay: a time waited in milliseconds, as described in the xml, for the next output to be executed
 *  - action queue: since delay stop the output of this thread, a queue must be exacted.
 *  - blink: an outputn special type. It will send the midi on and than send the midi off
 */ 

#ifndef MIDITHREAD_HPP
#define MIDITHREAD_HPP

#include "stdio.h"
#include "actions.h"
#include "jsonParser.h"
#include <sstream>
#include <string>

#include <set>
#include <atomic>
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include "midiOutput.hpp"


using namespace std;



class MIDI{

    private:

        std::string jsonFileName;
        mutex locking_mechanism;

        std::vector<Actions> header;
        std::vector<ModeType> modes;
        ModeType CurrentMode;
        jsonParser json;

        unsigned int SelectedModeIndex;

        void changeMode(std::vector<Actions>::iterator it_act);
        void execHeader();


        void processMode(ModeType m);

        void Stop();
        MidiOut* mOut;
    public:
       
        int getCurrentMode() {
            return CurrentMode.index;
        }
        void processInput(midiSignal midiS);
        void Reload();

        MIDI( string xmlFileName);

        ~MIDI();

};


#endif