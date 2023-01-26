#include "Creature.h"

Creature::Creature(QWidget* parent, QPixmap imgPixmap, int oneStepSpeed, int xCell, int yCell, QString ballFile, 
                QString up_File, QString down_File,QString left_File, QString right_File, int imgChangeCounterLimit):
                    Entity(parent, imgPixmap, xCell, yCell), oneStepSpeed(oneStepSpeed), 
                    sprites(ballFile, up_File, down_File, left_File, right_File, imgChangeCounterLimit){
}

void Creature::setSpeedVector(int newXSpeed, int newYSpeed){
    xSpeed = newXSpeed;
    ySpeed = newYSpeed;
}

void Creature::setSpeedVector(MoveDirection moveDirToSet){
    switch(moveDirToSet){
        case moveUp:
            setSpeedVector(0, -oneStepSpeed);
            break;
        case moveDown:
            setSpeedVector(0, oneStepSpeed);
            break;
        case moveLeft:
            setSpeedVector(-oneStepSpeed, 0);
            break;
        case moveRight:
            setSpeedVector(oneStepSpeed, 0);
            break;
        case noMove:
            setSpeedVector(0, 0);
            break;
    }
}

bool Creature::isNextPixelCellWall(MoveDirection moveDirToCheck){
    switch(moveDirToCheck){
        case moveUp:
            return GameFieldLayout::isCreatureInWall(getX(), getY() - oneStepSpeed);
        case moveDown:
            return GameFieldLayout::isCreatureInWall(getX(), getY() + oneStepSpeed);
        case moveLeft:
            return GameFieldLayout::isCreatureInWall(getX() - oneStepSpeed, getY());
        case moveRight:
            return GameFieldLayout::isCreatureInWall(getX() + oneStepSpeed, getY());
        case noMove:
            return true;
        default:
            return false;
    }
}

void Creature::newMoveDir(MoveDirection newDir){
    if(curMove == noMove){
        curMove = newDir;
        setSpeedVector(curMove);
    }else{
        nextMove = newDir;
    }
}

void Creature::onTick(){
    preMoveActiononOnTick();

    if(!isNextPixelCellWall(nextMove)){
        curMove = nextMove;
        nextMove = noMove;
        setSpeedVector(curMove);
        changeMoveImg(curMove);
    }else if(isNextPixelCellWall(curMove)){
        curMove = noMove;
        setSpeedVector(0, 0);
    }
    if(curMove != noMove){
        move(xSpeed, ySpeed);
    }
    
    if(getX() < -HEROES_SIZE ){
        setPosition(CELL_PIXEL_SIZE*FIELD_WIDTH_CELLS+HEROES_SIZE, getY());
    }else if(getX() > CELL_PIXEL_SIZE*FIELD_WIDTH_CELLS+HEROES_SIZE){
        setPosition(-HEROES_SIZE, getY());
    }
}

Creature::SpritesContainer::SpritesContainer(QString ballFile, QString up_File, QString down_File, 
                        QString left_File, QString right_File, int imgChangeCounterLimit):
                        ballImg(ballFile), up_Img(up_File), down_Img(down_File), 
                        left_Img(left_File), right_Img(right_File), 
                        IMG_CHANGE_COUNTER_LIMIT(imgChangeCounterLimit){
    imgChangeCounter = 0;
};