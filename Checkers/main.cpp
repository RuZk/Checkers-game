#include <QApplication>
#include <QDebug>

#include "field.h"

QChar cellToChar(Field::Cell _cell)
{
    switch (_cell)
    {
    case Field::NotValid:
        return '*';
    case Field::WhitePiece:
        return 'W';
    case Field::BlackPiece:
        return 'B';
    case Field::Empty:
        return ' ';
    default:
        return '%';
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Field f;
    QString out;
    for(int i = -1; i < 9; i++)
    {
        for(int j = -1; j < 9; j++)
        {
            out += cellToChar(f.at(i, j));
        }
        out += "\n";
    }
    qDebug() << out;

    return a.exec();
}
