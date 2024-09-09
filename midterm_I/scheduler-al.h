#ifndef SCHEDULER_AL_H
#define SCHEDULER_AL_H

#include <list>

#include "process.h"

class SchedulerAL{
  protected:
    Process* current;
    bool hasProcess;

  public:
    SchedulerAL();
    ~SchedulerAL() = default;
    Process* getCurrentProcess();
    bool hasProcessExe();

    virtual void schedule(std::list<Process*>&, int&) = 0;
};


#endif