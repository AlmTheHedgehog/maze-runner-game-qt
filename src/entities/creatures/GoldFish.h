#pragma once
#include "Fish.h"

// TRY TO STAY FAR AWAY FROM JELLYFISH
class GoldFish : public Fish{
    Q_OBJECT
    public:
        GoldFish(QWidget* parent, int xCell, int yCell);

    protected:
        void calcMovement();
};