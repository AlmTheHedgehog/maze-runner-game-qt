#include "GreenFish.h"

GreenFish::GreenFish(QWidget *parent, int xCell, int yCell):
                Fish(parent, xCell, yCell, 
                ":/creatures/fish/green/fish_green_up.png", 
                ":/creatures/fish/green/fish_green_down.png", 
                ":/creatures/fish/green/fish_green_left.png", 
                ":/creatures/fish/green/fish_green_right.png"){
}

void GreenFish::calcMovement(){
    if(curMove == noMove){
        newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
        oneStepSpeed = FISH_SPEED;
    }
    jellyfishVector.setVector(jellyfishCoords[0] - getX(), jellyfishCoords[1] - getY());
    if(jellyfishVector.x == 0){
        if(jellyfishVector.y > 0){
            for(int yCounter = getY(); (yCounter + HEROES_SIZE) < jellyfishCoords[1]; yCounter += HALF_OF_CELL){
                if(GameFieldLayout::isCreatureInWall(jellyfishCoords[0], yCounter)){
                    return;
                }
            }
            newMoveDir(moveDown);
            oneStepSpeed = FISH_SPEED * ANGRY_FISH_SPEED_MULTIPLIER;
        }else{
            for(int yCounter = getY(); yCounter > (jellyfishCoords[1] + HEROES_SIZE); yCounter -= HALF_OF_CELL){
                if(GameFieldLayout::isCreatureInWall(jellyfishCoords[0], yCounter)){
                    return;
                }
            }
            newMoveDir(moveUp);
            oneStepSpeed = FISH_SPEED * ANGRY_FISH_SPEED_MULTIPLIER;
        }
    }else if(jellyfishVector.y == 0){
        if(jellyfishVector.x > 0){
            for(int xCounter = getX(); (xCounter + HEROES_SIZE) < jellyfishCoords[0]; xCounter += HALF_OF_CELL){
                if(GameFieldLayout::isCreatureInWall(xCounter, jellyfishCoords[1])){
                    return;
                }
            }
            newMoveDir(moveRight);
            oneStepSpeed = FISH_SPEED * ANGRY_FISH_SPEED_MULTIPLIER;
        }else{
            for(int xCounter = getX(); xCounter > (jellyfishCoords[0] + HEROES_SIZE); xCounter -= HALF_OF_CELL){
                if(GameFieldLayout::isCreatureInWall(xCounter, jellyfishCoords[1])){
                    return;
                }
            }
            newMoveDir(moveLeft);
            oneStepSpeed = FISH_SPEED * ANGRY_FISH_SPEED_MULTIPLIER;
        }
    }
}
