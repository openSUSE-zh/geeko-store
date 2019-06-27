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
                enabled: searchInput.text.length > 0

                onClicked: {
                    rpmPackageListModel.search(searchInput.text);
                }
            }
        }
    }

    ScrollView {
        id: firstColumn
        anchors.top: searchBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: secondColumn.left
        clip: true

        Column {
            width: parent.width
            height: childrenRect.height

            Label {
                width: parent.width
                text: "RPM packages (OBS, Packman)"
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: rpmPackageListModel.isSearching
                }
            }

            ListView {
                width: parent.width
                height: childrenRect.height

                model: rpmPackageListModel.names

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                    highlighted: rpmPackageListModel.selectedName === modelData
                    onClicked: {
                        rpmPackageListModel.selectedName = modelData
                        console.log(rpmPackageListModel.selectedName)
                    }
                }
            }

            Label {
                width: parent.width
                text: "Flatpak (FlatHub.org)"
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: false
                }
            }

            ListView {
                width: parent.width
                height: childrenRect.height

                model: ["foo", "bar"]

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                }
            }

            Label {
                width: parent.width
                text: "Snap (Snap Store)"
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: false
                }
            }

            ListView {
                width: parent.width
                height: childrenRect.height

                model: ["foo", "bar"]

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                }
            }

            Label {
                width: parent.width
                text: "AppImage (Vendor Websites)"
                horizontalAlignment: Text.AlignHCenter
                padding: 5
                background: Rectangle {
                    color: "#eeeeee"
                }

                BusyIndicator {
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    running: false
                }
            }

            ListView {
                width: parent.width
                height: childrenRect.height

                model: ["foo", "bar"]

                delegate: ItemDelegate {
                    text: modelData
                    width: parent.width
                }
            }
        }
    }

    ScrollView {
        id: secondColumn
        anchors.top: searchBar.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: rpmPackageListModel.selectedName ? parent.width / 2 : 0
        clip: true;

        ListView {
            model: rpmPackageListModel.packages

            delegate: ItemDelegate {
                text: modelData.project
                width: parent.width
                highlighted: modelData.project === rpmPackageListModel.selectedPackage.project
                onClicked: {
                    rpmPackageListModel.selectedPackage = modelData
                }
            }
        }
    }
}
