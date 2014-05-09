/*
    Copyright 2014 Alejandro Fiestas Olivares <afiestas@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QTest>
#include <QSignalSpy>
#include <Solid/Power>
#include <Solid/AcPluggedJob>

using namespace Solid;
class solidPowerTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testAcPluggedJob();
    void testAcPluggedChanged();
};

void solidPowerTest::testAcPluggedJob()
{
    AcPluggedJob *job = new AcPluggedJob();
    QVERIFY(job->exec());
    QVERIFY(job->isPlugged());

    job = Power::isAcPlugged();
    QVERIFY(job->exec());
    QVERIFY(job->isPlugged());
}

void solidPowerTest::testAcPluggedChanged()
{
    Power *power = Power::self();
    QSignalSpy spy(power, SIGNAL(acPluggedChanged(bool)));

    QVERIFY(spy.wait());
    QVERIFY(spy.takeFirst().first().toBool());
}


QTEST_MAIN(solidPowerTest)

#include "solidpowertest.moc"