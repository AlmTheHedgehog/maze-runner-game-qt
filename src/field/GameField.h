#pragma once
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <memory>
#include <vector>
#include "Jellyfish.h"
#include "GlobalVars.h"
#include "Plant.h"
#include "Plankton.h"

class GameField : public QWidget {
    Q_OBJECT
    public:
        const short int HEIGHT_IN_CELLS, WIDTH_IN_CELLS;
        const int WIDTH_PX, HEIGHT_PX;
        
        GameField(short int heightInCells, short int widthInCells);
        ~GameField();

    public slots:
        void checkJellyfishCollision();  //TODO connect to wasMoved signal of Jellyfish. Use EachColactable.isCollision(). If it returns true, then delete item from items array and make an action(add points / eat ghosts).


    private:
        QLabel backGroundPicture;
        QTimer gameTimer;
        Jellyfish *mainHero;
        std::vector<Item> items;

        void initBackGroundPicture();
        void initField();
        void initHeroes();
        void keyPressEvent(QKeyEvent *event);

};

/*
to add more src files, you need add directouries in pacman-qt.pro file. in SOURCES and HEADERS
*/