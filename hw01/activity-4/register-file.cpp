#include "register-file.h"
#include <stdexcept>

RegisterFile::RegisterFile(){
    for(int i = 0; i < 10; ++i){
        this->registers.push_back(i);
    }
}

int RegisterFile::getIndex(const std::string& reg) {
    if (reg[0] == 'D') {
        int index = std::stoi(reg.substr(1));
        if (index >= 0 && index < 10) {
            return index;
        }
    }
    throw std::invalid_argument("Invalid register name");
}

int RegisterFile::get(const std::string& reg) {
    int index = getIndex(reg);
    return registers[index];
}

void RegisterFile::set(const std::string& reg, int value) {
    int index = getIndex(reg);
    registers[index] = value;
}
