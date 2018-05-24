/*
    Copyright 2006 Kevin Ottens <ervin@kde.org>
    Copyright 2012 Lukas Tinkl <ltinkl@redhat.com>
    Copyright 2014 Kai Uwe Broulik <kde@privat.broulik.de>

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

#ifndef SOLID_BACKENDS_FAKEHW_FAKEBATTERY_H
#define SOLID_BACKENDS_FAKEHW_FAKEBATTERY_H

#include <solid/devices/ifaces/battery.h>
#include "fakedeviceinterface.h"

namespace Solid
{
namespace Backends
{
namespace Fake
{
class FakeBattery : public FakeDeviceInterface, virtual public Solid::Ifaces::Battery
{
    Q_OBJECT
    Q_INTERFACES(Solid::Ifaces::Battery)

public:
    explicit FakeBattery(FakeDevice *device);
    virtual ~FakeBattery();

public Q_SLOTS:
    bool isPresent() const override;
    Solid::Battery::BatteryType type() const override;

    int chargePercent() const override;
    int capacity() const override;

    bool isRechargeable() const override;
    bool isPowerSupply() const override;

    Solid::Battery::ChargeState chargeState() const override;
    qlonglong timeToEmpty() const override;
    qlonglong timeToFull() const override;

    void setChargeState(Solid::Battery::ChargeState newState);
    void setChargeLevel(int newLevel);

    Solid::Battery::Technology technology() const override;

    double energy() const override;
    double energyFull() const override;
    double energyFullDesign() const override;
    double energyRate() const override;

    double voltage() const override;
    double temperature() const override;

    bool isRecalled() const override;
    QString recallVendor() const override;
    QString recallUrl() const override;

    QString serial() const override;

    qlonglong remainingTime() const override;

Q_SIGNALS:
    void presentStateChanged(bool newState, const QString &udi) override;
    void chargePercentChanged(int value, const QString &udi) override;
    void capacityChanged(int value, const QString &udi) override;
    void powerSupplyStateChanged(bool newState, const QString &udi) override;
    void chargeStateChanged(int newState, const QString &udi) override;
    void timeToEmptyChanged(qlonglong time, const QString &udi) override;
    void timeToFullChanged(qlonglong time, const QString &udi) override;
    void energyChanged(double energy, const QString &udi) override;
    void energyFullChanged(double energyFull, const QString &udi) override;
    void energyFullDesignChanged(double energyFullDesign, const QString &udi) override;
    void energyRateChanged(double energyRate, const QString &udi) override;
    void voltageChanged(double voltage, const QString &udi) override;
    void temperatureChanged(double temperature, const QString &udi) override;
    void remainingTimeChanged(qlonglong time, const QString &udi) override;
};
}
}
}

#endif // SOLID_BACKENDS_FAKEHW_FAKEBATTERY_H
