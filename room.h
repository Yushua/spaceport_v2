#pragma once
#include <string>
#include <vector>

struct Room {
    std::string name;
    std::string type;
    std::string description;
    std::vector<std::string> workspaces;
    int level = 1;
    int baseStorage = 0;
    int storage = 0;
};
