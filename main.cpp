#include <iostream>
#include "loop/loop.h"
#include "crew.h"

std::vector<CrewMember> crew;

void creatingGame() {
    crew = createCrew(5);
}

void onTick() {
    static int tickCount = 0;
    std::cout << "15 minutes have passed" << std::endl;
    writeCrewToFile(crew, "info/crew/crewLog.txt");
    handleCommands(crew);
    if (++tickCount >= 5) {
        stopGameLoop();
    }
}

int main() {
    int intervalSeconds = 5;
    creatingGame();
    std::cout << "Starting Space Port game loop..." << std::endl;
    gameLoop(intervalSeconds, onTick);
    std::cout << "Game loop ended." << std::endl;
    return 0;
}