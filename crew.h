#pragma once
#include <string>
#include <vector>

struct CrewMember {
    std::string name;
    std::string title;
    int lvl;
    int exp;
    std::string description;
    std::string location;
    std::string room;
    std::string workstation;
};

std::vector<CrewMember> createCrew(int count);
void listCrew(const std::vector<CrewMember>& crew);
void showCrewMember(const std::vector<CrewMember>& crew, const std::string& name);
void handleCommands(const std::vector<CrewMember>& crew);