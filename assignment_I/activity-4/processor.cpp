#include "processor.h"
#include <iostream>

Processor::Processor(int textSize, int dataSize)
    : memory(textSize, dataSize), controlUnit(regFile, memory, alu, icr, mdr, mar, pc, acc) {}

void Processor::loadProgram(const std::vector<std::string>& program) {
    controlUnit.loadProgram(program);
}

void Processor::execute() {
  pc.set(0);
  while (true) {
    // Execute the next instruction
    controlUnit.executeNextInstruction();
    
    // Check if the instruction was END and break the loop if true
    std::string currentInstruction = icr.get();
    if (currentInstruction.substr(0, 3) == "END") {
      std::cout << "Execution finished." << std::endl;
      break;
    }
  }
}
