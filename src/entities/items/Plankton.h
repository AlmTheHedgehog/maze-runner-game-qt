#pragma once
#include "Item.h"

class Plankton : public Item{
    Q_OBJECT
    public:
        Plankton(QWidget* parent, int xCell = 0, int yCell = 0);
        Plankton(const Plankton& oldPlankton);
        Plankton& operator=(const Plankton& oldPlankton);
};