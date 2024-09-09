#ifndef PROCESS_H
#define PROCESS_H

class Process {
  private:
    int PID;            // Identificador del proceso
    int arrivalTime;    // Tiempo de llegada
    int burstTime;      // Tiempo de ejecución restante
    int burstTimeInit;  // Tiempo de ejecuccion total
    int priority;       // Prioridad (solo para MLQ)
    int startTime;      // Tiempo de inicio de ejecución
    int finishTime;     // Tiempo de finalización
    int waitingTime;    // Tiempo de espera
    int turnaroundTime; // Tiempo de retorno
    bool started;       // Indica si el proceso ha comenzado a ejecutarse

  public:
    // Constructor
    Process(int pid, int at, int bt, int pr);
    Process();

    // Métodos Getters
    int getPID() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    int getStartTime() const;
    int getFinishTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getBurstTimeInit() const;

    // Métodos Setters
    void setArrivalTime(int at);
    void setBurstTime(int bt);
    void setPriority(int pr);
    void setStartTime(int st);
    void setFinishTime(int ft);
    void setWaitingTime(int wt);
    void setTurnaroundTime(int tt);

    // Otros métodos
    void calculateWaitingTime(int currentTime);
    void calculateTurnaroundTime();
    
    // Método para ejecutar el proceso
    void runFor(int timeToRun, int& currentTime);
};

#endif // PROCESS_H
