#pragma once
#include "Fish.h"

// TRY TO CATCH JELLYFISH IF SEE IT
class GreenFish : public Fish{
    Q_OBJECT
    public:
        GreenFish(QWidget* parent, int xCell, int yCell);

    protected:
        void calcMovement();
};