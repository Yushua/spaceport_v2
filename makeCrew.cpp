#include "makeCrew.h"
#include <random>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#include <string>
#include "randomUtil.h"

std::vector<std::string> firstNames = {
    "Alex", "Morgan", "Taylor", "Jordan", "Casey", "Riley", "Jamie", "Drew", "Skyler", "Avery",
    "Sam", "Charlie", "Robin", "Cameron", "Harper", "Quinn", "Peyton", "Reese", "Sawyer", "Rowan",
    "Elliot", "Finley", "Hayden", "Jesse", "Kai", "Logan", "Micah", "Parker", "Sage", "Toby"
};

std::vector<std::string> lastNames = {
    "Smith", "Johnson", "Lee", "Brown", "Garcia", "Martinez", "Davis", "Clark", "Lewis", "Walker",
    "Young", "Allen", "King", "Wright", "Scott", "Green", "Baker", "AdAMS", "Nelson", "Carter",
    "Mitchell", "Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins"
};

std::string getRandomName() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> firstDist(0, firstNames.size() - 1);
    std::uniform_int_distribution<> lastDist(0, lastNames.size() - 1);
    return firstNames[firstDist(gen)] + " " + lastNames[lastDist(gen)];
}

CrewMember createCommander() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createEngineer() {
    CrewMember member;
    member.name = getRandomName(); // <-- Assign random full name here!
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createOfficer() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createMedic() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createHeadEngineer() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createEnsign() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}

CrewMember createTraining() {
    CrewMember member;
    member.name = getRandomName();
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

    // Save to file
    std::string roleFolder;
    if (member.title == "Commander") roleFolder = "command";
    else if (member.title == "Officer") roleFolder = "officer";
    else if (member.title == "Head Engineer" || member.title == "Engineer") roleFolder = "engineer";
    else if (member.title == "Medic") roleFolder = "medic";
    else if (member.title == "Training") roleFolder = "training";
    else if (member.title == "Ensign") roleFolder = "ensign";
    else roleFolder = "other";

    std::filesystem::create_directories("info/crew/crewMembers/" + roleFolder);

    std::string filename = "info/crew/crewMembers/" + roleFolder + "/" + member.name + ".txt";
    std::replace(filename.begin(), filename.end(), ' ', '_');
    std::ofstream out(filename);
    if (out) {
        out << "Name: " << member.name << "\n";
        out << "Title: " << member.title << "\n";
        out << "Level: " << member.lvl << "\n";
        // ...add other initial stats as needed...
    }

    return member;
}