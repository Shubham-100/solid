/*
    Copyright 2010 Michael Zanetti <mzanetti@kde.org>
    Copyright 2010 Lukas Tinkl <ltinkl@redhat.com>

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

#ifndef UPOWERDEVICE_H
#define UPOWERDEVICE_H

#include <ifaces/device.h>
#include <solid/deviceinterface.h>

#include <QDBusInterface>
#include <QSet>

namespace Solid
{
namespace Backends
{
namespace UPower
{

class UPowerDevice : public Solid::Ifaces::Device
{
    Q_OBJECT
public:
    UPowerDevice(const QString &udi);
    virtual ~UPowerDevice();

    QObject *createDeviceInterface(const Solid::DeviceInterface::Type &type) override;
    bool queryDeviceInterface(const Solid::DeviceInterface::Type &type) const override;
    QString description() const override;
    QStringList emblems() const override;
    QString icon() const override;
    QString product() const override;
    QString vendor() const override;
    QString udi() const override;
    QString parentUdi() const override;

    QVariant prop(const QString &key) const;
    bool propertyExists(const QString &key) const;
    QMap<QString, QVariant> allProperties() const;

Q_SIGNALS:
    void changed();

private Q_SLOTS:
    void onPropertiesChanged(const QString &ifaceName, const QVariantMap &changedProps, const QStringList &invalidatedProps);
    void slotChanged();
    void login1Resuming(bool active);

private:
    QString batteryTechnology() const;
    mutable QDBusInterface m_device;
    QString m_udi;
    mutable QVariantMap m_cache;

    void checkCache(const QString &key) const;
};

}
}
}

#endif // UPOWERDEVICE_H
