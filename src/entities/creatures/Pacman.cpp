#include "Pacman.h"
#include <iostream>

Pacman::Pacman(QWidget* parent, int xCell, int yCell):Creature(parent, QPixmap(":/creatures/Pacman_ball.png"), xCell, yCell){
    xSpeed = PACMAN_SPEED;
}

void Pacman::onTick(){
    if(getCellX() > FIELD_WIDTH_CELLS - 1){
        xSpeed = -PACMAN_SPEED;
    }
    if(getCellX() < 0){
        xSpeed = PACMAN_SPEED;
    }
    move(xSpeed, 0);
}
