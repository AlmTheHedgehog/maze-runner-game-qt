#pragma once
#include <cmath>
#include <QRandomGenerator>
#include "Creature.h"

class Fish : public Creature{
    Q_OBJECT
    public:
        bool wasEaten;
        Fish(QWidget* parent, int xCell, int yCell, QString up_File, 
            QString down_File,QString left_File, QString right_File);
        void makeScared();
        void makeNotScared();

    public slots:
        void checkCollisionWithJellyFish(int xJellyFish, int yJellyFish);
        void updateJellyfishCoords(int xJellyFish, int yJellyFish);
    signals:
        void checkCollisionWithFish(int xFish, int yFish);
        void wasJellyfishAteFish(); // emits in this slot checkCollisionWithJellyFish(int xJellyFish, int yJellyFish);

    protected:
        struct GreySpritesContainer{
                const QPixmap up_Img, down_Img, left_Img, right_Img;
                GreySpritesContainer();
        } grayFishSprites;
        class Vector{
            public:
                int x, y;
                Vector(int x = 0, int y = 0);
                void setVector(int x, int y);
        };
        enum CatchDirection{fromJellyfish = 0, toJellyfish = 1};

        bool isScared;
        int jellyfishCoords[2];
        Vector jellyfishVector;

        void changeMoveImg(MoveDirection curMove);
        virtual void calcMovement() = 0;
        void runFromJellyfish(CatchDirection dirModifire = fromJellyfish);  
        void escapeOnX(CatchDirection dirModifire = fromJellyfish);
        void escapeOnY(CatchDirection dirModifire = fromJellyfish);
        bool isFreeSpaceNear();
        void preMoveActiononOnTick();
};