#pragma once
#include "iostream"
#include "stdlib.h"
#include "genOutput.hpp"
#include "queue"
#include "mutex"
#include "SendKeys.h"
#include <thread>
#include "VirtualKeySender.hpp"

class KeyboardOut : public GenOutput {
private:
	bool dead = false;
	std::queue<devActions> q;
	std::mutex lock;
	void keyboard_out_thread();
	void send_one_key();
	void send_text();
	void send_hot_key();
	std::thread t1;
	CSendKeys sk;
public:
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
	KeyboardOut() {

		t1 = std::thread(&KeyboardOut::keyboard_out_thread, this);
	}
};

