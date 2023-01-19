#include "GameFieldLayout.h"

bool GameFieldLayout::isWall(int xCell, int yCell)
{   
    if(xCell < 0){
        xCell = 0;
    }else if(xCell >= FIELD_WIDTH_CELLS){
        xCell = FIELD_WIDTH_CELLS - 1;
    }
    if(FIELD_MATRIX[yCell][xCell] == 1){
        return true;
    }else{
        return false;
    }
}

bool GameFieldLayout::isCreatureInWall(int xCreature, int yCreature)
{
    int upYcell, downYcell, leftXcell, rightXcell;
    upYcell = (yCreature + CELL_PIXEL_SIZE/2) / CELL_PIXEL_SIZE;
    downYcell = ((yCreature + HEROES_SIZE - CELL_PIXEL_SIZE/2) - 1) / CELL_PIXEL_SIZE;
    leftXcell = (xCreature + CELL_PIXEL_SIZE/2) / CELL_PIXEL_SIZE;
    rightXcell = ((xCreature + HEROES_SIZE - CELL_PIXEL_SIZE/2) - 1) / CELL_PIXEL_SIZE;
    return isWall(leftXcell, upYcell)||
            isWall(leftXcell,downYcell)||
            isWall(rightXcell, upYcell)||
            isWall(rightXcell, downYcell);
}
