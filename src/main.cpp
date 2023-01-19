#include <QApplication>
#include "GameField.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GameField gamefield(FIELD_HEIGHT_CELLS, FIELD_WIDTH_CELLS);
    
    return app.exec();
}