#include "GameField.h"

GameField::GameField(short int heightInCells, short int widthInCells):
                    HEIGHT_IN_CELLS(heightInCells), WIDTH_IN_CELLS(widthInCells),
                    WIDTH_PX(widthInCells * CELL_PIXEL_SIZE), HEIGHT_PX(heightInCells * CELL_PIXEL_SIZE){
    gameWindow.setFixedSize(WIDTH_PX, HEIGHT_PX);
    initBackGroundPicture();
    initPacman();
    

    gameWindow.show();
}

GameField::~GameField(){
    delete mPacman;
}

void GameField::initBackGroundPicture(){
    QPixmap pixmap(":/field/map-cell16px.png");
    backGroundPicture.setPixmap(pixmap);
    backGroundPicture.setParent(&gameWindow);
}

void GameField::initPacman(){
    mPacman = new Pacman(&gameWindow, 2, 4);
    connect(&gameTimer, &QTimer::timeout, mPacman, &Pacman::onTick);
    gameTimer.start(30);
}
