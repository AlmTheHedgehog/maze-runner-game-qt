#pragma once
#include "Creature.h"
#include "GlobalVars.h"
#include <QKeyEvent>

class Pacman : public Creature{
    Q_OBJECT
    public:
        Pacman(QWidget* parent, int xCell = 0, int yCell = 0);
        void keyPressProcessing(QKeyEvent *event);

    protected:
        void preActiononTick() override;
        void newMoveDir(MoveDirection newDir);

};