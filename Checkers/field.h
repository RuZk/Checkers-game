#ifndef FIELD_H
#define FIELD_H

#include <QVector>

class Field
{
public:

    enum Cell {NotValid,
               Empty,
               WhitePiece,
               BlackPiece,
               WhiteKing,
               BlackKing
              };
    Field();
    Cell at(int _i, int _j) const;

private:
    QVector<Cell> m_field;
};

#endif // FIELD_H
