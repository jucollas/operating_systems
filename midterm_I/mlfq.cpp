#include "mlfq.h"

MLFQ::MLFQ(){}

int MLFQ::nextTime(){
  int i = 0, tmp;
  bool flag = true;
  Process* current;
  while (i < q.size() && flag) {
    if (!q[i].isEmpty()) {
      tmp = currentTime;
      q[i].nextTime();
      current = q[i].getCurrentProcess();
      if(executionLog.empty() || executionLog[executionLog.size() - 1].first != current->getPID())
        executionLog.push_back({current->getPID(), tmp});

      if(!q[i].hasProcessExe() && current->getBurstTime() > 0){
        q[i].erase(current);
        current->setPriority(current->getPriority() + 1);
        this->add(*current);
      }

      flag = false;
    }
    i++;
  }
  if(flag) currentTime++;
  return currentTime;
}