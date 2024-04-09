#include "VirtualKeySender.hpp"

// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.
#define WINVER 0x0500
#include <windows.h>

int VirtualKeySender::test()
{
    // This structure will be used to create the keyboard
    // input event.
    INPUT ip;


    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));


    // IMPORTANT: Current keyboard layout 0xf0010413 (Netherland with USA kbd)!!!!!!!
    WORD vkCode = 0x36; // '6'
    INPUT keyEvent = { 0 };
    keyEvent.type = INPUT_KEYBOARD;
    keyEvent.ki.wVk = vkCode;
    keyEvent.ki.wScan = MapVirtualKeyEx(vkCode, 0, (HKL)0xf0010413);
//    SendInput(1, &amp; keyEvent, sizeof(keyEvent));

    // Exit normally
    return 0;
}