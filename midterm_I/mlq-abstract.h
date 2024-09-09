#ifndef MLQ_ABS_H
#define MLQ_ABS_H

#include <vector>
#include "process.h"

class MLQ_ABS {
  public:
    virtual void start() = 0;
    virtual void add(Process& process) = 0;
    virtual int nextTime() = 0;
    virtual bool isEmpty() const = 0;
    virtual std::vector<std::pair<int, int>> getReport() const = 0;
    virtual ~MLQ_ABS() = default;
};

#endif // MLQ_ABS_H
