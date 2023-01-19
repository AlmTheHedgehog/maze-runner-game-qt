#include "Pacman.h"

Pacman::Pacman(QWidget* parent, int xCell, int yCell):
                Creature(parent, QPixmap(":/creatures/Pacman_ball.png"), PACMAN_SPEED, xCell, yCell){
    curMove = moveRight;
    setSpeedVector(PACMAN_SPEED, 0);
    nextMove = noMove;
}

void Pacman::keyPressProcessing(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Up:
            newMoveDir(moveUp);
            break;
        case Qt::Key_Down:
            newMoveDir(moveDown);
            break;
        case Qt::Key_Left:
            newMoveDir(moveLeft);
            break;
        case Qt::Key_Right:
            newMoveDir(moveRight);
            break;
    }
}

void Pacman::preActiononTick(){
    
}

void Pacman::newMoveDir(MoveDirection newDir){
    if(curMove == noMove){
        curMove = newDir;
        setSpeedVector(curMove);
    }else{
        nextMove = newDir;
    }
}
