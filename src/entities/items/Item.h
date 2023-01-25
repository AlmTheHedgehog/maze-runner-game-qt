#pragma once
#include "Entity.h"

class Item : public Entity{
    Q_OBJECT
    public:
        const int pointsCost;
        const bool isWithSuperPower;

        Item(QWidget *parent, QPixmap imgPixmap, int scoreCostGain, bool haveSuperPower, int xCell, int yCell);
        Item(const Item& oldItems);
        Item& operator=(const Item& oldItems);
        bool isCollision(Entity* collisionObject);
};