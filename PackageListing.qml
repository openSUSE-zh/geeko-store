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
                    obsClient.search(searchInput.text);
                    obsLoading.running = true;
                    pmbsClient.search(searchInput.text);
                    pmbsLoading.running = true;
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
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    id: obsLoading
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: false
                }
            }

            ListView {
                id: obsList
                width: parent.width
                height: childrenRect.height

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
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    id: pmbsLoading
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: false
                }
            }

            ListView {
                id: pmbsList
                width: parent.width
                height: childrenRect.height

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    onClicked: console.log("clicked:", modelData)
                }
            }
        }
    }

    Connections {
        target: obsClient

        onSearchProgress: {
            //
        }

        onSearchResultParsed: {
            obsList.model = packages;
            obsLoading.running = false;
            console.log(packages);
        }
    }

    Connections {
        target: pmbsClient

        onSearchProgress: {
            //
        }

        onSearchResultParsed: {
            pmbsList.model = packages;
            pmbsLoading.running = false;
            console.log(packages);
        }
    }
}
