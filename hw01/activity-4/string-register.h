#ifndef SR_H
#define SR_H

#include <string>

class SR {
    std::string data;

public:
    SR();
    std::string get();
    void set(const std::string& data);
};

#endif // SR_H
