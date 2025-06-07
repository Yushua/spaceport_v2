#pragma once
#include <string>

struct Resource {
    std::string name;
    std::string type;   // e.g., "ore", "manufactured", "processed", "raw", "energy"
    double weight = 0.0;
};