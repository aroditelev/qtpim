/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qorganizerjsondbenginefactory.h"
#include "qorganizerjsondbengine.h"
#include "qorganizerjsondbid.h"
#include "qorganizerjsondbstring.h"

QTORGANIZER_BEGIN_NAMESPACE

QOrganizerManagerEngine *QOrganizerJsonDbEngineFactory::engine(const QMap<QString, QString> &parameters, QOrganizerManager::Error *error)
{
    Q_UNUSED(parameters)

    QOrganizerJsonDbEngine *ret = QOrganizerJsonDbEngine::createJsonDbEngine(error); // manager takes ownership and will clean up.
    return ret;
}

QOrganizerItemEngineId *QOrganizerJsonDbEngineFactory::createItemEngineId(const QMap<QString, QString> &parameters, const QString &idString) const
{
    Q_UNUSED(parameters)

    QOrganizerJsonDbItemId *retn = new QOrganizerJsonDbItemId;
    if (!idString.isEmpty())
        retn->setItemId(idString);
    return retn;
}

QOrganizerCollectionEngineId *QOrganizerJsonDbEngineFactory::createCollectionEngineId(const QMap<QString, QString> &parameters, const QString &idString) const
{
    Q_UNUSED(parameters)

    QOrganizerJsonDbCollectionId *retn = new QOrganizerJsonDbCollectionId;
    if (!idString.isEmpty())
        retn->setCollectionId(idString);
    return retn;
}

QString QOrganizerJsonDbEngineFactory::managerName() const
{
    return QOrganizerJsonDbStr::jsonDbEngineId();
}

#include "moc_qorganizerjsondbenginefactory.cpp"

QTORGANIZER_END_NAMESPACE
