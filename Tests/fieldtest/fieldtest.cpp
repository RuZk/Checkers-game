#ifndef FIELD_TST
#define FIELD_TST

#include <QString>
#include <QtTest>

#include "../../Checkers/field.h"

class FieldTest : public QObject
{
    Q_OBJECT

public:
    FieldTest();

private Q_SLOTS:    
    void testCells();
    void testAllField();
    void testOutOfField();
};

//--------------------

QChar cellToChar(Field::Cell _cell)
{
    switch (_cell)
    {
    case Field::NotValid:
        return '*';
    case Field::WhitePiece:
        return 'w';
    case Field::BlackPiece:
        return 'b';
    case Field::WhiteKing:
        return 'W';
    case Field::BlackKing:
        return 'B';
    case Field::Empty:
        return ' ';
    default:
        return '%';
    }
}

FieldTest::FieldTest()
{}

void FieldTest::testCells()
{
    Field f;
    QCOMPARE(f.at(0, 0), Field::WhitePiece);
    QCOMPARE(f.at(0, 1), Field::NotValid);
    QCOMPARE(f.at(6, 0), Field::BlackPiece);

    QCOMPARE(f.at(2, 6), Field::WhitePiece);
    QCOMPARE(f.at(2, 7), Field::NotValid);
    QCOMPARE(f.at(3, 0), Field::NotValid);
    QCOMPARE(f.at(3, 1), Field::Empty);

    QCOMPARE(f.at(5, 1), Field::BlackPiece);
    QCOMPARE(f.at(5, 0), Field::NotValid);
    QCOMPARE(f.at(4, 7), Field::NotValid);
    QCOMPARE(f.at(4, 6), Field::Empty);
}

void FieldTest::testAllField()
{
    Field f;
    QString out;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Field::Cell cellType = f.at(i, j);

            if((i + j) % 2 == 0)
            {
                if(cellType == Field::NotValid)
                    QFAIL("wrong cell invalidisity");
            }
            else
                if(cellType != Field::NotValid)
                    QFAIL("wrong cell invalidisity");

            out += cellToChar(f.at(i, j));
        }
        out += "\n";
    }

    qDebug() << "out\n" << out;
/*    QString rightAns =
           "w*w*w*w*\n\
            *w*w*w*w\n\
            w*w*w*w*\n\
            * * * * \n\
             * * * *\n\
            *b*b*b*b\n\
            b*b*b*b*\n\
            *b*b*b*b\n";

    QCOMPARE(rightAns, out);*/
}

void FieldTest::testOutOfField()
{
    Field f;
    for(int i = -100; i < 100; i++)
        for(int j = -100; j < 100; j++)
        {
            Field::Cell cellType = f.at(i, j);
            if(i <0 || i > 8 || j < 0 || j > 8)
                if(cellType != Field::NotValid)
                    QFAIL(QString("wrong cell invalidisity at point (%1, %2)").arg(i).arg(j).toStdString().c_str());
        }

}

//QTEST_MAIN(FieldTest)

#include "tst_fieldtest.moc"

#endif // FIELD_TST
