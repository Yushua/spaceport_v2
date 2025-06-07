#include "makeRoom.h"

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