#pragma once
#include "room.h"
#include <string>

Room createQuarters(int number);
Room createCafeteria();
Room createCanteen();
Room createDeck();
Room createScienceRoom();
Room createEngineeringRoom();
Room createEngineRoom();
Room createStorageRoom();
Room createPort();
Room createHubRoom(const std::string& civilianName);