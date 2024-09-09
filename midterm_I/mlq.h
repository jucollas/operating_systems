#ifndef MLQ_H
#define MLQ_H

#include <vector>
#include <iostream>

#include "queue.h"
#include "process.h"
#include "scheduler-al.h"
#include "mlq-abstract.h"
#include "rr.h"
#include "fcfs.h"

class MLQ : public MLQ_ABS {
  protected:
    std::vector<Queue> q;
    std::vector<std::pair<int, int>> executionLog;
    int currentTime;
    RR rr1;
    RR rr2;
    FCFS fcfs;

  public:
    MLQ();

    void add(Process& process) override;
    int nextTime() override;
    bool isEmpty() const override;
    std::vector<std::pair<int, int>> getReport() const override;
    void start() override;
};

#endif // MLQ_H
