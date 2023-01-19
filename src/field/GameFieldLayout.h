#pragma once
#include "GlobalVars.h"

class GameFieldLayout{
    public:
        static bool isWall(int xCell, int yCell);
        static bool isCreatureInWall(int xCreature, int yCreature);
};