#include "field.h"

Field::Field()
   : m_field(32)
{
    for(int i = 0; i < 12; ++i)
        m_field[i] = BlackPiece;
    for(int i = 12; i < 20; ++i)
        m_field[i] = Empty;
    for(int i = 20; i < 32; ++i)
        m_field[i] = WhitePiece;
}

Field::Cell Field::at(int _i, int _j) const
{
    if(_i >= 8 || _j >= 8 || _i < 0 || _j < 0)
        return NotValid;
    if((_i + _j) % 2)
        return NotValid;

    int index = _i * 8 + _j;
    if(index > 63 || index < 0)
        return NotValid;
    index /= 2;

    return m_field[index];
}
