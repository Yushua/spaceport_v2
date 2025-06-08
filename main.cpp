#include <iostream>
#include <thread>
#include <atomic>
#include <fstream>
#include <algorithm>
#include "loop/loop.h"
#include "entities/crew.h"
#include "create/makeCrew.h"
#include "entities/room.h"
#include "create/makeRoom.h"
#include "entities/workstation.h"
#include "create/makeWorkstation.h"

void updateCrewStatusOnTick(std::vector<CrewMember>& crew);
void updateCrewMemberFiles(const std::vector<CrewMember>& crew);

std::vector<CrewMember> crew;
std::vector<Room> rooms;
std::vector<Workstation> workstations;

int minutes = 0;
int hours = 0;
int days = 0;
int lastUpdateHour = 0;

void creatingGame() {
    crew.clear();
    rooms.clear();
    workstations.clear();

    // Create crew using only the createXxx() functions
    crew.push_back(createCommander());
    crew.push_back(createOfficer());
    crew.push_back(createOfficer());
    crew.push_back(createHeadEngineer());

    for (int i = 0; i < 3; ++i)
        crew.push_back(createEngineer());

    crew.push_back(createMedic());

    for (int i = 0; i < 3; ++i)
        crew.push_back(createEnsign());

    for (int i = 0; i < 4; ++i)
        crew.push_back(createTraining());

    // Create rooms, all at level 1
    for (int i = 0; i < crew.size(); ++i)
        rooms.push_back(createQuarters(i + 1, 1));
    rooms.push_back(createCafeteria(1));
    rooms.push_back(createDeck(1));
    rooms.push_back(createEngineeringRoom(1));
    rooms.push_back(createStorageRoom(1));
    rooms.push_back(createPort(1));

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

    // Create initial crew member files
    updateCrewMemberFiles(crew);
}

void clearScreen();

// Add this function to write room data every tick
void writeRoomDataToFile(const std::vector<CrewMember>& crew, const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return;
    out << "Name,RoomType,RoomName,RoomLevel\n";
    for (const auto& member : crew) {
        // Find the room object for this member's location
        auto it = std::find_if(rooms.begin(), rooms.end(), [&](const Room& room) {
            return room.name == member.location;
        });
        std::string roomType = (it != rooms.end()) ? it->type : "";
        int roomLevel = (it != rooms.end()) ? it->level : 1;
        out << member.name << "," << roomType << "," << member.location << "," << roomLevel << "\n";
    }
    out.close();
}

void writeAllRoomsToFile(const std::vector<Room>& rooms, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return;
    out << "RoomName,RoomType,RoomLevel,BaseStorage,Storage,Description\n";
    for (const auto& room : rooms) {
        out << room.name << ","
            << room.type << ","
            << room.level << ","
            << room.baseStorage << ","
            << room.storage << ","
            << room.description << "\n";
    }
    out.close();
}

void timeLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        minutes += 15;
        if (minutes >= 60) { minutes -= 60; hours++; }
        if (hours >= 24) { hours -= 24; days++; }

        updateCrewStatusOnTick(crew);

        // Update crew member files every 2 hours
        if (hours % 2 == 0 && hours != lastUpdateHour) {
            updateCrewMemberFiles(crew);
            lastUpdateHour = hours;
        }

        clearScreen();
        std::cout << "Time: " << days << " days, " << hours << " hours, " << minutes << " minutes" << std::endl;
        writeCrewToFile(crew, workstations, "info/crew/crewLog.txt");
        writeAllRoomsToFile(rooms, "info/rooms/roomData.txt");
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

void updateCrewStatusOnTick(std::vector<CrewMember>& crew) {
    for (auto& member : crew) {
        // If eating, reduce hunger
        if (member.status == "eating") {
            member.hunger -= 15;
            if (member.hunger <= 0) {
                member.hunger = 0;
                // After eating, go back to work if possible
                if (!member.workstation.empty()) {
                    member.status = "working";
                    // Find the room containing the workstation
                    for (const auto& room : rooms) {
                        if (std::find(room.workspaces.begin(), room.workspaces.end(), member.workstation) != room.workspaces.end()) {
                            member.location = room.name;
                            break;
                        }
                    }
                } else {
                    member.status = "nothing";
                    member.location = member.room;
                }
            }
            continue;
        }
        // If sleeping, reduce sleep
        if (member.status == "sleeping") {
            member.sleep -= 15;
            if (member.sleep <= 0) {
                member.sleep = 0;
                // After sleeping, go back to work if possible
                if (!member.workstation.empty()) {
                    member.status = "working";
                    // Find the room containing the workstation
                    for (const auto& room : rooms) {
                        if (std::find(room.workspaces.begin(), room.workspaces.end(), member.workstation) != room.workspaces.end()) {
                            member.location = room.name;
                            break;
                        }
                    }
                } else {
                    member.status = "nothing";
                    member.location = member.room;
                }
            }
            continue;
        }
        // Add hunger and sleep each tick
        member.hunger += 5;
        member.sleep += 4;
        // Check hunger first
        if (member.hunger >= member.hungerLimit) {
            member.status = "eating";
            member.location = "cafeteria";
            continue;
        }
        // Then check sleep
        if (member.sleep >= member.sleepLimit) {
            member.status = "sleeping";
            member.location = member.room;
            continue;
        }
        // If not eating or sleeping, set status and GAIN EXPERIENCE if working
        if (!member.workstation.empty()) {
            member.status = "working";
            // Find the room containing the workstation
            for (const auto& room : rooms) {
                if (std::find(room.workspaces.begin(), room.workspaces.end(), member.workstation) != room.workspaces.end()) {
                    member.location = room.name;
                    break;
                }
            }
            // Experience gain by workstation
            for (const auto& ws : workstations) {
                if (ws.name == member.workstation) {
                    member.exp += ws.expGain;
                    break;
                }
            }
        } else {
            member.status = "nothing";
            member.location = member.room;
        }
    }
}

void updateCrewMemberFiles(const std::vector<CrewMember>& crew);

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