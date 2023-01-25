#pragma once
#include "Item.h"

class Plant : public Item{
    Q_OBJECT
    public:
        Plant(QWidget* parent, int xCell = 0, int yCell = 0);
        Plant(const Plant& oldPlant);
        Plant& operator=(const Plant& oldPlant);
};