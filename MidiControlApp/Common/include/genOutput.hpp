#pragma once

#include "iostream"
#include "actions.h"

typedef void (*callBackType)(double timeStamp, std::vector<unsigned char>* message, void* userData);

class GenOutput {

public:
	GenOutput() {};
	virtual void QueueOutput(devActions) {};
	virtual void start() {};
	virtual void stop() {};

};
