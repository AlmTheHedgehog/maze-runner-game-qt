#pragma once
#include "Entity.h"

class Creature : public Entity{
    Q_OBJECT
    public:
        Creature(QWidget* parent, QPixmap imgPixmap, int xCell = 0, int yCell = 0);

    public slots:
        void onTick();  //TODO implement virtual method in each non-abstract class

    protected:
        enum moveDirection{moveLeft, moveRight, moveUp, moveDown, noMove};
        moveDirection curMove, nextMove;  //TODO Where pacman/ghost will go next. If it`s a wall before, than crear both moves. Better to make them enums
        
        virtual void preActiononTick() = 0;
};