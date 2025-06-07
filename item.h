#pragma once
#include <string>

struct Item {
    std::string name;
    std::string type;   // e.g., "food", "engineering", "weapon"
    double weight = 0.0;
};