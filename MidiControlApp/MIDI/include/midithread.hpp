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
#include <RtMidi.h>
#include "aconfig.h"
#include <thread>
#include <set>
#include <atomic>
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <oActions.hpp>


using namespace std;
#define PORT_NAME_SIZE 10
#define MILLISECONDS_TIMEOUT 10

class raw_midi{
    public:
        string port;
        string devName;
        string sub_name;
        string name;
        int sub;
        int card;
        int device;
    friend std::ostream& operator<<(std::ostream &os, const raw_midi &dt){
        os<<"port:"<<dt.port<<" devName:"<<dt.devName<<" sub_name:"<<dt.sub_name<<" name:"<<dt.name;
        return os;
    };
};

class MIDI : private oActions{

    private:

        std::string jsonFileName;

        mutex locking_mechanism;
        mutex midi_out_mutex;
        std::thread *in_thread;
        std::thread *out_thread;
        std::thread *thcoms;
;
        
        
        std::queue<std::vector<devActions> > oQueue;
        void in_func(); //midi input handler
        void out_func(); //keyboard and mouse handler
        bool outToFile;
        std::string outFileName;
        ofstream outFileStream;

        atomic_bool send;
        atomic_bool stop;
        int timeout;

        std::vector<Actions> header;
        std::vector<ModeType> modes;
        ModeType CurrentMode;
        jsonParser json;

        unsigned int SelectedMode;

        RtMidiIn *input;

        char port_name[PORT_NAME_SIZE];
        void saveJSON();
        void changeMode(std::vector<Actions>::iterator it_act);
        void execHeader();
        void parse();

        void processMode(ModeType m);
        void send_midi(char *send_data, size_t send_data_length);
        void send_mouse(mouseActions mouse);
        void send_joystick(){};
        void startup();

        std::vector<std::string> explode(std::string const & s, char delim);
        void Stop();
        void outStop();
        bool outFile(string name);
        void oMouse(mouseActions) {};
        void oJoystick(joystickActions) {};
        void oKeyboard(keyboardActions) {};

        void coms_handler();

    public:
        RtMidiOut* output;
        int getCurrentMode() {
            return CurrentMode.index;
        }
        void processInput(midiSignal midiS);
        void Reload();

        MIDI( string xmlFileName, vector<raw_midi> hw_ports);
        ~MIDI();

};


#endif