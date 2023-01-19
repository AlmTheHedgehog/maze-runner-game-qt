#pragma once
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <memory>
#include "Pacman.h"
#include "GlobalVars.h"

class GameField : public QWidget {
    Q_OBJECT
    public:
        const short int HEIGHT_IN_CELLS, WIDTH_IN_CELLS;
        const int WIDTH_PX, HEIGHT_PX;
        
        GameField(short int heightInCells, short int widthInCells);
        ~GameField();

    private:
        QWidget gameWindow;
        QLabel backGroundPicture;
        QTimer gameTimer;
        Pacman *mPacman;
        

        void initBackGroundPicture();
        void initPacman();

};

/*
to add more src files, you need add directouries in pacman-qt.pro file. in SOURCES and HEADERS
*/