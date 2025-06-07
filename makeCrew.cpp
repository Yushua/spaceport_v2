#include "makeCrew.h"
#include <random>

// Helper for random stat generation
int randomBetween(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

CrewMember createCommander() {
    CrewMember member;
    member.title = "Commander";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Leader of the crew.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(4, 8);
    member.strength = randomBetween(4, 8);
    member.endurance = randomBetween(4, 8);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createEngineer() {
    CrewMember member;
    member.title = "Engineer";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Responsible for technical systems.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(0, 4);
    member.strength = randomBetween(0, 4);
    member.endurance = randomBetween(0, 4);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createOfficer() {
    CrewMember member;
    member.title = "Officer";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Handles operations and discipline.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(4, 8);
    member.strength = randomBetween(4, 8);
    member.endurance = randomBetween(4, 8);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createMedic() {
    CrewMember member;
    member.title = "Medic";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Responsible for crew health.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(0, 4);
    member.strength = randomBetween(0, 4);
    member.endurance = randomBetween(0, 4);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createHeadEngineer() {
    CrewMember member;
    member.title = "Head Engineer";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Leads the engineering team.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(4, 8);
    member.strength = randomBetween(4, 8);
    member.endurance = randomBetween(4, 8);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createEnsign() {
    CrewMember member;
    member.title = "Ensign";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Junior officer in training.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(0, 4);
    member.strength = randomBetween(0, 4);
    member.endurance = randomBetween(0, 4);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}

CrewMember createTraining() {
    CrewMember member;
    member.title = "Training";
    member.lvl = 0;
    member.exp = 0;
    member.description = "Crew member in training.";
    member.location = "";
    member.room = "";
    member.workstation = "";
    member.intelligence = randomBetween(0, 4);
    member.strength = randomBetween(0, 4);
    member.endurance = randomBetween(0, 4);
    member.hunger = 0;
    member.sleep = 0;
    member.hungerLimit = member.strength * member.endurance + 30;
    member.sleepLimit = member.intelligence * member.endurance + 40;
    member.status = "nothing";
    return member;
}