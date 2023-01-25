#pragma once
#include <QLabel>
#include "GlobalVars.h"

const int HALF_OF_CELL = CELL_PIXEL_SIZE / 2;

class Entity : public QLabel{
    Q_OBJECT
    public:
        Entity(QWidget* parent, QPixmap imgPixmap, int xCell = 0, int yCell = 0);
        Entity(const Entity& oldEnt);
        Entity& operator=(const Entity& oldEnt);
        void move(int dx, int dy);
        void setPosition(int x, int y);
        void setCell(int xCell, int yCell);
        int getX() const;
        int getY() const;
        
    protected:
        void setImage(QPixmap imgPixmap);

    private:
        QPixmap image;
};