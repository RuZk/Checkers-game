#ifndef COMMANDEXECUTER_H
#define COMMANDEXECUTER_H

#include "field.h"
class Command;

class CommandExecuter
{
public:
    CommandExecuter();

    bool isCommandValid(const Command& _command) const;
    bool executeCommand(const Command& _command);

    const Field field() const;
private:
    Field m_field;
};

#endif // COMMANDEXECUTER_H
