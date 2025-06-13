#include "entities/crew.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <filesystem>

extern std::vector<std::string> firstNames;
extern std::vector<std::string> lastNames;

std::vector<std::string> titles = {
    "Engineer", "Pilot", "Scientist", "Medic", "Technician"
};

std::vector<CrewMember> createCrew(int count) {
    std::vector<CrewMember> crew;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> firstDist(0, firstNames.size() - 1);
    std::uniform_int_distribution<> lastDist(0, lastNames.size() - 1);
    std::uniform_int_distribution<> titleDist(0, titles.size() - 1);

    std::filesystem::create_directories("info/crew/crewMembers");

    for (int i = 0; i < count; ++i) {
        CrewMember member;
        member.name = firstNames[firstDist(gen)] + " " + lastNames[lastDist(gen)];
        member.title = titles[titleDist(gen)];
        member.lvl = 0;
        member.exp = 0;
        member.description = "A valued member of the crew.";
        member.location = "";
        member.room = "";
        member.workstation = "";
        crew.push_back(member);

        std::string filename = "info/crew/crewMembers/" + member.name + ".txt";
        std::replace(filename.begin(), filename.end(), ' ', '_');
        std::ofstream out(filename);
        if (out) {
            out << "Name: " << member.name << "\n";
            out << "Title: " << member.title << "\n";
            out << "Level: " << member.lvl << "\n";
            out << "Exp: " << member.exp << "\n";
            out << "Description: " << member.description << "\n";
            out << "Location: " << member.location << "\n";
            out << "Room: " << member.room << "\n";
            out << "Workstation: " << member.workstation << "\n";
        }
    }
    return crew;
}

void listCrew(const std::vector<CrewMember>& crew) {
    std::cout << "Crew List:\n";
    for (const auto& member : crew) {
        std::cout << "- " << member.name << " (" << member.title << ")\n";
    }
}

void showCrewMember(const std::vector<CrewMember>& crew, const std::string& name) {
    for (const auto& member : crew) {
        if (member.name == name) {
            std::cout << "Name: " << member.name << "\n";
            std::cout << "Title: " << member.title << "\n";
            std::cout << "Level: " << member.lvl << "\n";
            std::cout << "Exp: " << member.exp << "\n";
            std::cout << "Description: " << member.description << "\n";
            std::cout << "Location: " << member.location << "\n";
            std::cout << "Room: " << member.room << "\n";
            std::cout << "Workstation: " << member.workstation << "\n";
            return;
        }
    }
    std::cout << "Crew member not found.\n";
}

void handleCommands(const std::vector<CrewMember>& crew) {
    std::string input;
    std::cout << "Enter command: ";
    std::getline(std::cin, input);

    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    if (lowerInput == "crew") {
        std::cout << "Crew info updated in dataLog.txt\n";
    } else {
        showCrewMember(crew, input);
    }
}

void writeCrewToFile(const std::vector<CrewMember>& crew, const std::vector<Workstation>& workstations, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return;
    out << "Crew List:\n";
    for (const auto& member : crew) {
        out << "- " << member.name << " (" << member.title << ")\n";
        out << "  Level: " << member.lvl << ", Exp: " << member.exp << "\n";
        out << "  Intelligence: " << member.intelligence
            << ", Strength: " << member.strength
            << ", Endurance: " << member.endurance << "\n";
        out << "  Hunger: " << member.hunger << "/" << member.hungerLimit
            << ", Sleep: " << member.sleep << "/" << member.sleepLimit << "\n";
        out << "  Status: " << member.status << "\n";
        out << "  Location: " << member.location << ", Room: " << member.room << ", Workstation: " << member.workstation << "\n";
    }
    out.close();
}

void updateCrewMemberFiles(const std::vector<CrewMember>& crew) {
    for (const auto& member : crew) {
        std::string roleFolder;
        if (member.title == "Commander") roleFolder = "command";
        else if (member.title == "Officer") roleFolder = "officer";
        else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
        else if (member.title == "Medic") roleFolder = "medic";
        else if (member.title == "Training") roleFolder = "training";
        else if (member.title == "Ensign") roleFolder = "ensign";
        else roleFolder = "other";

        std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

        std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
        std::replace(filename.begin(), filename.end(), ' ', '_');
        std::ofstream out(filename);
        if (out) {
            out << "Name: " << member.name << "\n";
            out << "Title: " << member.title << "\n";
            out << "Level: " << member.lvl << ", Exp: " << member.exp << "\n";
            out << "Intelligence: " << member.intelligence << "\n";
            out << "Strength: " << member.strength << "\n";
            out << "Endurance: " << member.endurance << "\n";
            out << "Hunger: " << member.hunger << "/" << member.hungerLimit << "\n";
            out << "Sleep: " << member.sleep << "/" << member.sleepLimit << "\n";
            out << "Status: " << member.status << "\n";
            out << "Location: " << member.location << "\n";
            out << "Room: " << member.room << "\n";
            out << "Workstation: " << member.workstation << "\n";
        }
    }
}