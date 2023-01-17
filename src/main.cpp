#include <QApplication>
#include "GameField.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GameField gamefield(36, 28);
    
    return app.exec();
}