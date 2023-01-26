#pragma once
#include "Creature.h"
#include "GlobalVars.h"
#include <QKeyEvent>

class Jellyfish : public Creature{
    Q_OBJECT
    public:
        Jellyfish(QWidget* parent, int xCell = 0, int yCell = 0);
        void makeScary();
        void makeNotScary();
        void keyPressProcessing(QKeyEvent *event);

    public slots:
        void checkCollisionWithFish(int xFish, int yFish);
    signals:
        void jellyfishMoved();
        void checkCollisionWithJellyFish(int xJellyFish, int yJellyFish);
        void updateJellyfishCoords(int xJellyFish, int yJellyFish);
        void endGame();

    protected:
        void preMoveActiononOnTick() override;
    
    private:
        bool isScary;
        void changeMoveImg(MoveDirection curMove) override;
};