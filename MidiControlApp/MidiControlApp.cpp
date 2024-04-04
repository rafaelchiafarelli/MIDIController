// MidiControlApp.cpp: define o ponto de entrada para o aplicativo.
//

#include "MidiControlApp.h"

#include "Windows.h"
using namespace std;
void ShowDesktop();
//**********************************************************************
//
// Sends Win + D to toggle to the desktop
//
//**********************************************************************
void ShowDesktop()
{
    cout<<"Sending 'Win-D'\r\n";
    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'D';

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 'D';
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    if (uSent != ARRAYSIZE(inputs))
    {
        cout<<"SendInput failed: 0x%x\n"<<"\r\n";
    }
}
int main()
{

	std::vector< raw_midi> hw_ports;
	MIDI first_attempt("C:\\Users\\Usuário\\source\\repos\\MIDIController\\MidiControlApp\\boards\\Dj4Mix.json",hw_ports);
    ShowDesktop();
	cout << "using mode:" << first_attempt.getCurrentMode() << endl;
	char input;
	std::cin.get(input);
	return 0;
}
