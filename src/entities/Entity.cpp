#include "Entity.h"

Entity::Entity(QWidget* parent, QPixmap imgPixmap, int xCell, int yCell):QLabel(parent),image(imgPixmap){
    setCell(xCell, yCell);
    setPixmap(image);
}

void Entity::move(int dx, int dy)
{
    QPoint oldPosition = pos();
    QLabel::move(QPoint(oldPosition.x() + dx, oldPosition.y() + dy));
}

void Entity::setPosition(int x, int y){
    QLabel::move(x, y);
}

void Entity::setCell(int xCell, int yCell){
    QLabel::move(xCell * CELL_PIXEL_SIZE - HALF_OF_CELL, yCell * CELL_PIXEL_SIZE - HALF_OF_CELL);
}

int Entity::getX(){
    return pos().x();
}

int Entity::getY(){
    return pos().y();
}

void Entity::setImage(QPixmap imgPixmap){
    image = imgPixmap;
    setPixmap(image);
}