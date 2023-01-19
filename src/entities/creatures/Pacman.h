#pragma once
#include "Creature.h"
#include "GlobalVars.h"

class Pacman : public Creature{
    Q_OBJECT
    public:
        Pacman(QWidget* parent, int xCell = 0, int yCell = 0);
        void onTick();
    private:
        int xSpeed;

};