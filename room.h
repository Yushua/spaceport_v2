#pragma once
#include <string>
#include <vector>

struct Room {
    std::string name;
    std::string type;
    std::string description;
    std::vector<std::string> workspaces;
};
