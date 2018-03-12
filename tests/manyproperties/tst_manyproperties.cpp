/****************************************************************************
 *  Copyright (C) 2018 Woboq GmbH
 *  Olivier Goffart <contact at woboq.com>
 *  https://woboq.com/
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program.
 *  If not, see <http://www.gnu.org/licenses/>.
 */
#include <wobjectdefs.h>
#include <QtTest/QtTest>

class tst_ManyProperties : public QObject
{
    W_OBJECT(tst_ManyProperties)

private:
    void manyProperties();
    W_SLOT(manyProperties)
};


class HasManyProperties : public QObject
{
    W_OBJECT(HasManyProperties)
public:
#define DeclareProperty(Type, Name) \
    Type m_##Name; \
    void Name##Changed() W_SIGNAL(Name##Changed) \
    W_PROPERTY(Type, Name MEMBER m_##Name NOTIFY Name##Changed) \


    DeclareProperty(QString, prop0)
    DeclareProperty(QString, prop1)
    DeclareProperty(QString, prop2)
    DeclareProperty(QString, prop3)
    DeclareProperty(QString, prop4)
    DeclareProperty(QString, prop5)
    DeclareProperty(QString, prop6)
    DeclareProperty(QString, prop7)
    DeclareProperty(QString, prop8)
    DeclareProperty(QString, prop9)
    DeclareProperty(QString, prop10)
    DeclareProperty(QString, prop11)
    DeclareProperty(QString, prop12)
    DeclareProperty(QString, prop13)
    DeclareProperty(QString, prop14)
    DeclareProperty(QString, prop15)
    DeclareProperty(QString, prop16)
    DeclareProperty(QString, prop17)
    DeclareProperty(QString, prop18)
    DeclareProperty(QString, prop19)
    DeclareProperty(QString, prop20)
    DeclareProperty(QString, prop21)
    DeclareProperty(QString, prop22)
    DeclareProperty(QString, prop23)
    DeclareProperty(QString, prop24)
    DeclareProperty(QString, prop25)
    DeclareProperty(QString, prop26)
    DeclareProperty(QString, prop27)
    DeclareProperty(QString, prop28)
    DeclareProperty(QString, prop29)
    DeclareProperty(QString, prop30)
    DeclareProperty(QString, prop31)
    DeclareProperty(QString, prop32)
    DeclareProperty(QString, prop33)
    DeclareProperty(QString, prop34)
    DeclareProperty(QString, prop35)
    DeclareProperty(QString, prop36)
    DeclareProperty(QString, prop37)
    DeclareProperty(QString, prop38)
    DeclareProperty(QString, prop39)
    DeclareProperty(QString, prop40)
    DeclareProperty(QString, prop41)
    DeclareProperty(QString, prop42)
    DeclareProperty(QString, prop43)
    DeclareProperty(QString, prop44)
    DeclareProperty(QString, prop45)
    DeclareProperty(QString, prop46)
    DeclareProperty(QString, prop47)
    DeclareProperty(QString, prop48)
    DeclareProperty(QString, prop49)
    DeclareProperty(QString, prop50)
    DeclareProperty(QString, prop51)
    DeclareProperty(QString, prop52)
    DeclareProperty(QString, prop53)
    DeclareProperty(QString, prop54)
    DeclareProperty(QString, prop55)
    DeclareProperty(QString, prop56)
    DeclareProperty(QString, prop57)
    DeclareProperty(QString, prop58)
    DeclareProperty(QString, prop59)
    DeclareProperty(QString, prop60)
    DeclareProperty(QString, prop61)
    DeclareProperty(QString, prop62)
    DeclareProperty(QString, prop63)
    DeclareProperty(QString, prop64)
    DeclareProperty(QString, prop65)
    DeclareProperty(QString, prop66)
    DeclareProperty(QString, prop67)
    DeclareProperty(QString, prop68)
    DeclareProperty(QString, prop69)
    DeclareProperty(QString, prop70)

    DeclareProperty(int, intProp0)
    DeclareProperty(int, intProp1)
    DeclareProperty(int, intProp2)
    DeclareProperty(int, intProp3)
    DeclareProperty(int, intProp4)
    DeclareProperty(int, intProp5)
    DeclareProperty(int, intProp6)
    DeclareProperty(int, intProp7)
    DeclareProperty(int, intProp8)
    DeclareProperty(int, intProp9)
    DeclareProperty(int, intProp10)
    DeclareProperty(int, intProp11)
    DeclareProperty(int, intProp12)
    DeclareProperty(int, intProp13)
    DeclareProperty(int, intProp14)
    DeclareProperty(int, intProp15)
    DeclareProperty(int, intProp16)
    DeclareProperty(int, intProp17)
    DeclareProperty(int, intProp18)
    DeclareProperty(int, intProp19)
    DeclareProperty(int, intProp20)
};



#include <wobjectimpl.h>

W_OBJECT_IMPL(tst_ManyProperties)
W_OBJECT_IMPL(HasManyProperties)

void tst_ManyProperties::manyProperties() {
    HasManyProperties obj;

    {   // test that the corresponding signal is emitted when setting a prop
        bool ok = false;
        auto c = connect(&obj, &HasManyProperties::prop11Changed, [&ok] { ok = true; });

        QVERIFY(obj.setProperty("prop45", QStringLiteral("yo")));
        QCOMPARE(ok, false);

        QVERIFY(obj.setProperty("prop11", QStringLiteral("salut")));
        QCOMPARE(ok, true);
        QCOMPARE(obj.property("prop11"), QStringLiteral("salut"));

        disconnect(c);
    }
    {
        QMetaProperty prop64 = obj.metaObject()->property(obj.metaObject()->indexOfProperty("prop64"));
        QCOMPARE(prop64.name(), "prop64");
        QCOMPARE(prop64.typeName(), "QString");
        QCOMPARE(prop64.hasNotifySignal(), true);
        QCOMPARE(prop64.notifySignal().name(), "prop64Changed");
    }
    {
        QMetaProperty prop20 = obj.metaObject()->property(obj.metaObject()->indexOfProperty("intProp20"));
        QCOMPARE(prop20.name(), "intProp20");
        QCOMPARE(prop20.typeName(), "int");
        QCOMPARE(prop20.hasNotifySignal(), true);
        QCOMPARE(prop20.notifySignal().name(), "intProp20Changed");
    }
}

QTEST_MAIN(tst_ManyProperties)