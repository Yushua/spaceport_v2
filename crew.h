#pragma once
#include <string>
#include <vector>
#include "workstation.h"

struct CrewMember {
    std::string name;
    std::string title;
    int lvl;
    int exp;
    std::string description;
    std::string location;
    std::string room;
    std::string workstation;
    std::string status;
    int intelligence = 0;
    int strength = 0;
    int endurance = 0;
    int hunger = 0;
    int sleep = 0;
    int hungerLimit = 0;
    int sleepLimit = 0;
};

std::vector<CrewMember> createCrew(int count);
void listCrew(const std::vector<CrewMember>& crew);
void showCrewMember(const std::vector<CrewMember>& crew, const std::string& name);
void handleCommands(const std::vector<CrewMember>& crew);
void writeCrewToFile(const std::vector<CrewMember>& crew, const std::vector<Workstation>& workstations, const std::string& filename = "dataLog.txt");

CrewMember createCommander();
CrewMember createEngineer();
CrewMember createOfficer();
CrewMember createMedic();
CrewMember createHeadEngineer();
CrewMember createEnsign();
CrewMember createTraining();