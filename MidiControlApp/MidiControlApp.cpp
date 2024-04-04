// MidiControlApp.cpp: define o ponto de entrada para o aplicativo.
//

#include "MidiControlApp.h"

using namespace std;

int main()
{

	std::vector< raw_midi> hw_ports;
	MIDI first_attempt("C:\\Users\\Usuário\\source\\repos\\MIDIController\\MidiControlApp\\boards\\Dj4Mix.json",hw_ports);
	
	cout << "using mode:" << first_attempt.getCurrentMode() << endl;
	char input;
	std::cin.get(input);
	return 0;
}
