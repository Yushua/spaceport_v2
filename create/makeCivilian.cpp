#include "entities/civilian.h"
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include "utils/randomUtil.h"

extern std::vector<std::string> firstNames;
extern std::vector<std::string> lastNames;

std::vector<std::string> jobs = {"shopkeeper", "doctor", "barber", "baker", "artist"};
std::vector<std::string> statuses = {"refugee", "seller", "tourist", "civilian"};


std::string getRandomCivilianName() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> firstDist(0, firstNames.size() - 1);
    std::uniform_int_distribution<> lastDist(0, lastNames.size() - 1);
    return firstNames[firstDist(gen)] + " " + lastNames[lastDist(gen)];
}

Civilian createCivilian() {
    Civilian civ;
    civ.name = getRandomCivilianName();
    civ.job = jobs[randomBetween(0, jobs.size() - 1)];
    civ.status = statuses[randomBetween(0, statuses.size() - 1)];
    civ.intelligence = randomBetween(1, 15);
    civ.strength = randomBetween(1, 15);
    civ.endurance = randomBetween(1, 15);
    civ.hunger = 0;
    civ.sleep = 0;
    civ.hungerLimit = civ.strength * civ.endurance + 30;
    civ.sleepLimit = civ.intelligence * civ.endurance + 40;
    civ.room = "hubRoom_" + civ.name;
    civ.location = civ.room;
    return civ;
}

void updateCivilianStatusOnTick(std::vector<Civilian>& civilians) {
    for (auto& civ : civilians) {
        // If eating, reduce hunger
        if (civ.location == "canteen") {
            civ.hunger -= 15;
            if (civ.hunger <= 0) {
                civ.hunger = 0;
                civ.location = civ.room;
            }
            continue;
        }
        // If sleeping, reduce sleep
        if (civ.location == civ.room && civ.sleep > 0) {
            civ.sleep -= 15;
            if (civ.sleep <= 0) {
                civ.sleep = 0;
            }
            continue;
        }
        // Add hunger and sleep each tick
        civ.hunger += 5;
        civ.sleep += 4;
        // Go to canteen if hungry
        if (civ.hunger >= civ.hungerLimit) {
            civ.location = "canteen";
            continue;
        }
        // Sleep if tired
        if (civ.sleep >= civ.sleepLimit) {
            civ.location = civ.room;
            continue;
        }
        // Otherwise, stay in room
        civ.location = civ.room;
    }
}