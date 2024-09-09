#include "fcfs.h"
#include <algorithm>

FCFS::FCFS(){}

void FCFS::schedule(std::list<Process*>& processes, int& currentTime) {
	if (!hasProcess && !processes.empty()) {
		auto it = std::min_element(
			processes.begin(), processes.end(),
			[](const Process* a, const Process* b) {
				return a->getArrivalTime() < b->getArrivalTime();
			}
		);
		current = *it;
		processes.erase(it);
		hasProcess = true;
	}

	if (hasProcess) {
		current->runFor(current->getBurstTime(), currentTime);
		hasProcess = false;
	}
}

