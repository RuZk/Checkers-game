#ifndef FIELD_H
#define FIELD_H

#include <QVector>

class Field
{
public:
    enum Cell {NotValid, Empty, WhitePiece, BlackPiece, WhiteKing, BlackKing};

    Field();
    bool isValid(int _i, int _j) const;
    Cell at(int _i, int _j) const;
    bool set(int _i, int _j, Cell _val);

    int width() const;
    int height() const;

private:
    QVector<Cell> m_field;
};

#endif // FIELD_H
