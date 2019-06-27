import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.12

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("Geeko Store")

    Row {
        anchors.fill: window

        PackageListing {
            id: listing
            width: 400
            height: window.height
        }

        PackageDetails {
            id: details
            width: window.width - listing.width
            height: window.height
        }

    }
}
