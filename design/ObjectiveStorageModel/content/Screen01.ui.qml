

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import ObjectiveStorageModel

Rectangle {
    id: rectangle
    width: Constants.width
    height: 800

    color: Constants.backgroundColor

    Rectangle {
        id: titleBLock
        x: 0
        y: 0
        width: 1280
        height: 70
        color: "#413737"
        radius: 0
        border.width: 0
    }

    Rectangle {
        id: titleBanner
        x: 254
        y: 7
        width: 771
        height: 56
        color: "#ffffff"
        radius: 15
        border.width: 0

        Text {
            id: text1
            x: 122
            y: 5
            text: qsTr("Data Structures Driven Warehouse")
            font.pixelSize: 35
        }
    }

    Rectangle {
        id: rectitleBLock1
        x: 0
        y: 730
        width: 1280
        height: 70
        color: "#413737"
        radius: 0
        border.width: 0
    }

    Rectangle {
        id: rectangle1
        x: 1123
        y: 742
        width: 149
        height: 47
        color: "#ffffff"
        radius: 15
        enabled: true

        Text {
            id: text2
            x: 32
            y: 12
            text: qsTr("Edit/Save")
            font.pixelSize: 20
            font.family: "Arial"
        }
    }

    Rectangle {
        id: rectangle2
        x: 8
        y: 742
        width: 200
        height: 47
        color: "#ffffff"
        radius: 15
        Text {
            x: 25
            y: 12
            text: qsTr("Create product >")
            font.pixelSize: 20
            font.family: "Arial"
        }
        enabled: true
    }

    Rectangle {
        id: rectangle3
        x: 50
        y: 147
        width: 249
        height: 504
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle6
        x: 1009
        y: 256
        width: 250
        height: 288
        color: "#00ffffff"
        radius: 15
        border.width: 3

        Rectangle {
            id: rectangle21
            x: -825
            y: -80
            width: 106
            height: 125
            color: "#44b2dc"
            radius: 25
            border.width: 3
        }

        Rectangle {
            id: rectangle22
            x: -328
            y: 82
            width: 62
            height: 125
            color: "#44b2dc"
            radius: 25
            border.width: 3
        }
    }

    Rectangle {
        id: rectangle7
        x: 1009
        y: 182
        width: 250
        height: 47
        color: "#ffffff"
        radius: 15
        enabled: true
        Text {
            x: 54
            y: 12
            width: 143
            height: 23
            text: qsTr("Product Factory")
            font.pixelSize: 20
            font.family: "Arial"
        }
    }

    Rectangle {
        id: rectangle8
        x: 50
        y: 147
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle9
        x: 50
        y: 315
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle10
        x: 50
        y: 481
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle4
        x: 361
        y: 149
        width: 249
        height: 504
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle11
        x: 361
        y: 149
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle12
        x: 361
        y: 317
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle13
        x: 361
        y: 483
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle5
        x: 671
        y: 149
        width: 249
        height: 504
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle14
        x: 671
        y: 149
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle15
        x: 671
        y: 317
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle16
        x: 671
        y: 483
        width: 249
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle17
        x: 50
        y: 149
        width: 124
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle18
        x: 671
        y: 315
        width: 83
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Rectangle {
        id: rectangle19
        x: 754
        y: 315
        width: 83
        height: 170
        color: "#00ffffff"
        border.width: 3
    }

    Button {
        id: button
        x: 305
        y: 210
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button1
        x: 305
        y: 241
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button2
        x: 305
        y: 371
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button3
        x: 305
        y: 402
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button4
        x: 305
        y: 540
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button5
        x: 305
        y: 571
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button6
        x: 616
        y: 210
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button7
        x: 616
        y: 241
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button8
        x: 616
        y: 371
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button9
        x: 616
        y: 402
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button10
        x: 616
        y: 540
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button11
        x: 616
        y: 571
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button12
        x: 926
        y: 210
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button13
        x: 926
        y: 241
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button14
        x: 926
        y: 371
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button15
        x: 926
        y: 402
        width: 25
        height: 25
        text: qsTr("-")
    }

    Button {
        id: button16
        x: 926
        y: 540
        width: 25
        height: 25
        text: qsTr("+")
    }

    Button {
        id: button17
        x: 926
        y: 571
        width: 25
        height: 25
        text: qsTr("-")
    }

    ComboBox {
        id: comboBox
        x: 115
        y: 92
        displayText: "FIFO"
        textRole: ""
    }

    ComboBox {
        id: comboBox1
        x: 426
        y: 92
        displayText: "LIFO"
        textRole: ""
    }

    ComboBox {
        id: comboBox2
        x: 736
        y: 92
        displayText: "Free"
        textRole: ""
    }
    states: [
        State {
            name: "clicked"
            when: editOrSaveExbtn.checked
        }
    ]
}
