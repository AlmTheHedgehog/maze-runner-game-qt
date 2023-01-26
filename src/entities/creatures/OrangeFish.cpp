#include "OrangeFish.h"

OrangeFish::OrangeFish(QWidget *parent, int xCell, int yCell):
                Fish(parent, xCell, yCell, 
                ":/creatures/fish/orange/fish_orange_up.png", 
                ":/creatures/fish/orange/fish_orange_down.png", 
                ":/creatures/fish/orange/fish_orange_left.png", 
                ":/creatures/fish/orange/fish_orange_right.png") {
    
}

void OrangeFish::calcMovement(){
    runFromJellyfish(Fish::toJellyfish);
}
