#pragma once

void gameLoop(int intervalSeconds, void (*onTick)());
void stopGameLoop();