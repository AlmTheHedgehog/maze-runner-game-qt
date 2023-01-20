#include "Pacman.h"

Pacman::Pacman(QWidget* parent, int xCell, int yCell):
                Creature(parent, QPixmap(":/creatures/Pacman_ball.png"), PACMAN_SPEED, xCell, yCell,
                ":/creatures/Pacman_ball.png", 
                ":/creatures/Pacman_up_normal.png", 
                ":/creatures/Pacman_down_normal.png",
                ":/creatures/Pacman_left_normal.png", 
                ":/creatures/Pacman_right_normal.png", 
                ((1000/PACMAN_IMAGE_CHANGE_PER_SECOND)/(1000/FPS))){
    setImage(sprites.right_Img);
    sprites.curImg = sprites.Right;
    curMove = moveRight;
    setSpeedVector(curMove);
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

void Pacman::preMoveActiononOnTick(){
    if(sprites.imgChangeCounter >= sprites.IMG_CHANGE_COUNTER_LIMIT){
        changeMoveImg(curMove);
    }else{
        sprites.imgChangeCounter++;
    }
}

void Pacman::newMoveDir(MoveDirection newDir){
    if(curMove == noMove){
        curMove = newDir;
        setSpeedVector(curMove);
    }else{
        nextMove = newDir;
    }
}

void Pacman::changeMoveImg(MoveDirection curMove){
    sprites.imgChangeCounter = 0;
    if(sprites.curImg != sprites.ball){
        sprites.curImg = sprites.ball;
        setImage(sprites.ballImg);
        return;
    }
    switch(curMove){
        case moveUp:
            setImage(sprites.up_Img);
            sprites.curImg = sprites.Up;
            break;
        case moveDown:
            setImage(sprites.down_Img);
            sprites.curImg = sprites.Down;
            break;
        case moveLeft:
            setImage(sprites.left_Img);
            sprites.curImg = sprites.Left;
            break;
        case moveRight:
            setImage(sprites.right_Img);
            sprites.curImg = sprites.Right;
            break;
        case noMove:
            break;
    }
}
