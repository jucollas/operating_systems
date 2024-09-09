#include "mlq.h"

MLQ::MLQ()
  : currentTime(0), rr1(4), rr2(8), fcfs() {
  q.emplace_back(Queue(rr1, currentTime)); // Level 1, quantum = 4
  q.emplace_back(Queue(rr2, currentTime)); // Level 2, quantum = 8
  q.emplace_back(Queue(fcfs, currentTime)); // Level 3, FCFS
}

void MLQ::add(Process& process) {
  int priority = process.getPriority();
  if (priority == 1) {
    q[0].add(process); // Level 1
  } else if (priority == 2) {
    q[1].add(process); // Level 2
  } else {
    q[2].add(process); // Level 3
  }
}

int MLQ::nextTime() {
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
      flag = false;
    }
    i++;
  }
  if(flag) currentTime++;
  return currentTime;
}

bool MLQ::isEmpty() const {
  bool ans = true;
  int i = 0;
  while(i < q.size() && ans){
    if(!q[i++].isEmpty())
      ans = false;
  }
  return ans;
}

std::vector<std::pair<int, int>> MLQ::getReport() const {
  return executionLog;
}

void MLQ::start(){
  currentTime = 0;
}
