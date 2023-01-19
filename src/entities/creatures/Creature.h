#pragma once
#include "Entity.h"
#include "GameFieldLayout.h"

class Creature : public Entity{
    Q_OBJECT
    public:
        Creature(QWidget* parent, QPixmap imgPixmap, int oneStepSpeed, int xCell = 0, int yCell = 0);
        void setSpeedVector(int newXSpeed, int newYSpeed);
        
        
    public slots:
        void onTick();  //TODO implement virtual method in each non-abstract class


    protected:
        int xSpeed, ySpeed, oneStepSpeed;
        enum MoveDirection{moveLeft, moveRight, moveUp, moveDown, noMove};
        MoveDirection curMove, nextMove;  //TODO Where pacman/ghost will go next. If it`s a wall before, than crear both moves. Better to make them enums
        
        void setSpeedVector(MoveDirection moveDirToSet);
        virtual void preActiononTick() = 0;
        bool isNextPixelCellWall(MoveDirection moveDirToCheck);

};