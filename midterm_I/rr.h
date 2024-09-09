#ifndef RR_H
#define RR_H

#include <list>
#include <iostream>

#include "scheduler-al.h"
#include "process.h"

class RR : public SchedulerAL {
  private:
    int quantum;           
    int currentQuantum;

  public:
    RR(int quantum);
    void schedule(std::list<Process*>& processes, int& currentTime) override;
};

#endif // RR_H
