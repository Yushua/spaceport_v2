#include <iostream>
#include <thread>
#include <atomic>
#include <fstream>
#include "loop/loop.h"
#include "crew.h"
#include "makeCrew.h"
#include "room.h"
#include "makeRoom.h"
#include "workstation.h"
#include "makeWorkstation.h"

std::vector<CrewMember> crew;
std::vector<Room> rooms;
std::vector<Workstation> workstations;

int minutes = 0;
int hours = 0;
int days = 0;

void creatingGame() {
    crew.clear();
    rooms.clear();
    workstations.clear();

    // Create crew and assign names
    CrewMember commander = createCommander();
    commander.name = "Commander Smith";
    crew.push_back(commander);

    CrewMember officer1 = createOfficer();
    officer1.name = "Officer Lee";
    crew.push_back(officer1);

    CrewMember officer2 = createOfficer();
    officer2.name = "Officer Brown";
    crew.push_back(officer2);

    CrewMember headEngineer = createHeadEngineer();
    headEngineer.name = "Head Engineer Garcia";
    crew.push_back(headEngineer);

    for (int i = 0; i < 3; ++i) {
        CrewMember engineer = createEngineer();
        engineer.name = "Engineer_" + std::to_string(i + 1);
        crew.push_back(engineer);
    }

    CrewMember medic = createMedic();
    medic.name = "Medic Martinez";
    crew.push_back(medic);

    for (int i = 0; i < 3; ++i) {
        CrewMember ensign = createEnsign();
        ensign.name = "Ensign_" + std::to_string(i + 1);
        crew.push_back(ensign);
    }

    for (int i = 0; i < 4; ++i) {
        CrewMember training = createTraining();
        training.name = "Training_" + std::to_string(i + 1);
        crew.push_back(training);
    }

    // Create rooms
    for (int i = 0; i < crew.size(); ++i)
        rooms.push_back(createQuarters(i + 1));
    rooms.push_back(createCafeteria());
    rooms.push_back(createDeck());
    rooms.push_back(createEngineeringRoom());
    rooms.push_back(createStorageRoom());
    rooms.push_back(createPort());

    // Create workstations for deck and engineering room
    workstations.push_back(createCaptainStation());
    workstations.push_back(createHelmStation());
    workstations.push_back(createHelmStation());
    workstations.push_back(createSecurityStation());
    workstations.push_back(createSecurityStation());
    workstations.push_back(createEngineerStation());
    workstations.push_back(createEngineerStation());
    workstations.push_back(createEngineerStation());
    workstations.push_back(createEngineerStation());

    // Assign quarters, workstations, location, and status
    for (size_t i = 0; i < crew.size(); ++i) {
        crew[i].room = "quarters_" + std::to_string(i + 1);
        if (i == 0) {
            crew[i].workstation = "CaptainStation";
            crew[i].location = "deck";
            crew[i].status = "working";
        } else if (i == 1 || i == 2) {
            crew[i].workstation = "HelmStation";
            crew[i].location = "deck";
            crew[i].status = "working";
        } else if (i == 3) {
            crew[i].workstation = "EngineerStation";
            crew[i].location = "engineering_room";
            crew[i].status = "working";
        } else if (i >= 4 && i <= 6) {
            crew[i].workstation = "EngineerStation";
            crew[i].location = "engineering_room";
            crew[i].status = "working";
        } else {
            crew[i].workstation = "";
            crew[i].location = crew[i].room;
            crew[i].status = "nothing";
        }
    }
}

void clearScreen();

// Add this function to write room data every tick
void writeRoomDataToFile(const std::vector<CrewMember>& crew, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return;
    out << "Name,RoomType,RoomName\n";
    for (const auto& member : crew) {
        std::string roomType;
        if (member.location == member.room) {
            roomType = "quarters";
        } else if (member.location == "deck") {
            roomType = "deck";
        } else if (member.location == "engineering_room") {
            roomType = "engineering_room";
        } else {
            roomType = member.location;
        }
        out << member.name << "," << roomType << "," << member.location << "\n";
    }
    out.close();
}

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
        writeRoomDataToFile(crew, "info/rooms/roomData.txt");
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