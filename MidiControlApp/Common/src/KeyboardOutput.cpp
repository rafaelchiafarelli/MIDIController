#include "KeyboardOutput.hpp"

void KeyboardOut::keyboard_out_thread()
{
    std::cout << "keyboard_out_thread" << std::endl;
    int debug = 0;
    while (!dead)
    {
        if (q.size() > 0)
        {
            while (q.size() > 0)
            {
                devActions out(q.front());

                if (out.tp == keyboard)
                {
                    // Send "Hello world!"
                    switch (out.kData.type) {
                    case oneKey:
                    {
                        char c = *out.kData.data.c_str();
                        sk.SendOneKey(c);
                    }
                        break;
                    case hotkey:
                        sk.SendKeys(out.kData.data.c_str());
                        break;
                    case text:
                        sk.SendString(out.kData.data);
                        break;
                    }   
                }
                q.pop();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void KeyboardOut::send_one_key()
{

}
void KeyboardOut::send_text()
{

}
void KeyboardOut::send_hot_key()
{

}