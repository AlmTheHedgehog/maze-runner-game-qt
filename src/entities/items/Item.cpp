#include "Item.h"

Item::Item(QWidget *parent, QPixmap imgPixmap, int xCell, int yCell): Entity(parent, imgPixmap, xCell, yCell){
}

Item::Item(const Item &oldItems):Entity(oldItems){
}

Item &Item::operator=(const Item& oldItem){
    Entity::operator=(oldItem);
    return *this;
}

bool Item::isCollision(Entity *collisionObject){
    if((getX() == collisionObject->getX()) && (getY() == collisionObject->getY())){
        return true;
    }
    return false;
}




// bool Item::isCollision(Entity *collisionObject){
    // if((getX() > (collisionObject->getX() + HALF_OF_CELL/2)) && 
    //     ((getX() + CELL_PIXEL_SIZE) < (collisionObject->getX() + HEROES_SIZE - HALF_OF_CELL/2))){
    //     if((getY() > (collisionObject->getY() + HALF_OF_CELL/2)) && 
    //     ((getY() + CELL_PIXEL_SIZE) < (collisionObject->getY() + HEROES_SIZE - HALF_OF_CELL/2))){
    //         return true;
    //     }
    // }
    // std::cout << std::endl << "X: " << getX() << " > " << (collisionObject->getX() + HALF_OF_CELL/2) << "&&"
    //             << getX() + CELL_PIXEL_SIZE << "<" << (collisionObject->getX() + HEROES_SIZE - HALF_OF_CELL/2) << std::endl;
    // std::cout << "Y: " << getY() << " > " << (collisionObject->getY() + HALF_OF_CELL/2) << "&&"
    //             << getY() + CELL_PIXEL_SIZE << "<" << (collisionObject->getY() + HEROES_SIZE - HALF_OF_CELL/2) << std::endl;
// }    