#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "register-file.h"
#include "memory.h"
#include "alu.h"
#include "string-register.h"
#include "address-register.h"

#include <string>

class ControlUnit {
    private:
        RegisterFile& regFile;
        Memory& memory;
        ALU& alu;
        SR& icr;
        SR& mdr;
        AR& mar;
        AR& pc;
        AR& acc;

        std::string UC;
        bool pause;

        void fech();
        void writeback();
        void mem(std::string& d1, std::string& d2);
        void load(std::string d1);
        void addition(std::string d1, std::string d2, std::string d3);
        void increment(std::string d1);
        void decrement(std::string d1);
        void store(std::string d1);
        void show(std::string d1);

    public:
        ControlUnit(RegisterFile& rf, Memory& mem, ALU& a, SR& i, SR& m, AR& mar, AR& pc, AR& acc);
        void loadProgram(const std::vector<std::string>& program);
        void executeNextInstruction();
};

#endif // CONTROLUNIT_H
