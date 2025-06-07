#pragma once
#include <string>

struct Civilian {
    std::string name;
    std::string job;      // shopkeeper, doctor, barber, baker, artist
    std::string status;   // refugee, seller, tourist, civilian
    int intelligence = 0;
    int strength = 0;
    int endurance = 0;
    int hunger = 0;
    int sleep = 0;
    int hungerLimit = 0;
    int sleepLimit = 0;
    std::string location; // "hubRoom" or "canteen"
    std::string room;     // their hubRoom
};

Civilian createCivilian();