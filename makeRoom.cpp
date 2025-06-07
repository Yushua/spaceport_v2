#include "makeRoom.h"
#include "civilian.h"

Room createQuarters(int number) {
    Room room;
    room.name = "quarters_" + std::to_string(number);
    return room;
}

Room createCafeteria() {
    Room room;
    room.name = "cafeteria";
    return room;
}

Room createCanteen() {
    Room room;
    room.name = "canteen";
    room.type = "canteen";
    room.description = "A place where civilians eat.";
    return room;
}

Room createDeck() {
    Room room;
    room.name = "deck";
    room.workspaces.push_back("CaptainStation");
    room.workspaces.push_back("HelmStation");
    room.workspaces.push_back("HelmStation");
    room.workspaces.push_back("SecurityStation");
    room.workspaces.push_back("SecurityStation");
    return room;
}

Room createScienceRoom() {
    Room room;
    room.name = "science_room";
    return room;
}

Room createEngineeringRoom() {
    Room room;
    room.name = "engineering_room";
    room.workspaces.push_back("EngineerStation");
    room.workspaces.push_back("EngineerStation");
    room.workspaces.push_back("EngineerStation");
    room.workspaces.push_back("EngineerStation");
    return room;
}

Room createEngineRoom() {
    Room room;
    room.name = "engine_room";
    return room;
}

Room createStorageRoom() {
    Room room;
    room.name = "storage_room";
    return room;
}

Room createPort() {
    Room room;
    room.name = "port";
    return room;
}

Room createHubRoom(const std::string& civilianName) {
    Room room;
    room.name = "hubRoom_" + civilianName;
    room.type = "hubRoom";
    room.description = "Private civilian quarters for " + civilianName;
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