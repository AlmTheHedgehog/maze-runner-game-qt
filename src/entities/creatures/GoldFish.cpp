#include "GoldFish.h"

GoldFish::GoldFish(QWidget *parent, int xCell, int yCell):
                Fish(parent, xCell, yCell, 
                ":/creatures/fish/gold/fish_gold_up.png", 
                ":/creatures/fish/gold/fish_gold_down.png", 
                ":/creatures/fish/gold/fish_gold_left.png", 
                ":/creatures/fish/gold/fish_gold_right.png") {
    
}

void GoldFish::calcMovement(){
    runFromJellyfish();
}
