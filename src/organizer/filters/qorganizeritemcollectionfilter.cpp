/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Mobility Components.
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qorganizeritemcollectionfilter.h>
#include <private/qorganizeritemcollectionfilter_p.h>

QTORGANIZER_BEGIN_NAMESPACE

/*!
    \class QOrganizerItemCollectionFilter
    \brief The QOrganizerItemCollectionFilter class provides a filter based around the collection one'
           organizer item belongs to.
    \inmodule QtOrganizer
    \ingroup organizeritems-filters

    It may be used to select organizer items belonging to certain collections.
 */

Q_IMPLEMENT_ORGANIZERITEMFILTER_PRIVATE(QOrganizerItemCollectionFilter)

/*!
    \fn QOrganizerItemCollectionFilter::QOrganizerItemCollectionFilter(const QOrganizerItemFilter &other)

    Constructs a copy of \a other if possible, otherwise constructs a new organizeritem collection filter.
 */

/*!
    Constructs a new organizeritem collection filter.
 */
QOrganizerItemCollectionFilter::QOrganizerItemCollectionFilter()
    : QOrganizerItemFilter(new QOrganizerItemCollectionFilterPrivate)
{
}

/*!
    Sets the \a id of the collection, which the organizer items should belong to.
 */
void QOrganizerItemCollectionFilter::setCollectionId(const QOrganizerCollectionId &id)
{
    Q_D(QOrganizerItemCollectionFilter);
    d->m_ids.clear();
    d->m_ids.insert(id);
}

/*!
    Sets the list of collection \a ids, which the organizer items should belong to.
 */
void QOrganizerItemCollectionFilter::setCollectionIds(const QSet<QOrganizerCollectionId> &ids)
{
    Q_D(QOrganizerItemCollectionFilter);
    d->m_ids = ids;
}

/*!
    Returns the list of collection IDs of organizeritems should belong to.
 */
QSet<QOrganizerCollectionId> QOrganizerItemCollectionFilter::collectionIds() const
{
    Q_D(const QOrganizerItemCollectionFilter);
    return d->m_ids;
}

QTORGANIZER_END_NAMESPACE
