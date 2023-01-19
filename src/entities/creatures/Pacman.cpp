#include "Pacman.h"

Pacman::Pacman(QWidget* parent, int xCell, int yCell):Creature(parent, QPixmap(":/creatures/Pacman_ball.png"), xCell, yCell){
    xSpeed = PACMAN_SPEED;
    ySpeed = 0;
    curMove = moveRight;
    nextMove = noMove;
}

void Pacman::keyPressProcessing(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            curMove = moveUp;
            break;
        case Qt::Key_Down:
            curMove = moveDown;
            break;
        case Qt::Key_Left:
            curMove = moveLeft;
            break;
        case Qt::Key_Right:
            curMove = moveRight;
            break;
    }
}

void Pacman::preActiononTick(){
    
}
