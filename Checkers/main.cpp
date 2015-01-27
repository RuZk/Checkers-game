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

    Field f;

    CommandExecuter executer;
    Command command1(2, 6, 3, 7, White);
    Command command2(5, 1, 4, 0, White);

    qDebug() << executer.isCommandValid(command1);
    qDebug() << executer.isCommandValid(command2);
    qDebug() << executer.executeCommand(command1);
    qDebug() << executer.isCommandValid(command1);

    qDebug() << executer.isCommandValid(command2);
    qDebug() << executer.executeCommand(command2);


    return a.exec();
}
