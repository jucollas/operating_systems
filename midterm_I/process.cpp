#include "process.h"
#include <iostream>

// Constructors
Process::Process(int pid, int at, int bt, int pr)
  : PID(pid), arrivalTime(at), burstTime(bt), priority(pr),
    startTime(-1), finishTime(-1), waitingTime(0), turnaroundTime(0), started(false), burstTimeInit(bt) {}

Process::Process()
  : PID(-1), arrivalTime(-1), burstTime(-1), priority(-1),
    startTime(-1), finishTime(-1), waitingTime(0), turnaroundTime(0), started(false), burstTimeInit(-1) {}

// Getters
int Process::getPID() const { return PID; }
int Process::getArrivalTime() const { return arrivalTime; }
int Process::getBurstTime() const { return burstTime; }
int Process::getPriority() const { return priority; }
int Process::getStartTime() const { return startTime; }
int Process::getFinishTime() const { return finishTime; }
int Process::getWaitingTime() const { return waitingTime; }
int Process::getTurnaroundTime() const { return turnaroundTime; }
int Process::getBurstTimeInit() const {return burstTimeInit; }

// Setters
void Process::setArrivalTime(int at) { arrivalTime = at; }
void Process::setBurstTime(int bt) { burstTime = bt; }
void Process::setPriority(int pr) { priority = pr; }
void Process::setStartTime(int st) { startTime = st; }
void Process::setFinishTime(int ft) { finishTime = ft; }
void Process::setWaitingTime(int wt) { waitingTime = wt; }
void Process::setTurnaroundTime(int tt) { turnaroundTime = tt; }

void Process::runFor(int timeToRun, int& currentTime) {
    if (!started) {
        startTime = currentTime;
        started = true;
    }

    burstTime -= timeToRun;

    if (burstTime <= 0) {
        finishTime = currentTime + timeToRun;
        calculateWaitingTime(currentTime + timeToRun);
        calculateTurnaroundTime();
    }
    currentTime += timeToRun;
}

void Process::calculateWaitingTime(int currentTime) {
    waitingTime = finishTime - arrivalTime - burstTimeInit;
}

void Process::calculateTurnaroundTime() {
    turnaroundTime = finishTime - arrivalTime;
}
