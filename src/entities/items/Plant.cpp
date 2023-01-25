#include "Plant.h"

Plant::Plant(QWidget *parent, int xCell, int yCell):
            Item(parent, QPixmap(":/collectableItems/Plant.png"), SCORE_FOR_PLANT, false, xCell, yCell){
}

Plant::Plant(const Plant &oldPlant):Item(oldPlant){
}

Plant &Plant::operator=(const Plant &oldPlant){
    Item::operator=(oldPlant);
    return *this;
}
