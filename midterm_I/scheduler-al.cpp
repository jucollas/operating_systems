#include "scheduler-al.h"

SchedulerAL::SchedulerAL() : hasProcess(false), current(nullptr) {}

Process* SchedulerAL::getCurrentProcess() {
  return current;
}

bool SchedulerAL::hasProcessExe(){
  return hasProcess;
}