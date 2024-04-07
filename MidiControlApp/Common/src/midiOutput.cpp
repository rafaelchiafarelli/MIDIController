#include "midiOutput.hpp"

bool MidiOut::send_midi(unsigned char* send_data, size_t send_data_length) {
    send_data[3] = 0;
    const unsigned char* ch = send_data;
    output->sendMessage(ch, 3);
    return false;

}

void MidiOut::midi_out_thread()
{
    std::vector<std::vector<devActions>> currentActions;
    while (!dead)
    {
        /*
        if (send)
        {


            currentActions.push_back(oQueue.front());
            oQueue.pop();
            for (std::vector<std::vector<devActions>>::iterator to_send = currentActions.begin();
                to_send != currentActions.end();
                to_send++)
            {
                for (std::vector<devActions>::iterator out = (*to_send).begin();
                    out != (*to_send).end();
                    out++)
                {
                    switch (out->tp)
                    {
                    case keyboard:
                        out->kData.spot = out->spot;
                        std::cout << "keyboard out:" << out->kData;
                        keyboard_send(out->kData);
                        if (out->kData.delay > 0)
                        {
                            out->state = delaing;
                        }
                        else
                        {
                            out->state = done;
                        }
                        break;
                    case midi:
                        send_midi((char*)out->mAct.midi.byte, sizeof(midiSignal));
                        if (out->mAct.delay != 0)
                            std::this_thread::sleep_for(std::chrono::milliseconds(out->kData.delay));
                        break;
                    case mouse:
                        send_mouse(out->mouse);
                        break;
                    case joystick:
                        send_joystick();
                        break;
                    default:
                        break;
                    }
                }
            }
            if (oQueue.empty())
            {
                send = false;
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        */
    }
}