#pragma once
#include "Entity.h"
#include "GameFieldLayout.h"

class Creature : public Entity{
    Q_OBJECT
    public:
        Creature(QWidget* parent, QPixmap imgPixmap, int oneStepSpeed, int xCell, int yCell, QString ballFile, 
                QString up_File, QString down_File,QString left_File, QString right_File, int imgChangeCounterLimit = 0);
        void setSpeedVector(int newXSpeed, int newYSpeed);
        
        
    public slots:
        void onTick();  //TODO implement virtual method in each non-abstract class


    protected:
        int xSpeed, ySpeed, oneStepSpeed;
        enum MoveDirection{moveLeft = 0, moveRight = 1, moveUp = 2, moveDown = 3, noMove = 4};
        MoveDirection curMove, nextMove;

        class SpritesContainer{
            public:
                QPixmap ballImg, up_Img, down_Img, left_Img, right_Img;
                const int IMG_CHANGE_COUNTER_LIMIT;
                int imgChangeCounter;
                enum ImgName{ball, Left, Right, Up, Down};
                ImgName curImg;
                SpritesContainer(QString ballFile, QString up_File, QString down_File, 
                                QString left_File, QString right_File, int imgChangeCounterLimit);
        };
        SpritesContainer sprites;

        void setSpeedVector(MoveDirection moveDirToSet);
        void newMoveDir(MoveDirection newDir);
        virtual void preMoveActiononOnTick() = 0;
        virtual void changeMoveImg(MoveDirection curMove) = 0;
        bool isNextPixelCellWall(MoveDirection moveDirToCheck);

};