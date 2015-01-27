#include "turnanalizer.h"

TurnAnalizer::TurnAnalizer(const Field &_field, const Command &_command)
    : m_field(_field),
      m_command(_command)
{
}

void TurnAnalizer::setCommand(const Command &_command)
{
    m_command = _command;
}

bool TurnAnalizer::isValid() const
{
    Field::Cell from = m_field.at(m_command.fromX(), m_command.fromY());
    if(from == Field::NotValid || from == Field::Empty)
        return false;
    Field::Cell to = m_field.at(m_command.toX(), m_command.toY());
    if(to == Field::NotValid || to != Field::Empty)
        return false;

    return isMove() || isEat();
}

bool TurnAnalizer::isMove() const
{
    Field::Cell from = m_field.at(m_command.fromX(), m_command.fromY());

    int progressX = m_command.toX() - m_command.fromX();
    if(progressX == 1 || progressX == -1)
    {
        int progressY = m_command.toY() - m_command.fromY();
        if( (from == Field::WhitePiece && progressY == 1) ||
            (from == Field::BlackPiece && progressY == -1))
            return true;
    }
    return false;
}

bool TurnAnalizer::isEat() const
{
    int progressX = m_command.toX() - m_command.fromX();
    int progressY = m_command.toY() - m_command.fromY();

    if((progressX == 2 || progressX == -2) || progressY == 2 || progressY == -2)
    {
        int midX = m_command.fromX() + progressX / 2;
        int midY = m_command.fromY() + progressY / 2;
        Field::Cell mid = m_field.at(midY, midX);
        if((m_command.player() == White && (mid == Field::BlackKing || mid == Field::BlackPiece)) ||
           (m_command.player() == Black && (mid == Field::WhiteKing || mid == Field::WhitePiece)) )
        return true;
    }
    return false;
}

int TurnAnalizer::xEated() const
{
    int progressX = m_command.toX() - m_command.fromX();
    return m_command.fromX() + progressX / 2;
}

int TurnAnalizer::yEated() const
{
    int progressY = m_command.toY() - m_command.fromY();
    return m_command.fromY() + progressY / 2;
}
