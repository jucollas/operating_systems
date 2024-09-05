#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "control-unit.h"
#include <vector>
#include <string>

class Processor {
    RegisterFile regFile;
    Memory memory;
    ALU alu;
    SR icr;
    SR mdr;
    AR mar;
    AR pc;
    AR acc;

    ControlUnit controlUnit;
    
public:
    Processor(int textSize, int dataSize);
    void loadProgram(const std::vector<std::string>& program);
    void execute();
};

#endif // PROCESSOR_H
