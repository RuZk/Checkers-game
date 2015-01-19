#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command(int _fromX, int _fromY, int _toX, int _toY);
    inline int fromX() const {return m_fromX;}
    inline int fromY() const {return m_fromY;}
    inline int toX()   const {return m_toX;}
    inline int toY()   const {return m_toY;}

private:
    int m_fromX, m_fromY;
    int m_toX, m_toY;
};

#endif // COMMAND_H