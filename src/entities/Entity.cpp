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
    QLabel::move(x - HALF_OF_CELL, y - HALF_OF_CELL);
}

void Entity::setCell(int xCell, int yCell){
    QLabel::move(xCell * CELL_PIXEL_SIZE - HALF_OF_CELL, yCell * CELL_PIXEL_SIZE - HALF_OF_CELL);
}

int Entity::getCellX(){
    return (pos().x() + 1 + HALF_OF_CELL) / CELL_PIXEL_SIZE;
}

int Entity::getCellY(){
    return (pos().y() + 1 + HALF_OF_CELL) / CELL_PIXEL_SIZE;
}

int Entity::getX(){
    return pos().x() + HALF_OF_CELL;
}

int Entity::getY(){
    return pos().y() + HALF_OF_CELL;
}

void Entity::setImage(QPixmap imgPixmap){
    image = imgPixmap;
    setPixmap(image);
}