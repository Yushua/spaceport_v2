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

void clearScreen();

void timeLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        minutes += 15;
        if (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        if (hours >= 24) {
            hours -= 24;
            days++;
        }
        clearScreen();
        std::cout << "Time: " << days << " days, " << hours << " hours, " << minutes << " minutes" << std::endl;
        writeCrewToFile(crew, "info/crew/crewLog.txt");
        std::cout << "Crew log updated." << std::endl;
        std::cout << "Enter command: " << std::flush;
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
        std::cout << "Current Time: " << days << " days, " << hours << " hours, " << minutes << " minutes" << std::endl;
        handleCommands(crew);
        clearScreen();
    }
}

// Add this function to clear the terminal screen
void clearScreen() {
    // ANSI escape code to clear screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    clearScreen();
    creatingGame();
    std::cout << "Starting Space Port game..." << std::endl;
    std::thread t1(timeLoop);
    std::thread t2(commandLoop);
    t1.join();
    t2.join();
    std::cout << "Game ended." << std::endl;
    return 0;
}