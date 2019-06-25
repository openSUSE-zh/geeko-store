import QtQuick 2.9
import QtQuick.Controls 2.5

Page {
    width: 300
    height: 600

    title: qsTr("Packages")

    background: Rectangle {
        color: "#ffffff"
    }

    Item {
        id: searchBar
        anchors.top: parent.top
        width: parent.width
        height: searchInput.height + 10

        Row {
            width: parent.width
            height: searchInput.height
            anchors.fill: parent
            anchors.margins: 5
            spacing: 5

            TextField {
                id: searchInput
                width: parent.width - searchButton.width - parent.spacing
            }

            Button {
                id: searchButton
                text: qsTr("Search")

                onClicked: {
                    obsListModel.search(searchInput.text);
                    pmbsListModel.search(searchInput.text);
                }
            }
        }
    }

    ScrollView {
        anchors.top: searchBar.bottom
        width: parent.width
        height: parent.height - searchBar.height
        clip: true

        Column {
            width: parent.width
            height: childrenRect.height

            Label {
                id: obsLabel
                width: parent.width
                text: "openSUSE"
                background: Rectangle {
                    color: "yellow"
                }
            }

            ListView {
                id: obsList
                width: parent.width
                height: childrenRect.height
                model: ["hello", "world"]

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    onClicked: console.log("clicked:", modelData)
                }
            }

            Label {
                id: pmbsLabel
                width: parent.width
                text: "Packman"
                background: Rectangle {
                    color: "#eeeeee"
                }
            }

            ListView {
                id: pmbsList
                width: parent.width
                height: childrenRect.height
                model: ["foo", "bar"]

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    onClicked: console.log("clicked:", modelData)
                }
            }
        }
    }

    Connections {
        target: obsListModel

        onProgress: {
            //
        }

        onParsed: {
            obsList.model = packages;
            console.log(packages);
        }
    }

    Connections {
        target: pmbsListModel

        onProgress: {
            //
        }

        onParsed: {
            pmbsList.model = packages;
            console.log(packages);
        }
    }
}
