#include "simulation.h"

Simulation::Simulation(std::vector<Process>& p, MLQ_ABS& m) : p(p), m(m){}

void Simulation::execute() {
  std::sort(p.begin(), p.end(), [](const Process& a, const Process& b) {
    return a.getArrivalTime() < b.getArrivalTime();
  });
    
  m.start();
  time = 0;
  size_t i = 0;
  while (i < p.size() || !m.isEmpty()) {
    while (i < p.size() && p[i].getArrivalTime() <= time)
      m.add(p[i++]);
    time = m.nextTime();
  }
}

void printLine(){
  for(int i = 0; i < 49; ++i) {
    if(i % 6 == 0)
      printf("+");
    else
      printf("-");
  }
  printf("\n");
}

void Simulation::displayTable(std::vector<Process>& p){
  int TP = p.size();
  float ST = 0, FT = 0, WT = 0, TAT = 0;
  printf("### Table ###\n");
  printf("| %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s |\n",
    "PID", "AT","BT","P", 
    "ST" , "FT", "WT", 
    "TAT");
  printLine();
  for (const auto& process : p) {
    printf("| P%-2d | %3d | %3d | %3d | %3d | %3d | %3d | %3d |\n",
      process.getPID(),
      process.getArrivalTime(),
      process.getBurstTimeInit(),
      process.getPriority(),
      process.getStartTime(),
      process.getFinishTime(),
      process.getWaitingTime(),
      process.getTurnaroundTime()
    );
    ST += process.getStartTime();
    FT += process.getFinishTime();
    WT += process.getWaitingTime();
    TAT += process.getTurnaroundTime();
  }
  ST /= TP;
  FT /= TP;
  WT /= TP;
  TAT /= TP;
  printf("Prom: ST : %.2f, FT : %.2f, WT : %.2f, TAT : %.2f\n\n", ST, FT, WT, TAT);
}

void Simulation::displayExecutionOrder(std::vector<std::pair<int, int>> report){
  std::cout << "### Execution Order ###\n";
  
  for (const auto& entry : report) {
    std::cout << "Process " << entry.first << " executed in time " << entry.second << ".\n";
  }
  std::cout << std::endl; 
}

void Simulation::displayGrafix(std::vector<std::pair<int, int>> report){
  int i, j, aux;

  printf("### Grafix ###\n");

  printf("0");
  for(i = 1; i <= time; ++i)
    printf("%6d", i);
  printf("\n");

  printf("|");
  for(i = 0; i < time; ++i)
    printf("-----|");
  printf("\n");
  
  j = 0, aux = -1;
  printf("|");
  for(i = 0; i < time; ++i){
    if(j < report.size() && report[j].second == i)
      aux = report[j++].first;
    if(aux == -1) printf(" NLL |");
    else printf(" P%-2d |", aux);
  }
  printf("\n");
  
  printf("|");
  for(i = 0; i < time; ++i)
    printf("-----|");
  printf("\n\n");
}

void Simulation::report() {
  std::vector<std::pair<int, int>> report = m.getReport();
  displayTable(p);
  displayExecutionOrder(report);
  displayGrafix(report);
}
