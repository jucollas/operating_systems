#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "process.h"
#include "mlq.h"
#include "mlfq.h"
#include "simulation.h"

std::vector<Process> loadProcessesFromFile(const std::string& filename) {
    std::vector<Process> processes;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return processes;
    }

    while (std::getline(file, line)) {
        int id, arrivalTime, burstTime, priority;
        char delimiter;
        std::stringstream ss(line);
        
        ss >> id >> delimiter >> arrivalTime >> delimiter >> burstTime >> delimiter >> priority;

        Process p(id, arrivalTime, burstTime, priority);
        processes.push_back(p);
    }

    file.close();
    return processes;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <process_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<Process> processes = loadProcessesFromFile(filename);
    std::vector<Process> processes2 = processes;


    std::cout << "### Simulation MLQ ###" << std::endl;
    MLQ mlq;
    Simulation simulation(processes, mlq);
    simulation.execute();
    simulation.report();

    std::cout << "### Simulation MLFQ ###" << std::endl;
    MLFQ mlfq;
    Simulation simulation2(processes2, mlfq);
    simulation2.execute();
    simulation2.report();

    return 0;
}
