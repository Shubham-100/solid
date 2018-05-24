/*
    Copyright 2006 Davide Bettio <davide.bettio@kdemail.net>

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

#ifndef SOLID_BACKENDS_FAKEHW_FAKEVOLUME_H
#define SOLID_BACKENDS_FAKEHW_FAKEVOLUME_H

#include "fakeblock.h"
#include <solid/devices/ifaces/storagevolume.h>

namespace Solid
{
namespace Backends
{
namespace Fake
{
class FakeVolume : public FakeBlock, virtual public Solid::Ifaces::StorageVolume
{
    Q_OBJECT
    Q_INTERFACES(Solid::Ifaces::StorageVolume)

public:
    explicit FakeVolume(FakeDevice *device);
    virtual ~FakeVolume();

public Q_SLOTS:
    bool isIgnored() const override;
    Solid::StorageVolume::UsageType usage() const override;
    QString fsType() const override;
    QString label() const override;
    QString uuid() const override;
    qulonglong size() const override;
    QString encryptedContainerUdi() const override;
};
}
}
}

#endif // SOLID_BACKENDS_FAKEHW_FAKEVOLUME_H
