#include "Plankton.h"

Plankton::Plankton(QWidget *parent, int xCell, int yCell):Item(parent, QPixmap(":/collectableItems/Plankton.png"), xCell, yCell){
}

Plankton::Plankton(const Plankton &oldPlankton):Item(oldPlankton){
}

Plankton &Plankton::operator=(const Plankton &oldPlankton){
    Item::operator=(oldPlankton);
    return *this;
}
