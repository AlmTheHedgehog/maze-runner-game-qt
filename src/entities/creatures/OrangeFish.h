#pragma once
#include "Fish.h"

// GO IN RIGHT DIRECTION
class OrangeFish : public Fish{
    Q_OBJECT
    public:
        OrangeFish(QWidget* parent, int xCell, int yCell);

    protected:
        void calcMovement();
};