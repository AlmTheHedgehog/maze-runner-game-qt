#pragma once
#include "Creature.h"
#include "GlobalVars.h"
#include <QKeyEvent>

class Jellyfish : public Creature{
    Q_OBJECT
    public:
        Jellyfish(QWidget* parent, int xCell = 0, int yCell = 0);
        void keyPressProcessing(QKeyEvent *event);

    signals:
        void jellyfishMoved();

    protected:
        void preMoveActiononOnTick() override;
        void newMoveDir(MoveDirection newDir);
    
    private:
        void changeMoveImg(MoveDirection curMove) override;
};