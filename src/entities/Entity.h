#pragma once
#include <QLabel>
#include "GlobalVars.h"

const int HALF_OF_CELL = CELL_PIXEL_SIZE / 2;

class Entity : public QLabel{
    Q_OBJECT
    public:
        Entity(QWidget* parent, QPixmap imgPixmap, int xCell = 0, int yCell = 0);
        void move(int dx, int dy);
        void setPosition(int x, int y);
        void setCell(int xCell, int yCell);
        int getCellX();
        int getCellY();
        int getX();
        int getY();
        
    protected:
        void setImage(QPixmap imgPixmap);

    private:
        QPixmap image;
};