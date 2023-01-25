#include "Plankton.h"

Plankton::Plankton(QWidget *parent, int xCell, int yCell):
                    Item(parent, QPixmap(":/collectableItems/Plankton.png"), SCORE_FOR_PLANKTON, true, xCell, yCell){
}

Plankton::Plankton(const Plankton &oldPlankton):Item(oldPlankton){
}

Plankton &Plankton::operator=(const Plankton &oldPlankton){
    Item::operator=(oldPlankton);
    return *this;
}
