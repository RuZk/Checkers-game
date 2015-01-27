#include "commandexecuter.h"
#include "command.h"

#include "turnanalizer.h"

CommandExecuter::CommandExecuter()
    : m_field(),
      m_currentPlayer(White)
{
}

bool CommandExecuter::isCommandValid(const Command& _command) const
{
    if(_command.player() != m_currentPlayer)
        return false;

    TurnAnalizer analizer(m_field, _command);
    return analizer.isValid();

    return true;
}

bool CommandExecuter::executeCommand(const Command& _command)
{
    if(isCommandValid(_command))
    {
        m_field.set(_command.fromX(), _command.fromY(), Field::Empty);
        Field::Cell subject = m_field.at(_command.fromX(), _command.fromY());
        m_field.set(_command.toX(), _command.toY(), subject);

        TurnAnalizer analizer(m_field, _command);
        if(analizer.isEat())
            m_field.set(analizer.yEated(), analizer.xEated(), Field::Empty);

        m_currentPlayer = (m_currentPlayer == White)? Black : White;
        return true;
    }
    else
        return false;
}

const Field CommandExecuter::field() const
{
    return m_field;
}
