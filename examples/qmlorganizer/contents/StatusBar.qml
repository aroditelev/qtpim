/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Mobility Components.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Item {
    id: statusbar
    property string status
    signal leftClicked
    signal rightClicked
    signal addClicked
    signal managerChangeClicked

    BorderImage { source: "images/titlebar.sci"; width: parent.width; height: parent.height + 14; y: -7 }

    Button {//add new item button
        id: addButton
        text: "+"
        anchors.left: parent.left; anchors.leftMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.addClicked()
    }

    Button {
        id: leftButton
        text: "<"
        anchors.left: addButton.right; anchors.leftMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.leftClicked()
    }
    Text {
        id:statusText
        color: "#ecc70a"
        text:status
        font.family: "Monospace"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 6
        anchors.left: leftButton.right
        anchors.leftMargin: 2
        anchors.right: rightButton.left
        anchors.rightMargin: 2
        y: 5

    }

    Button {
        id: rightButton
        text: ">"
        anchors.right: todayButton.left; anchors.rightMargin: 2; y: 3; width: 30; height: 32
        onClicked: statusbar.rightClicked()
    }

    Button {
        //change the current Date to Today
        id: todayButton;
        anchors.right: parent.right; anchors.leftMargin: 2; y: 3; width: 50; height: 32
        text: "Today";
            onClicked: {
                var tempdate = new Date();
                calendar.currentDate = new Date(tempdate.getFullYear(), tempdate.getMonth(), tempdate.getDate());
            }
    }


}
