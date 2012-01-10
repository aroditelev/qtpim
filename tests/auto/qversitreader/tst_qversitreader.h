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

#ifndef tst_QVERSITREADER_H
#define tst_QVERSITREADER_H

#include <QObject>
#include <QBuffer>
#include <qversitreader.h>

QTVERSIT_BEGIN_NAMESPACE
class QVersitReaderPrivate;
class LineReader;
QTVERSIT_END_NAMESPACE

QTVERSIT_USE_NAMESPACE

// Poor man's QSignalSpy because I couldn't get QSignalSpy to work with the user type QVR::State.
class SignalCatcher : public QObject
{
Q_OBJECT
public:
    SignalCatcher() : mResultsCount(0) {}
public slots:
    void stateChanged(QVersitReader::State state) {
        mStateChanges.append(state);
    }
    void resultsAvailable() {
        mResultsCount += 1;
    }

public:
    QList<QVersitReader::State> mStateChanges;
    int mResultsCount;
};

class tst_QVersitReader : public QObject
{
     Q_OBJECT

private slots: // Tests
    void init();
    void cleanup();

    void testDevice();
    void testNullDevice();
    void testDefaultCodec();
    void testValidateUtf8();
    void testValidateUtf8_data();
    void testDetectCodec();
    void testDetectCodec_data();
    void testReading();
    void testResult();
    void testParseNextVersitProperty();
    void testParseNextVersitProperty_data();
    void testParseVersitDocument();
    void testParseVersitDocument_data();
    void testDecodeQuotedPrintable();
    void testDecodeQuotedPrintable_data();
    void testParamName();
    void testParamValue();
    void testExtractPart();
    void testExtractParts();
    void testExtractPropertyGroupsAndName();
    void testExtractVCard21PropertyParams();
    void testExtractVCard30PropertyParams();
    void testExtractParams();
    void testReadLine();
    void testReadLine_data();
    void testByteArrayInput();
    void testRemoveBackSlashEscaping();

private: // Data
    QVersitReader* mReader;
#ifdef QT_BUILD_INTERNAL
    QVersitReaderPrivate* mReaderPrivate;
#endif
    QBuffer* mInputDevice;
    QTextCodec* mAsciiCodec;
    SignalCatcher* mSignalCatcher;
};

#endif // tst_VERSITREADER_H
