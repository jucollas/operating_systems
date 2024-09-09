#ifndef QUEUE_H
#define QUEUE_H

#include <list>
#include <iostream>

#include "process.h"
#include "scheduler-al.h"

class Queue {
  private:
    SchedulerAL& scheduler;  
    int& currentTime;        
    std::list<Process*> processes;

  public:
    Queue(SchedulerAL& scheduler, int& currentTime);
    
    void add(Process& process);    
    void nextTime();              
    bool isEmpty() const;               
    Process* getCurrentProcess();
    bool hasProcessExe();
    void erase(Process* p);
};

#endif // QUEUE_H
