#include "commandexecuter.h"
#include "command.h"

CommandExecuter::CommandExecuter()
    : m_field(),
      m_currentPlayer(White)
{
}

bool CommandExecuter::isCommandValid(const Command& _command) const
{
    Field::Cell from = m_field.at(_command.fromX(), _command.fromY());
    if(from == Field::NotValid || from == Field::Empty)
        return false;
    Field::Cell to = m_field.at(_command.toX(), _command.toY());
    if(to == Field::NotValid || to != Field::Empty)
        return false;

    // much more conditions!!!
    return true;
}

bool CommandExecuter::executeCommand(const Command& _command)
{
    if(isCommandValid(_command))
    {
        m_field.set(_command.fromX(), _command.fromY(), Field::Empty);
        Field::Cell subject = m_field.at(_command.fromX(), _command.fromY());
        m_field.set(_command.toX(), _command.toY(), subject);
        return true;
    }
    else
        return false;
}

const Field CommandExecuter::field() const
{
    return m_field;
}
