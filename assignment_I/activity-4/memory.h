#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>

enum class Section {
    TEXT, DATA
};

class Memory {
    std::vector<std::string> textSection;
    std::vector<int> dataSection;

public:
    Memory(int textSize, int dataSize);
    std::string readInstruction(int address);
    int readData(int address);
    void writeInstruction(int address, const std::string& instruction);
    void writeData(int address, int value);
};

#endif // MEMORY_H
