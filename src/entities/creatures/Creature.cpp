#include "Creature.h"

Creature::Creature(QWidget* parent, QPixmap imgPixmap, int xCell, int yCell):Entity(parent, imgPixmap, xCell, yCell){
}

void Creature::onTick(){
    preActiononTick();
    switch(curMove){
        case moveRight:
            move(1, 0);
            break;
        case moveLeft:
            move(-1, 0);
            break;
        case moveUp:
            move(0, -1);
            break;
        case moveDown:
            move(0, 1);
            break;
        case noMove:
            break;
    }
    // move(xSpeed, ySpeed);
}