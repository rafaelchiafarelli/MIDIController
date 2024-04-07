#pragma once

#include "genOutput.hpp"
#include "actions.h"
#include "iostream"
#include "queue"
#include "mutex"
#include <RtMidi.h>

#include <thread>



class MidiOut : public GenOutput {

private:
    bool dead = false;
	std::queue<devActions> q;
	std::mutex lock;
	RtMidiIn* input;
	RtMidiOut* output;
    void midi_out_thread();
	
public:
    bool send_midi(unsigned char* send_data, size_t send_data_length);
	void QueueOutput(std::vector<devActions> devAct)
	{
		std::lock_guard<std::mutex> locker(lock);
        for (std::vector<devActions>::iterator it = devAct.begin();
            it != devAct.end();
            it++)
        {
            q.push(*it);
        }
	};
	void start() {};
	void stop() {};
    void Halt() { 
        std::lock_guard<std::mutex> locker(lock);
        /*figure out a way to halt the system*/
    }
	MidiOut(std::string devNameIn, std::string devNameOut, callBackType cbk, void *ref)
	{

        /* MIDI hw stuff */
        std::vector< RtMidi::Api > apis;
        RtMidi::getCompiledApi(apis);

        if (apis.size() < 1)
        {
            std::cout << "MAJOR ERROR - API NOT COMPILED PROPERLY" << std::endl;
            return;
        }

        std::cout << "\nAPIs\n  API #0: unspecified / default\n";
        std::string input_name, output_name;
        int dev_index = -1, dev_index_out = -1;
        RtMidi::Api api = RtMidi::Api::WINDOWS_MM;
        for (size_t n = 0; n < apis.size(); n++)
        {
            std::string tmp = RtMidi::getApiDisplayName(apis[n]);
            std::cout << "  API #" << apis[n] << ": " << tmp << "\n";
            if (!devNameIn.compare(tmp)) {
                api = static_cast<RtMidi::Api>(n);
            }
        }
        input = new RtMidiIn(api);
        output = new RtMidiOut(api);

        unsigned int i = 0, nPorts = input->getPortCount();
        unsigned int nOutPorts = output->getPortCount();

        if (nPorts == 0 || nOutPorts == 0) {
            std::cout << "MAJOR ERROR No input ports available!" << std::endl;
            return;
        }

        if (nPorts == 1) {
            std::cout << "\nOpening Input " << input->getPortName() << std::endl;
            dev_index = 0;

        }
        else {
            for (i = 0; i < nPorts; i++) {
                std::string tmp = input->getPortName(i);

                std::cout << " Input Port #" << i << "input: " << tmp << '\n';
                if (!tmp.compare(devNameOut))
                {
                    input_name = tmp;
                    dev_index = i;
                }

            }
        }

        if (nOutPorts == 1) {
            std::cout << "\nOpening Output " << output->getPortName() << std::endl;
            dev_index_out = 0;
        }
        else {
            for (i = 0; i < nOutPorts; i++) {

                std::string outTmp = output->getPortName(i);
                std::cout << " comparing Output Port #" << i << " with:" << devNameOut << "output:" << outTmp << "." << '\n';

                if (!outTmp.compare(devNameOut))
                {
                    std::cout << " Output Port Selected #" << i << "output:" << outTmp << "." << '\n';
                    output_name = outTmp;
                    dev_index_out = i;
                }
            }
        }


        input->openPort(dev_index);
        output->openPort(dev_index_out);

        input->setCallback(cbk, ref);
        // Don't ignore sysex, timing, or active sensing messages.
        input->ignoreTypes(false, false, false);

	}
};


