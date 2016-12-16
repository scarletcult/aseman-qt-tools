/*
    Copyright (C) 2017 Aseman Team
    http://aseman.co

    AsemanQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AsemanQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.0
import QtQuick.Controls.Styles 1.1
import QtGraphicalEffects 1.0
import AsemanTools 1.0

ButtonStyle {
    property color buttonColor: masterPalette.highlight
    property color buttonTextColor: masterPalette.highlightedText
    property color shadowColor: "#000000"
    property real  fontPixelSize: Math.floor(9*Devices.fontDensity)

    SystemPalette {
        id: masterPalette
    }

    background: Item {
        implicitWidth: 100*Devices.density
        implicitHeight: 32*Devices.density

        Item {
            id: frame
            anchors.fill: parent

            Rectangle {
                anchors.fill: parent
                anchors.margins: 1*Devices.density
                radius: 5*Devices.density
                color: {
                    if(control.enabled)
                        return control.pressed? Qt.darker(buttonColor,1.02) : buttonColor
                    else
                        return Qt.darker(masterPalette.window, 1.1)
                }
            }
        }

        InnerShadow {
            anchors.fill: source
            source: frame
            radius: 4*Devices.density
            samples: 16
            horizontalOffset: 0
            verticalOffset: 1*Devices.density
            opacity: control.pressed? 0.5 : 0.2
            color: shadowColor
        }
    }

    label: Item {
        Row {
            anchors.centerIn: parent

            Image {
                height: control.height/2
                width: height
                source: control.iconSource
                sourceSize: Qt.size(width,height)
                visible: status == Image.Ready
            }

            Text {
                color: control.enabled? buttonTextColor : Qt.lighter(masterPalette.windowText, 5)
                text: control.text
                font.family: AsemanApp.globalFont.family
                font.pixelSize: fontPixelSize
            }
        }
    }
}
