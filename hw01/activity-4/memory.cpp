#include "memory.h"
#include <stdexcept>

Memory::Memory(int textSize, int dataSize) 
  : textSection(textSize, ""), dataSection(dataSize, 0) {}

std::string Memory::readInstruction(int address) {
  if (address >= 0 && address < textSection.size()) {
    return textSection[address];
  }
  throw std::out_of_range("Invalid text memory address");
}

int Memory::readData(int address) {
  if (address >= 0 && address < dataSection.size()) {
    return dataSection[address];
  }
  throw std::out_of_range("Invalid data memory address");
}

void Memory::writeInstruction(int address, const std::string& instruction) {
  if (address >= 0 && address < textSection.size()) {
    textSection[address] = instruction;
  } else {
    throw std::out_of_range("Invalid text memory address");
  }
}

void Memory::writeData(int address, int value) {
  if (address >= 0 && address < dataSection.size()) {
    dataSection[address] = value;
  } else {
    throw std::out_of_range("Invalid data memory address");
  }
}
