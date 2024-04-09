#include "midiOutput.hpp"

bool MidiOut::send_midi(unsigned char* send_data, size_t send_data_length) {
    send_data[3] = 0;
    const unsigned char* ch = send_data;
    output->sendMessage(ch, 3);
    return false;

}
struct midiBlinker
{
    midiActions m;/*bliker code (last byte 127 for "ON" and 0 for "OFF")*/
    unsigned int time = 0; /*time in milisseconds that is measured by the delay configured*/
};
void MidiOut::midi_out_thread()
{
    std::vector<midiBlinker> blinkQueue;
    std::vector<midiActions> delayQueue;
    std::cout << "midi_out_thread" << std::endl;
    int debug = 0;
    while (!dead)
    {
        if (q.size() > 0)
        {
            while (q.size()>0)
            {
                devActions out = q.front();
                if (out.tp == midi)
                {
                    if (out.mAct.delay > 0 && out.mAct.midi_mode == midi_normal)
                    {
                        delayQueue.push_back(out.mAct);
                    }
                    else if (out.mAct.midi_mode == midi_blink) 
                    {
                        bool is_there = false;
                        std::vector<midiBlinker>::iterator to_delete;
                        for (auto blinker = blinkQueue.begin();
                            blinker != blinkQueue.end();
                            blinker++)
                        {
                            if (blinker->m.isEqual(out.mAct))
                            {
                                is_there = true;
                                to_delete = blinker; //saves the iterator to remove from the list later.
                                break;
                            }
                        }
                        if (!is_there)
                        {
                            if (out.mAct.delay == 0)
                            {
                                out.mAct.delay = 80;
                            }
                            blinkQueue.push_back({ out.mAct ,out.mAct.delay });
                        }
                        else
                        {
                            to_delete->m.midi.byte[2] = 0;
                            send_midi((unsigned char*)to_delete->m.midi.byte, sizeof(midiSignal));
                            blinkQueue.erase(to_delete);
                        }
                        
                    }
                    else /*output this midi in any other case */
                    {
                        send_midi((unsigned char*)out.mAct.midi.byte, sizeof(midiSignal));
                    }
                }
                q.pop();
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(25));

            if (delayQueue.size() > 0)
            {
                std::vector<std::vector<midiActions>::iterator> it_vec;
                for (auto item = delayQueue.begin();
                    item != delayQueue.end();
                    item++)
                {
                    if (item->delay > 0) {
                        item->delay--;
                    }
                    else
                    {

                        send_midi((*item).midi.byte, sizeof(midiSignal));
                        it_vec.push_back(item);
                    }
                }
                for (auto to_delete = it_vec.begin();
                    to_delete != it_vec.end();
                    to_delete++)
                {
                    delayQueue.erase(*to_delete);
                }
            }

            if (blinkQueue.size() > 0)
            {
                for (auto blinker = blinkQueue.begin();
                    blinker != blinkQueue.end();
                    blinker++)
                {
                    if (blinker->time == blinker->m.delay)
                    {
                        blinker->m.midi.byte[2] = 127;
                        send_midi((unsigned char*)blinker->m.midi.byte, sizeof(midiSignal));
                    }
                    else if(blinker->time == 0)
                    {
                        blinker->m.midi.byte[2] = 0;
                        blinker->time = 2 * blinker->m.delay + 1;
                        send_midi((unsigned char*)blinker->m.midi.byte, sizeof(midiSignal));
                    }
                    blinker->time--;
                }
            }
        }
    }
}