#include "Creature.h"

Creature::Creature(QWidget* parent, QPixmap imgPixmap, int oneStepSpeed, int xCell, int yCell):
                    Entity(parent, imgPixmap, xCell, yCell), oneStepSpeed(oneStepSpeed){
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

void Creature::onTick(){
    preActiononTick();

    if(!isNextPixelCellWall(nextMove)){
        curMove = nextMove;
        nextMove = noMove;
        setSpeedVector(curMove);
    }else if(isNextPixelCellWall(curMove)){
        curMove = noMove;
        setSpeedVector(0, 0);
    }
    
    if(getX() < -HEROES_SIZE ){
        setPosition(CELL_PIXEL_SIZE*FIELD_WIDTH_CELLS+HEROES_SIZE, getY());
    }else if(getX() > CELL_PIXEL_SIZE*FIELD_WIDTH_CELLS+HEROES_SIZE){
        setPosition(-HEROES_SIZE, getY());
    }

    move(xSpeed, ySpeed);  //if curMove == noMove than vector is 0 and we are busy-waiting(probably use condition var)
}