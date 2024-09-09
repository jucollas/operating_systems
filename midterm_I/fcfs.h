#ifndef FCFS_H
#define FCFS_H

#include <list>

#include "scheduler-al.h"

class FCFS : public SchedulerAL {
  public:
    FCFS();
    void schedule(std::list<Process*>& processes, int& currentTime) override;
};

#endif // FCFS_H
