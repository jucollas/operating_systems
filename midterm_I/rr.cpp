#include "rr.h"

RR::RR(int quantum) : quantum(quantum), currentQuantum(0) {}

void RR::schedule(std::list<Process*>& processes, int& currentTime) {
	if (processes.empty() && !hasProcess) return;

	if(!hasProcess){
		current = processes.front();
		processes.pop_front();
		currentQuantum = 0;
		hasProcess = true;
	}

	current->runFor(1, currentTime);
	currentQuantum++;

	if (!current->getBurstTime() || currentQuantum >= quantum){
		if (current->getBurstTime() > 0)
			processes.push_back(current);
		hasProcess = false;
		currentQuantum = 0;
	}
}


/*void RR::schedule(std::list<Process*>& processes, int& currentTime) {
	if (processes.empty() && !hasProcess) return;

	if (!hasProcess || currentQuantum >= quantum) {
		if (hasProcess && current->getBurstTime() > 0)
			processes.push_back(current);

		current = processes.front();
		processes.pop_front();
		currentQuantum = 0;
		hasProcess = true;
	}

	current->runFor(1, currentTime);
	currentQuantum++;

	if (current->getBurstTime() == 0) {
		hasProcess = false;
		currentQuantum = 0;
	}
}*/
