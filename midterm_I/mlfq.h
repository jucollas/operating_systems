#ifndef MLFQ_H
#define MLFQ_H

#include "mlq.h"

class MLFQ : public MLQ {

  public:
    MLFQ();
    int nextTime() override;
    void add(Process& process) override;
};

#endif // MLFQ_H
