#include "GameField.h"

GameField::GameField(short int heightInCells, short int widthInCells):
                    HEIGHT_IN_CELLS(heightInCells), WIDTH_IN_CELLS(widthInCells),
                    WIDTH_PX(widthInCells * CELL_PIXEL_SIZE), HEIGHT_PX(heightInCells * CELL_PIXEL_SIZE){
    setFixedSize(WIDTH_PX, HEIGHT_PX);
    initBackGroundPicture();
    initField();
    initHeroes();

    show();
}

GameField::~GameField(){
    delete mainHero;
}

void GameField::initBackGroundPicture(){
    QPixmap pixmap(":/field/map-cell16px.png");
    backGroundPicture.setPixmap(pixmap);
    backGroundPicture.setParent(this);
}

void GameField::initField(){
    int jellyfishCoord[2];
    for(int y = 0; y < FIELD_HEIGHT_CELLS; y++){
        for(int x = 0; x < FIELD_WIDTH_CELLS; x++){
            switch(GameFieldLayout::getCellType(x, y)){
                case GameFieldLayout::plantCell:
                    items.push_back(Plant(this, x, y));
                    break;
                case GameFieldLayout::planktonCell:
                    items.push_back(Plankton(this, x, y));
                    break;
                case GameFieldLayout::jellyfishCell:
                    jellyfishCoord[0] = x;
                    jellyfishCoord[1] = y;
                    break;
            }
        }
    }
    mainHero = new Jellyfish(this, jellyfishCoord[0], jellyfishCoord[1]);
}

void GameField::initHeroes(){
    connect(&gameTimer, &QTimer::timeout, mainHero, &Jellyfish::onTick);
    connect(mainHero, &Jellyfish::jellyfishMoved, this, &GameField::checkJellyfishCollision);
    gameTimer.start(1000/FPS);
}

void GameField::keyPressEvent(QKeyEvent *event){
    mainHero->keyPressProcessing(event);
}

void GameField::checkJellyfishCollision(){
    for(auto element = items.begin(); element!=items.end(); ++element){
        if((*element).isCollision(mainHero)){
            items.erase(element);
            // TODO give point / ability to eat fish
            //in distructor plant and plakton have to emit signal plantEaten()||planktonEaten(). Connect points counter to both and GamaField to planktonEaten() to let jellyfish eat fish
            return;
        }
    }
}
