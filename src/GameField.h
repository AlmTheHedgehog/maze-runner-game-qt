#pragma once

#include <QWidget>
#include <QLabel>

#define CELL_PIXEL_SIZE 16

class GameField : public QWidget {
    Q_OBJECT
    public:
        const short int HEIGHT_IN_CELLS, WIDTH_IN_CELLS;
        const int WIDTH_PX, HEIGHT_PX;
        
        GameField(short int heightInCells, short int widthInCells, QWidget* parent = 0);

    private:
        QWidget gameWindow;
        QLabel backGroundPicture;

        void initBackGroundPicture();

};