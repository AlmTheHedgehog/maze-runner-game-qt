#pragma once
#include "GlobalVars.h"

class GameFieldLayout{
    public:
        enum CellType{freeCell = 0, wallCell = 1, plantCell = 2, planktonCell = 3, 
                        fishCell = 4, jellyfishCell = 5, scoreCell = 6};

        static bool isWall(int xCell, int yCell);
        static bool isCreatureInWall(int xCreature, int yCreature);
        static CellType getCellType(int xCell, int yCell);
};