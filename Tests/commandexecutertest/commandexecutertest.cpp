#ifndef COMMANDEXECUTER_TST
#define COMMANDEXECUTER_TST

#include <QString>
#include <QtTest>

#include "../../Checkers/command.h"
#include "../../Checkers/commandexecuter.h"

class CommandExecuterTest : public QObject
{
    Q_OBJECT

public:
    CommandExecuterTest();

private Q_SLOTS:
    void testCommands();
};

//--------------------

CommandExecuterTest::CommandExecuterTest()
{}

void CommandExecuterTest::testCommands()
{
    CommandExecuter executer;
    Command command1(2, 6, 3, 7, White);
    Command command2(5, 1, 4, 0, Black);

    QCOMPARE(executer.isCommandValid(command1), true);
    QCOMPARE(executer.isCommandValid(command2), false);

    QCOMPARE(executer.executeCommand(command1), true);

    QCOMPARE(executer.isCommandValid(command1), false);
    QCOMPARE(executer.isCommandValid(command2), true);

    QCOMPARE(executer.executeCommand(command2), true);

    QCOMPARE(executer.isCommandValid(command1), false);
    QCOMPARE(executer.isCommandValid(command2), false);
}

//QTEST_MAIN(CommandExecuterTest)

#include "commandexecutertest.moc"

#endif // COMMANDEXECUTER_TST
