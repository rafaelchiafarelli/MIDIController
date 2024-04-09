#ifndef ACTIONS_H
#define ACTIONS_H
#include "string"
#include <iostream>
#include <sstream>

#include <ostream>
#include <vector>
#include <set>
#include "keyNumber.hpp"
#include <chrono>
/**
 * 
 */ 
typedef enum{
    oneKey,
    hotkey,
    text
}keyType;

/**
 * 
 */
typedef enum{
    hold,
    not_hold,
    hold_delay
}holdType;

/**
 * 
 */
typedef enum{
    notype,
    midi,
    keyboard,
    mouse,
    joystick
}devType;

devType GetDevType(std::string dType);
/**
 * 
 * 
 */
typedef union {
    unsigned char byte[4];
    uint32_t asInt;
}midiSignal;

typedef enum
{
    midi_normal = 0,
    midi_trigger_higher = 1,
    midi_trigger_lower = 2,
    midi_spot = 3,
    midi_blink = 4,
    midi_nomode = 5

}midi_action_mode;

class midiActions{
    public:
    midi_action_mode midi_mode = midi_normal;
    midiSignal midi = { 0 };
    unsigned long int delay = 0;
    std::string str(){
        char c_str[14];
        std::sprintf(c_str,"%d %d %d",midi.byte[0],midi.byte[1],midi.byte[2]);
        return std::string(c_str);
    };
    std::string ar_str(){
        char c_str[14];
        std::sprintf(c_str,"[%d,%d,%d]",midi.byte[0],midi.byte[1],midi.byte[2]);
        return std::string(c_str);
    };
    midiActions(){};
    ~midiActions(){};
    friend std::ostream& operator<<(std::ostream &os, const midiActions &dt){
        os<<std::hex<<(unsigned int)dt.midi.byte[0]<<" "<<std::hex<<(unsigned int)dt.midi.byte[1]<<" "<<std::hex<<(unsigned int)dt.midi.byte[2];
        return os;
    };
    friend std::stringstream& operator<<(std::stringstream &os, const midiActions &dt){
        os<<std::hex<<(unsigned int)dt.midi.byte[0]<<" "<<std::hex<<(unsigned int)dt.midi.byte[1]<<" "<<std::hex<<(unsigned int)dt.midi.byte[2];
        return os;
    };
    midiActions& operator=(const midiActions& t) {
        this->midi_mode = t.midi_mode;
        this->midi = t.midi;
        this->delay = t.delay;
        return *this;
    }
    bool isEqual(const midiActions& t) {
        if (((midi_action_mode)this->midi_mode == (midi_action_mode)t.midi_mode) && (this->midi.asInt == t.midi.asInt))
        {
            return true;
        }
        return false;
    }

};

/**
 * 
 * 
 */ 
class joystickActions{
    private:
    public:
    joystickActions(){};
    ~joystickActions(){};
    friend std::ostream& operator<<(std::ostream &os, const joystickActions &dt){
        os<<"no joystickActions yet";
        return os;
    };
    joystickActions& operator=(const joystickActions& t)
    {
        return *this;
    }

};

/**
 * 
 * 
 */ 
class keyboardActions{
    public:
        keyType type = oneKey;
        std::string data = "";
        holdType hold = not_hold;
        int spot = -1;
        unsigned int delay = 0;
        keyboardActions(){};
        ~keyboardActions(){};
        friend std::ostream& operator<<(std::ostream &os, const keyboardActions &dt){
            os<<"type:"<<dt.type<<" data:"<<dt.data<<" delay:"<<dt.delay;
            return os;
        };
        keyboardActions& operator=(const keyboardActions& t)
        {
            this->type = t.type;
            this->data = t.data;
            this->hold = t.hold;
            this->spot = t.spot;
            this->delay = t.delay;
            return *this;
        }

};
/**
 * 
 * 
 * 
 */ 
class mouseActions{
    public:
        long dx = 0;
        long gotox = 0;
        long dy = 0;
        long gotoy = 0;
        unsigned int wheel_move = 0;
        bool click = 0;
        bool right_click = 0;
        unsigned long int delay = 0;
        mouseActions(){};
        ~mouseActions(){};
    friend std::ostream& operator<<(std::ostream &os, const mouseActions &dt){
        os<<"dx:"<<dt.dx<<" dy:"<<dt.dy<<" gotox:"<<dt.gotox<<" gotoy:"<<dt.gotoy<<" whm:"<<dt.wheel_move<<" click:"<<dt.click<<" rclick"<<dt.right_click;
        return os;
    };
    mouseActions& operator=(const mouseActions& t)
    {
        this->dx = t.dx;
        this->gotox = t.gotox;
        this->gotoy = t.gotoy;
        this->dy = t.dy;
        this->wheel_move = t.wheel_move;
        this->click = t.click;
        this->right_click = t.right_click;
        this->delay = t.delay;
        return *this;
    }
};
/*
Represents the state of the output. Only when the output gets to "done" is when we can remove from the queue.
*/
typedef enum {
    not_done,
    done,
    delaing,
    doing
}outputState;
/**
 * 
 * 
 */ 
class devActions{
    private: 
        int index = -1;
    public:
        int spot=-1;

        outputState state;

        devType tp; /* type of the output, either keyboard or mouse ou a midi response*/

        //keyboard
        keyboardActions kData; /* data to be sent to the output*/

        joystickActions joy;
        //mouse
        mouseActions mouse;

        //midi
        midiActions mAct;

        devActions& operator=(const devActions& t)
        {
            this->spot = t.spot;
            this->state = t.state;
            this->tp = t.tp;
            switch (this->tp)
            {
            case devType::keyboard:
                this->kData = t.kData;
                break;
            case devType::joystick:
                this->joy = t.joy;
                break;
            case devType::midi:
                this->mAct = t.mAct;
                break;
            case devType::mouse:
                this->mouse = t.mouse;
                break;
            }
            return *this;
        }

        devActions(){
            index = 0;
            tp = devType::notype;
            state = not_done;
        };
        devActions(unsigned char b0, unsigned char b1, unsigned char b2){
            index = ((unsigned int)b2)<<16 + ((unsigned int)b1)<<8 + b0;
            mAct.midi.asInt = index;
            tp = devType::midi;
            state = not_done;
        };

        devActions(std::string kD, keyType ktp){
            kData.data = kD;
            kData.type= ktp;
            tp = devType::keyboard;
            state = not_done;
        };
        devActions( unsigned long int dx,
                    unsigned long int gotox,
                    unsigned long int dy,
                    unsigned long int gotoy,
                    unsigned int wheel_move,
                    bool click,
                    bool right_click){
            mouse.dx = dx;
            mouse.gotox = gotox,
            mouse.dy = dy;
            mouse.gotoy = gotoy;
            mouse.wheel_move = wheel_move;
            mouse.click = click;
            mouse.right_click = right_click;
            tp = devType::mouse;
            state = not_done;
        };
        unsigned int GetIndex(){return index;}
        void SetIndex(int idx){index = idx;}

        friend std::ostream& operator<<(std::ostream &os, const devActions &devAct){
            switch(devAct.tp)
            {
                case devType::keyboard:
                os<<"keyboard: "<<devAct.kData;
                break;
                case devType::joystick:
                os<<"joystick: "<<devAct.joy;
                break;
                case devType::midi:
                os<<"midi: "<<devAct.mAct;
                break;
                case devType::mouse:
                os<<"mouse: "<<devAct.mouse;
                break;
            }
        return os;
        };
};
/**
 * 
 * 
 */ 
class Actions{

public:
    bool change_mode = false;
    int change_to = -1;
    devActions in;
    std::vector<devActions> out;
    void clear(){
        out.clear();
        in = devActions();
    }
    Actions(){};
    ~Actions(){};
    bool operator > (const Actions &rhs) const {return in.mAct.midi.asInt>rhs.in.mAct.midi.asInt;}

    Actions& operator=(const Actions& t)
    {
        this->change_mode = t.change_mode;
        this->change_to = t.change_to;
        this->in = t.in;
        for (auto it = t.out.begin();
            it != t.out.end();
            it++)
        {
            devActions o = *it;
            this->out.push_back(o);
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Actions& Act) {
        os << "change_mode:" << Act.change_mode << " change_to:" << Act.change_to << " input:" << Act.in << " out:";
        
        for (auto it = Act.out.begin();
            it != Act.out.end();
            it++)
        {
            os << *it;
        }
        os << std::endl;
        return os;
    };
};

#endif
