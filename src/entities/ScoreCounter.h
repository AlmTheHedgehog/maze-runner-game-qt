#pragma once
#include "Entity.h"

class ScoreCounter : public Entity{
    Q_OBJECT
    public:
        ScoreCounter(QWidget *parent, int xCell, int yCell);
        void setScore(int newScore);
        int getScore();

    public slots:
        void addScore(int scoreToBeAdded); 

    private:
        int score;

};