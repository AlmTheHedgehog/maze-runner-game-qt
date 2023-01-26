#include "Fish.h"

Fish::Fish(QWidget *parent, int xCell, int yCell, QString up_File, 
        QString down_File,QString left_File, QString right_File):
            Creature(parent, QPixmap(":/creatures/fish/grey/fish_grey_left.png"), 
            FISH_SPEED, xCell, yCell, ":/creatures/fish/grey/fish_grey_left.png", 
            up_File, down_File, left_File, right_File){
    isScared = false;
    wasEaten = false;
    setImage(sprites.right_Img);
    sprites.curImg = sprites.Right;
    curMove = noMove;
    nextMove = noMove;
    jellyfishCoords[0] = 0;
    jellyfishCoords[1] = 0;
}

void Fish::makeScared(){
    isScared = true;
    oneStepSpeed = FISH_SPEED;
}

void Fish::makeNotScared(){
    isScared = false;
}

void Fish::updateJellyfishCoords(int xJellyFish, int yJellyFish){
    jellyfishCoords[0] = xJellyFish;
    jellyfishCoords[1] = yJellyFish;
}

void Fish::changeMoveImg(MoveDirection curMove){
    switch(curMove){
        case moveUp:
            if(isScared){
                setImage(grayFishSprites.up_Img);
            }else{
                setImage(sprites.up_Img);
            }
            sprites.curImg = sprites.Up;
            break;
        case moveDown:
            if(isScared){
                setImage(grayFishSprites.down_Img);
            }else{
                setImage(sprites.down_Img);
            }
            sprites.curImg = sprites.Down;
            break;
        case moveLeft:
            if(isScared){
                setImage(grayFishSprites.left_Img);
            }else{
                setImage(sprites.left_Img);
            }
            sprites.curImg = sprites.Left;
            break;
        case moveRight:
            if(isScared){
                setImage(grayFishSprites.right_Img);
            }else{
                setImage(sprites.right_Img);
            }
            sprites.curImg = sprites.Right;
            break;
        case noMove:
            break;
    }
}

void Fish::preMoveActiononOnTick(){
    if((curMove != noMove) && (!isScared)){
        emit checkCollisionWithFish(getX(), getY());
    }
    changeMoveImg(curMove);
    if(isScared){
        runFromJellyfish();
    }else{
        calcMovement();
    }
}

void Fish::runFromJellyfish(CatchDirection dirModifire){
    // if(isFreeSpaceNear()){
    if(curMove == noMove){
        jellyfishVector.setVector(jellyfishCoords[0] - getX(), jellyfishCoords[1] - getY());
        if(std::abs(jellyfishVector.x) == std::abs(jellyfishVector.y)){
            newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
        }else if(std::abs(jellyfishVector.x) < std::abs(jellyfishVector.y)){
            escapeOnX(dirModifire);
        }else{
            escapeOnY(dirModifire);
        }
    }
}

void Fish::escapeOnX(CatchDirection dirModifire){
    if(jellyfishVector.x == 0){
        if(curMove == noMove){
            if(jellyfishVector.y > 0){
                if(!isNextPixelCellWall(static_cast<MoveDirection>(moveUp + dirModifire))){
                    newMoveDir(static_cast<MoveDirection>(moveUp + dirModifire));
                    return;
                }
            }else{
                if(!isNextPixelCellWall(static_cast<MoveDirection>(moveDown - dirModifire))){
                    newMoveDir(static_cast<MoveDirection>(moveDown - dirModifire));
                    return;
                }
            }
            newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(2, 4)));
        }
        return;
    }else if(jellyfishVector.x > 0){
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveLeft + dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveLeft + dirModifire));
            return;
        }
    }else{
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveRight - dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveRight - dirModifire));
            return;
        }
    }
    if(jellyfishVector.y >= 0){
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveUp + dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveUp + dirModifire));
        }else{
            if(!isNextPixelCellWall(static_cast<MoveDirection>(moveDown - dirModifire))){
                newMoveDir(static_cast<MoveDirection>(moveDown - dirModifire));
            }else{
                newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
            }
        }
    }else{
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveDown - dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveDown - dirModifire));
        }else{
            if(!isNextPixelCellWall(static_cast<MoveDirection>(moveUp + dirModifire))){
                newMoveDir(static_cast<MoveDirection>(moveUp + dirModifire));
            }else{
                newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
            }
        }
    }
}

void Fish::escapeOnY(CatchDirection dirModifire){
    if(jellyfishVector.y == 0){
        if(curMove == noMove){
            if(jellyfishVector.x > 0){
                if(!isNextPixelCellWall(static_cast<MoveDirection>(moveLeft + dirModifire))){
                    newMoveDir(static_cast<MoveDirection>(moveLeft + dirModifire));
                    return;
                }
            }else{
                if(!isNextPixelCellWall(static_cast<MoveDirection>(moveRight - dirModifire))){
                    newMoveDir(static_cast<MoveDirection>(moveRight - dirModifire));
                    return;
                }
            }
            newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(2, 4)));
        }
        return;
    }else if(jellyfishVector.y > 0){
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveUp + dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveUp + dirModifire));
            return;
        }
    }else{
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveDown - dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveDown - dirModifire));
            return;
        }
    }
    if(jellyfishVector.x >= 0){
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveLeft + dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveLeft + dirModifire));
        }else{
            if(!isNextPixelCellWall(static_cast<MoveDirection>(moveRight - dirModifire))){
                newMoveDir(static_cast<MoveDirection>(moveRight - dirModifire));
            }else{
                newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
            }
        }
    }else{
        if(!isNextPixelCellWall(static_cast<MoveDirection>(moveRight - dirModifire))){
            newMoveDir(static_cast<MoveDirection>(moveRight - dirModifire));
        }else{
            if(!isNextPixelCellWall(static_cast<MoveDirection>(moveLeft + dirModifire))){
                newMoveDir(static_cast<MoveDirection>(moveLeft + dirModifire));
            }else{
                newMoveDir(static_cast<MoveDirection>(QRandomGenerator::global()->bounded(0, 4)));
            }
        }
    }
}

bool Fish::isFreeSpaceNear(){
    if((curMove != moveUp) && (!isNextPixelCellWall(moveUp))){
        return true;
    }
    if((curMove != moveDown) && (!isNextPixelCellWall(moveDown))){
        return true;
    }
    if((curMove != moveLeft) && (!isNextPixelCellWall(moveLeft))){
        return true;
    }
    if((curMove != moveRight) && (!isNextPixelCellWall(moveRight))){
        return true;
    }
    if(curMove == noMove){
        return true;
    }
    return false;
}

void Fish::checkCollisionWithJellyFish(int xJellyFish, int yJellyFish){
    //TODO wait during scared. if thue then delete this fish
}

Fish::GreySpritesContainer::GreySpritesContainer(): up_Img(QPixmap(":/creatures/fish/grey/fish_grey_up.png")), 
                                                    down_Img(QPixmap(":/creatures/fish/grey/fish_grey_down.png")),
                                                    left_Img(QPixmap(":/creatures/fish/grey/fish_grey_left.png")), 
                                                    right_Img(QPixmap(":/creatures/fish/grey/fish_grey_right.png")){
}

Fish::Vector::Vector(int x, int y): x(x), y(y){
}

void Fish::Vector::setVector(int x, int y){
    this->x=x;
    this->y=y;
}
