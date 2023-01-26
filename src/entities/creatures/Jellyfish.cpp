#include "Jellyfish.h"

Jellyfish::Jellyfish(QWidget* parent, int xCell, int yCell):
                Creature(parent, QPixmap(":/creatures/jellyfish/Jellyfish_ball.png"), JELLYFISH_SPEED, xCell, yCell,
                ":/creatures/jellyfish/Jellyfish_ball.png", 
                ":/creatures/jellyfish/Jellyfish_up.png", 
                ":/creatures/jellyfish/Jellyfish_down.png",
                ":/creatures/jellyfish/Jellyfish_left.png", 
                ":/creatures/jellyfish/Jellyfish_right.png", 
                ((1000/JELLYFISH_IMAGE_CHANGE_PER_SECOND)/(1000/FPS))){
    isScary = false;
    setImage(sprites.right_Img);
    sprites.curImg = sprites.Right;
    curMove = moveRight;
    setSpeedVector(curMove);
    nextMove = noMove;
}

void Jellyfish::makeScary(){
    isScary = true;
}

void Jellyfish::makeNotScary(){
    isScary = false;
}

void Jellyfish::keyPressProcessing(QKeyEvent *event){
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

void Jellyfish::preMoveActiononOnTick(){
    if(sprites.imgChangeCounter >= sprites.IMG_CHANGE_COUNTER_LIMIT){
        changeMoveImg(curMove);
    }else{
        sprites.imgChangeCounter++;
    }
    if(curMove != noMove){
        emit jellyfishMoved();
        emit updateJellyfishCoords(getX(), getY());
        if(isScary){
            emit checkCollisionWithJellyFish(getX(), getY());
        }
    }
}

void Jellyfish::changeMoveImg(MoveDirection curMove){
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

void Jellyfish::checkCollisionWithFish(int xFish, int yFish){
    //TODO wait during notScared Fish. if true then defeat
}
