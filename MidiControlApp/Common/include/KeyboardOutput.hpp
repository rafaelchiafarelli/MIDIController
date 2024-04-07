#pragma once

#include "genOutput.hpp"
#include "queue"
#include "mutex"


class KeyboardOut : public GenOutput {
private:
	std::queue<devActions> q;
	std::mutex lock;

public:
	void QueueOutput(devActions devAct)
	{
		std::lock_guard<std::mutex> locker(lock);
		q.push(devAct);
	};
	void start() {};
	void stop() {};
};

