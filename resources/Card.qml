import QtQuick 2.9
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Material.impl 2.2
import QtGraphicalEffects 1.0

Item {
    id: root
    anchors.fill: parent
    property int elevation: 1


    Rectangle {
        id: rect
        anchors.fill: parent
        color: "white"
        radius: 4
        layer.enabled: root.elevation > 0
        layer.effect: ElevationEffect {
            elevation: root.elevation
        }
    }
}
