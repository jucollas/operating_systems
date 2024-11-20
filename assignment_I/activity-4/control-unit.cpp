#include "control-unit.h"
#include <iostream>
#include <sstream>

ControlUnit::ControlUnit(RegisterFile& rf, Memory& mem, ALU& a, SR& i, SR& m, AR& mar, AR& pc, AR& acc)
  : regFile(rf), memory(mem), alu(a), icr(i), mdr(m), mar(mar), pause(false), UC(""), pc(pc), acc(acc){}

void ControlUnit::loadProgram(const std::vector<std::string>& program) {
  for (int i = 0; i < program.size(); ++i) {
    memory.writeInstruction(i, program[i]);
  }
}

void ControlUnit::fech(){
  if (!pause){
    mar.set(pc.get());
    mdr.set(memory.readInstruction(mar.get()));
    icr.set(mdr.get());
    UC = icr.get();
  }
  pc.set(pc.get() + 1);
}

void ControlUnit::writeback(){
  memory.writeData(mar.get(), std::stoi(mdr.get()));
}

void ControlUnit::mem(std::string& d1, std::string& d2){
  mdr.set(d2);
  mar.set(regFile.get(d1));
  writeback();
}

void ControlUnit::load(std::string d1){
  mar.set(regFile.get(d1));
  acc.set(memory.readData(mar.get()));
  mdr.set(std::to_string(acc.get()));
}

void ControlUnit::addition(std::string d1, std::string d2, std::string d3){
  mar.set(regFile.get(d1));
  int value1 = memory.readData(mar.get());
  mdr.set(std::to_string(value1)); // Store data in MDR

  if (d2 != "NULL") {
    mar.set(regFile.get(d2));
    int value2 = memory.readData(mar.get());
    mdr.set(std::to_string(value2)); // Store data in MDR
    acc.set(alu.add(value1, value2));

    if (d3 != "NULL") {
      mar.set(regFile.get(d3));
      mdr.set(std::to_string(acc.get()));
      writeback();
    }

  }else {
    acc.set(alu.add(acc.get(), value1));
  }
}

void ControlUnit::increment(std::string d1){
  mar.set(regFile.get(d1));
  mdr.set(std::to_string(alu.increment(memory.readData(mar.get())))); // Store data in MDR
  writeback();
}

void ControlUnit::decrement(std::string d1){
  mar.set(regFile.get(d1));
  mdr.set(std::to_string(alu.decrement(memory.readData(mar.get())))); // Store data in MDR
  writeback();
}

void ControlUnit::store(std::string d1){
  mar.set(regFile.get(d1));
  mdr.set(std::to_string(acc.get())); // Store data in MDR
  writeback();
}

void ControlUnit::show(std::string d1){
  if (d1 == "ACC") {
    std::cout << "ACC: " << acc.get() << std::endl;
  } else if (d1 == "ICR") {
    std::cout << "ICR: " << icr.get() << std::endl;
  } else if (d1 == "MAR") {
    std::cout << "MAR: " << mar.get() << std::endl;
  } else if (d1 == "MDR") {
    std::cout << "MDR: " << mdr.get() << std::endl;
  } else if (d1 == "UC") {
    std::cout << "UC: " << this->UC << std::endl;
  } else {
    int address = regFile.get(d1);
    if (!pause){
      mar.set(address);
      mdr.set(std::to_string(memory.readData(address)));
    }
    std::cout << "Memory[" << address << "]: " << memory.readData(address) << std::endl;
  }
}

void ControlUnit::executeNextInstruction() {
  std::string instruction = memory.readInstruction(pc.get());
  std::istringstream iss(instruction);
  std::string op, d1, d2, d3;
  iss >> op >> d1 >> d2 >> d3;

  if (op == "PAUSE"){
    pause = true;
    std::cout << "PAUSED" << std::endl;
  }else if(pause && op != "SHW"){
    pause = false;
  }

  fech();

  if (op == "SET") {
    mem(d1, d2);
  } else if (op == "LDR") {
    load(d1);
  } else if (op == "ADD") {
    addition(d1, d2, d3);
  } else if (op == "INC") {
    increment(d1);
  } else if (op == "DEC") {
    decrement(d1);
  } else if (op == "STR") {
    store(d1); 
  } else if (op == "SHW") {
    show(d1);
  } else if (op == "END") {
    std::cout << "END OF EXECUTION" << std::endl;
  }
}
