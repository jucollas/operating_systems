#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

#include "mlq-abstract.h"
#include "process.h"

class Simulation {
  private:
    std::vector<Process>& p;
    MLQ_ABS& m;
    int time;

    void displayTable(std::vector<Process>& p);
    void displayExecutionOrder(std::vector<std::pair<int, int>> report);
    void displayGrafix(std::vector<std::pair<int, int>> report);
  public:
    Simulation(std::vector<Process>& p, MLQ_ABS& m);
    void execute();
    void report();
};

#endif // SIMULATION_H
