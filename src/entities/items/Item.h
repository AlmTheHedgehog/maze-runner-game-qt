#pragma once
#include "Entity.h"

class Item : public Entity{
    Q_OBJECT
    public:
        Item(QWidget* parent, QPixmap imgPixmap, int xCell, int yCell);
        Item(const Item& oldItems);
        Item& operator=(const Item& oldItems);
        bool isCollision(Entity* collisionObject);
};