#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<bool> running{true};

// The loop function runs every 'intervalSeconds' seconds and calls the provided callback.
void gameLoop(int intervalSeconds, void (*onTick)()) {
    while (running) {
        onTick();
        std::this_thread::sleep_for(std::chrono::seconds(intervalSeconds));
    }
}

// Call this to stop the loop from outside.
void stopGameLoop() {
    running = false;
}