#include <QApplication>
#include <QDebug>

#include "field.h"
#include "commandexecuter.h"
#include "command.h"

QChar cellToChar(Field::Cell _cell)
{
    switch (_cell)
    {
    case Field::NotValid:
        return '*';
    case Field::WhitePiece:
        return 'w';
    case Field::BlackPiece:
        return 'b';
    case Field::WhiteKing:
        return 'W';
    case Field::BlackKing:
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

//    Field f;
//    QString out;
//    for(int i = 0; i < 8; i++)
//    {
//        out += QString::number(i);
//        for(int j = 0; j < 8; j++)
//        {
//            out += cellToChar(f.at(i, j));
//        }
//        out += "\n";
//    }
//    qDebug() << out;

    /*qDebug() << (f.at(0, 0) == Field::WhitePiece);
    qDebug() << (f.at(2, 0) == Field::WhitePiece);
    qDebug() << (f.at(2, 6) == Field::WhitePiece);
    qDebug() << (f.at(3, 7) == Field::Empty);

    CommandExecuter executer;
    Command command1(6, 5, 7, 4, White);
    Command command2(1, 2, 0, 3, Black);
    qDebug() << executer.isCommandValid(command1);
    qDebug() << executer.isCommandValid(command2);

    qDebug() << executer.executeCommand(command1);
    qDebug() << executer.isCommandValid(command1);
    qDebug() << executer.isCommandValid(command2);

    qDebug() << executer.executeCommand(command2);
*/

    return a.exec();
}
