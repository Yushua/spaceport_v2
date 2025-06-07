#include <iostream>
#include "loop/loop.h"
#include "crew.h"

std::vector<CrewMember> crew;

void creatingGame() {
    crew = createCrew(5);
}

// Example tick function
void onTick() {
    static int tickCount = 0;
    std::cout << "15 minutes have passed" << std::endl;
    handleCommands(crew);
    if (++tickCount >= 5) { // Stop after 5 ticks for demo
        stopGameLoop();
    }
}

int main() {
    int intervalSeconds = 5; // Set the interval here
    creatingGame();
    std::cout << "Starting Space Port game loop..." << std::endl;
    gameLoop(intervalSeconds, onTick);
    std::cout << "Game loop ended." << std::endl;
    return 0;
}