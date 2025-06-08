#pragma once
#include <string>

struct Workstation {
    std::string name;
    std::string type;
    int expGain = 0; // Add this line
};