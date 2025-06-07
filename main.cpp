#include <iostream>
#include "loop/loop.h"

// Example tick function
void onTick() {
    static int tickCount = 0;
    std::cout << "15 minutes have passed" << std::endl;
    if (++tickCount >= 5) { // Stop after 5 ticks for demo
        stopGameLoop();
    }
}

int main() {
    int intervalSeconds = 5; // Set the interval here
    std::cout << "Starting Space Port game loop..." << std::endl;
    gameLoop(intervalSeconds, onTick);
    std::cout << "Game loop ended." << std::endl;
    return 0;
}