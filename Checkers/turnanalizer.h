#ifndef TURNANALIZER_H
#define TURNANALIZER_H

#include "field.h"
#include "command.h"

// Be careful using this class: _field should have the same live time as TurnAnalizer.

class TurnAnalizer
{
public:
    TurnAnalizer(const Field& _field, const Command& _command);
    void setCommand(const Command& _command);

    bool isValid() const;

    bool isMove() const;
    bool isEat() const;

    int xEated() const;
    int yEated() const;

private:
    const Field m_field;
    Command m_command;
};

#endif // TURNANALIZER_H
