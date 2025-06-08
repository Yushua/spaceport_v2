#include "create/makeRoom.h"
#include "entities/civilian.h"

Room createQuarters(int number, int level /*= 1*/) {
    Room room;
    room.name = "quarters_" + std::to_string(number);
    room.baseStorage = 5;
    room.type = "military";
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createCafeteria(int level /*= 1*/) {
    Room room;
    room.name = "cafeteria";
    room.type = "military";
    room.baseStorage = 5;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createCanteen(int level /*= 1*/) {
    Room room;
    room.name = "canteen";
    room.type = "canteen";
    room.description = "A place where civilians eat.";
    room.baseStorage = 5;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createDeck(int level /*= 1*/) {
    Room room;
    room.name = "deck";
    room.type = "military";
    room.baseStorage = 10;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    room.workspaces = {"CaptainStation", "HelmStation", "HelmStation", "SecurityStation", "SecurityStation"};
    return room;
}

Room createScienceRoom(int level /*= 1*/) {
    Room room;
    room.name = "science_room";
    room.type = "military";
    room.baseStorage = 15;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createEngineeringRoom(int level /*= 1*/) {
    Room room;
    room.name = "engineering_room";
    room.type = "military";
    room.baseStorage = 15;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    room.workspaces = {"EngineerStation", "EngineerStation", "EngineerStation", "EngineerStation"};
    return room;
}

Room createEngineRoom(int level /*= 1*/) {
    Room room;
    room.name = "engine_room";
    room.type = "military";
    room.baseStorage = 15;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createStorageRoom(int level /*= 1*/) {
    Room room;
    room.name = "storage_room";
    room.type = "military";
    room.baseStorage = 40;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createPort(int level /*= 1*/) {
    Room room;
    room.name = "port";
    room.type = "All";
    room.baseStorage = 20;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

Room createHubRoom(const std::string& civilianName, int level /*= 1*/) {
    Room room;
    room.name = "hubRoom_" + civilianName;
    room.type = "hubRoom";
    room.description = "Private civilian quarters for " + civilianName;
    room.baseStorage = 5;
    room.level = level;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
    return room;
}

void setupRoomsAndCivilians(std::vector<Room>& rooms, std::vector<Civilian>& civilians, int numCivilians) {
    rooms.push_back(createCanteen());
    for (int i = 0; i < numCivilians; ++i) {
        Civilian civ = createCivilian();
        rooms.push_back(createHubRoom(civ.name));
        civ.room = "hubRoom_" + civ.name;
        civ.location = civ.room;
        civilians.push_back(civ);
    }
}

void upgradeRoom(Room& room) {
    room.level += 1;
    room.storage = room.baseStorage + static_cast<int>(room.baseStorage * 0.2 * (room.level - 1));
}