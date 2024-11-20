#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <vector>
#include <string>

class RegisterFile {
    std::vector<int> registers;

    int getIndex(const std::string& reg);

public:
    RegisterFile();
    int get(const std::string& reg);
    void set(const std::string& reg, int value);
};

#endif // REGISTERFILE_H
