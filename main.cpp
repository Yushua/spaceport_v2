#include <iostream>
#include <thread>
#include <atomic>
#include "loop/loop.h"
#include "crew.h"
#include "makeCrew.h"

std::vector<CrewMember> crew;

int minutes = 0;
int hours = 0;
int days = 0;

void creatingGame() {
    crew.clear();
    crew.push_back(createCommander());
    crew.push_back(createOfficer());
    crew.push_back(createOfficer());
    crew.push_back(createHeadEngineer());
    for (int i = 0; i < 3; ++i) crew.push_back(createEngineer());
    crew.push_back(createMedic());
    for (int i = 0; i < 3; ++i) crew.push_back(createEnsign());
    for (int i = 0; i < 4; ++i) crew.push_back(createTraining());
}

void timeLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        minutes += 15;
        if (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        if (hours >= 24) {
            hours -= 24;
            days++;
        }
        std::cout << "Time: " << days << " days, " << hours << " hours, " << minutes << " minutes" << std::endl;
        writeCrewToFile(crew, "info/crew/crewLog.txt");
        std::cout << "Crew log updated." << std::endl;
    }
}

void commandLoop() {
    std::string input;
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        if (input == "exit" || input == "quit") {
            break;
        }
        // Show the current time when a command is entered
        std::cout << "Current Time: " << days << " days, " << hours << " hours, " << minutes << " minutes" << std::endl;
        handleCommands(crew);
    }
}

int main() {
    creatingGame();
    std::cout << "Starting Space Port game..." << std::endl;
    std::thread t1(timeLoop);
    std::thread t2(commandLoop);
    t1.join();
    t2.join();
    std::cout << "Game ended." << std::endl;
    return 0;
}