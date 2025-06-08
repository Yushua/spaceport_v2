#pragma once
#include "entities/room.h"
#include <string>
#include "entities/civilian.h" 

Room createQuarters(int number, int level = 1);
Room createCafeteria(int level = 1);
Room createCanteen(int level = 1);
Room createDeck(int level = 1);
Room createScienceRoom(int level = 1);
Room createEngineeringRoom(int level = 1);
Room createEngineRoom(int level = 1);
Room createStorageRoom(int level = 1);
Room createPort(int level = 1);
Room createHubRoom(const std::string& civilianName, int level = 1);
void setupRoomsAndCivilians(std::vector<Room>& rooms, std::vector<Civilian>& civilians, int numCivilians);
void upgradeRoom(Room& room);