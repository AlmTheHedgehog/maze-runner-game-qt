#include "RedFish.h"

RedFish::RedFish(QWidget *parent, int xCell, int yCell):
                Fish(parent, xCell, yCell, 
                ":/creatures/fish/red/fish_red_up.png", 
                ":/creatures/fish/red/fish_red_down.png", 
                ":/creatures/fish/red/fish_red_left.png", 
                ":/creatures/fish/red/fish_red_right.png") {
    
}

void RedFish::calcMovement(){
    if(curMove == noMove){
        newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
    }
}
