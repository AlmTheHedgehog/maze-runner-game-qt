#include "GameField.h"
#include <iostream>

GameField::GameField(short int heightInCells, short int widthInCells):
                    HEIGHT_IN_CELLS(heightInCells), WIDTH_IN_CELLS(widthInCells),
                    WIDTH_PX(widthInCells * CELL_PIXEL_SIZE), HEIGHT_PX(heightInCells * CELL_PIXEL_SIZE){
    setFixedSize(WIDTH_PX, HEIGHT_PX);
    initBackGroundPicture();
    initField();
    initHeroes();
    initFinalScore();

    show();
}

GameField::~GameField(){
    delete mainHero;
    delete scoreCounter;
    delete blackBackGround;
    delete bigScore;
}

void GameField::initBackGroundPicture(){
    QPixmap pixmap(":/field/map-cell16px.png");
    backGroundPicture.setPixmap(pixmap);
    backGroundPicture.setParent(this);
}

void GameField::initField(){
    int jellyfishCoord[2], 
        fishCoords[NUMBER_OF_FISH][2], 
        index = 0;
    for(int y = 0; y < FIELD_HEIGHT_CELLS; y++){
        for(int x = 0; x < FIELD_WIDTH_CELLS; x++){
            switch(GameFieldLayout::getCellType(x, y)){
                case GameFieldLayout::plantCell:
                    itemsPtrs.push_back(std::make_unique<Plant>(this, x, y));
                    break;
                case GameFieldLayout::planktonCell:
                    itemsPtrs.push_back(std::make_unique<Plankton>(this, x, y));
                    break;
                case GameFieldLayout::jellyfishCell:
                    jellyfishCoord[0] = x;
                    jellyfishCoord[1] = y;
                    break;
                case GameFieldLayout::fishCell:
                    fishCoords[index][0] = x; 
                    fishCoords[index][1] = y;
                    index++;
                    break;
                case GameFieldLayout::scoreCell:
                    scoreCounter = new ScoreCounter(this, x, y);
                    break;
                default:
                    break;
            }
        }
    }
    mainHero = new Jellyfish(this, jellyfishCoord[0], jellyfishCoord[1]);
    fishPtrs.push_back(std::make_unique<RedFish>(this, fishCoords[0][0], fishCoords[0][1]));
    fishPtrs.push_back(std::make_unique<OrangeFish>(this, fishCoords[1][0], fishCoords[1][1]));
    fishPtrs.push_back(std::make_unique<GreenFish>(this, fishCoords[2][0], fishCoords[2][1]));
    fishPtrs.push_back(std::make_unique<GoldFish>(this, fishCoords[3][0], fishCoords[3][1]));
}

void GameField::initHeroes(){
    connect(&gameTimer, &QTimer::timeout, mainHero, &Jellyfish::onTick);
    connect(mainHero, &Jellyfish::jellyfishMoved, this, &GameField::checkJellyfishCollision);
    connect(mainHero, &Jellyfish::endGame, this, &GameField::endGame);

    for(auto element = fishPtrs.begin(); element!=fishPtrs.end(); ++element){
        connect(&gameTimer, &QTimer::timeout, (*element).get(), &Fish::onTick);
        connect(mainHero, &Jellyfish::checkCollisionWithJellyFish, (*element).get(), &Fish::checkCollisionWithJellyFish);
        connect((*element).get(), &Fish::checkCollisionWithFish, mainHero, &Jellyfish::checkCollisionWithFish);
        connect(mainHero, &Jellyfish::updateJellyfishCoords, (*element).get(), &Fish::updateJellyfishCoords);
        connect((*element).get(), &Fish::wasJellyfishAteFish, this, &GameField::fishWasEaten);
    }

    gameTimer.start(1000/FPS);
}

void GameField::initFinalScore(){
    blackBackGround = new QLabel(this);
    blackBackGround->move(0, 0);
    blackBackGround->setFixedSize(WIDTH_IN_CELLS * CELL_PIXEL_SIZE, HEIGHT_IN_CELLS * CELL_PIXEL_SIZE);
    bigScore = new QLabel(this);
    bigScore->move(CELL_PIXEL_SIZE * 2, HEIGHT_IN_CELLS * CELL_PIXEL_SIZE / 2);
    bigScore->setFixedSize(WIDTH_IN_CELLS * CELL_PIXEL_SIZE, CELL_PIXEL_SIZE * 2);
    bigScore->setFont(QFont("Liberation Serif", 25, QFont::Bold, true));
}

void GameField::keyPressEvent(QKeyEvent *event){
    mainHero->keyPressProcessing(event);
}

void GameField::giveJellyfishSuperPower(){
    mainHero->makeScary();
    for(auto element = fishPtrs.begin(); element!=fishPtrs.end(); ++element){
        (*element)->makeScared();
    }
    QTimer::singleShot(SCARY_TIME_SECONDS*1000, this, &GameField::takeJellyfishSuperPower);
}

void GameField::takeJellyfishSuperPower(){
    mainHero->makeNotScary();
    for(auto element = fishPtrs.begin(); element!=fishPtrs.end(); ++element){
        (*element)->makeNotScared();
    }
}

void GameField::fishWasEaten(){
    for(auto element = fishPtrs.begin(); element!=fishPtrs.end(); ++element){
        if((*element)->wasEaten){
            fishPtrs.erase(element);
            scoreCounter->addScore(SCORE_FOR_FISH);
            if(itemsPtrs.empty() && fishPtrs.empty()){
                endGame();
            }
            return;
        }
    }
}

void GameField::endGame(){
    gameTimer.stop();
    blackBackGround->setPixmap(QPixmap(":/field/map-cell16px_black.png"));
    bigScore->setText("Your score:" + QString::number(scoreCounter->getScore()));
}

void GameField::checkJellyfishCollision(){
    for(auto element = itemsPtrs.begin(); element!=itemsPtrs.end(); ++element){
        if((*element)->isCollision(mainHero)){
            scoreCounter->addScore((*element)->pointsCost);
            if((*element)->isWithSuperPower){
                giveJellyfishSuperPower();
            }
            itemsPtrs.erase(element);
            if(itemsPtrs.empty() && fishPtrs.empty()){
                endGame();
            }
            return;
        }
    }
}
