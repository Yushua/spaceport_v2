#include "crew.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <filesystem>

std::vector<std::string> firstNames = {
    "Alex", "Morgan", "Taylor", "Jordan", "Casey",
    "Riley", "Jamie", "Drew", "Skyler", "Avery"
};
std::vector<std::string> lastNames = {
    "Smith", "Johnson", "Lee", "Brown", "Garcia",
    "Martinez", "Davis", "Clark", "Lewis", "Walker"
};
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

void writeCrewToFile(const std::vector<CrewMember>& crew, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Could not open " << filename << " for writing.\n";
        return;
    }
    out << "Crew List:\n";
    for (const auto& member : crew) {
        out << "- " << member.name << " (" << member.title << ")\n";
        out << "  Level: " << member.lvl << ", Exp: " << member.exp << "\n";
        out << "  Description: " << member.description << "\n";
        out << "  Location: " << member.location << ", Room: " << member.room << ", Workstation: " << member.workstation << "\n";
    }
    out.close();
}