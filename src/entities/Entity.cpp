#include "Entity.h"

Entity::Entity(QWidget* parent, QPixmap imgPixmap, int xCell, int yCell):QLabel(parent),image(imgPixmap){
    setCell(xCell, yCell);
    setPixmap(image);
}

Entity::Entity(const Entity &oldEnt):QLabel(oldEnt.parentWidget()),image(oldEnt.image){
    setPosition(oldEnt.getX(), oldEnt.getY());
    setPixmap(image);
}

Entity &Entity::operator=(const Entity& oldEnt){
    image = oldEnt.image;
    setImage(image);
    setPosition(oldEnt.getX(), oldEnt.getY());
    return *this;
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

int Entity::getX() const{
    return pos().x();
}

int Entity::getY() const{
    return pos().y();
}

void Entity::setImage(QPixmap imgPixmap){
    image = imgPixmap;
    setPixmap(image);
}