#include <QTest>
#include "fieldtest/fieldtest.cpp"
#include "commandexecutertest/commandexecutertest.cpp"

int main(int argc, char *argv[])
{
    FieldTest test1;
    CommandExecuterTest test2;

    QTest::qExec(&test1);
    QTest::qExec(&test2);

    return 0;
}
