import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 300
    height: 600

    title: qsTr("Packages")

    background: Rectangle {
        color: "#ffffff"
    }

    Column {
        anchors.fill: parent

        Item {
            width: parent.width
            height: search.height + 10

            Row {
                width: parent.width
                height: search.height
                anchors.fill: parent
                anchors.margins: 5
                spacing: 5

                TextField {
                    id: search
                    width: parent.width - searchButton.width - parent.spacing
                    text: "firefox"
                }

                Button {
                    id: searchButton
                    text: qsTr("Search")
                }
            }
        }

        ItemDelegate {
            text: qsTr("MozillaFirefox")
            width: parent.width
        }

        ItemDelegate {
            text: qsTr("firefox-esr")
            width: parent.width
        }
    }
}
