#pragma once
#include "Fish.h"

// RANDOM FISH
class RedFish : public Fish{
    Q_OBJECT
    public:
        RedFish(QWidget* parent, int xCell, int yCell);

    protected:
        void calcMovement();
};