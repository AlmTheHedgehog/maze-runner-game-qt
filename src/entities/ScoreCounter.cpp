#include "ScoreCounter.h"

ScoreCounter::ScoreCounter(QWidget *parent, int xCell, int yCell):Entity(parent, QPixmap(), xCell, yCell){
    setFixedSize(300, 30);
    setScore(0);
    setFont(QFont("Arial", 20, QFont::Bold));
    setStyleSheet("QLabel { color : white; }");
}

void ScoreCounter::addScore(int scoreToBeAdded){
    score += scoreToBeAdded;
    setText(QString::number(score));
}

void ScoreCounter::setScore(int newScore){
    score = newScore;
    setText(QString::number(score));
}

int ScoreCounter::getScore(){
    return score;
}
