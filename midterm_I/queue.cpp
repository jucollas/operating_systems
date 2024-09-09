#include "queue.h"

Queue::Queue(SchedulerAL& sched, int& time) : scheduler(sched), currentTime(time) {}

void Queue::add(Process& process) {
  processes.push_back(&process);
}

void Queue::nextTime() {
  scheduler.schedule(processes, currentTime);
}

bool Queue::isEmpty() const {
  return processes.empty() && !scheduler.hasProcessExe();
}

Process* Queue::getCurrentProcess() {
  return scheduler.getCurrentProcess();
}

bool Queue::hasProcessExe(){
  return scheduler.hasProcessExe();
}

void Queue::erase(Process* p){
  std::list<Process*>::iterator it = processes.begin();
  while (it != processes.end() && *it != p) ++it;
  if (it != processes.end()) processes.erase(it);
}
