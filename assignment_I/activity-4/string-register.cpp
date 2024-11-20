#include "string-register.h"

SR::SR() : data("") {}

std::string SR::get() {
    return data;
}

void SR::set(const std::string& data) {
    this->data = data;
}
