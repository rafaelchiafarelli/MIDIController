// MidiControlApp.cpp: define o ponto de entrada para o aplicativo.
//

#include "MidiControlApp.h"
using namespace std;

int main()
{

	MIDI midiDevice("C:\\Users\\Usuário\\source\\repos\\MIDIController\\MidiControlApp\\boards\\Dj4Mix.json");

	cout << "using mode:" << midiDevice.getCurrentMode() << endl;
	char input;
	std::cin.get(input);
	return 0;
}
