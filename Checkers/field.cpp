#include "field.h"

const int N = 8;

Field::Field()
   : m_field(32)
{
    for(int i = 0; i < 12; ++i)
        m_field[i] = WhitePiece;
    for(int i = 12; i < 20; ++i)
        m_field[i] = Empty;
    for(int i = 20; i < 32; ++i)
        m_field[i] = BlackPiece;
}

bool Field::isValid(int _i, int _j) const
{
    if(_i > 7 || _j > 7 || _i < 0 || _j < 0)
        return false;
    if((_i + _j) % 2)
        return false;

    int index = _i * 8 + _j;
    if(index > 64 || index < 0)
        return false;

    return true;
}

Field::Cell Field::at(int _i, int _j) const
{
    if(!isValid(_i, _j))
        return NotValid;

    int index = _i * 8 + _j;
    index /= 2;
    return m_field[index];
}

bool Field::set(int _i, int _j, Cell _val)
{
    if(!isValid(_i, _j))
        return false;

    int index = _i * 8 + _j;
    index /= 2;
    m_field[index] = _val;
    return true;
}

int Field::width() const
{
    return N;
}

int Field::height() const
{
    return N;
}
