#pragma once
#include <string>
#include <vector>

struct Room {
    std::string name;
    std::string location;
    int space;
    std::vector<std::pair<std::string, int>> inventory;
    std::vector<std::string> additions;
    std::vector<std::string> workspaces;
};