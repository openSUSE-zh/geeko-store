import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 500
    height: 600

    title: qsTr("Firefox")

    Column {
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.bottomMargin: 20
        spacing: 20

        Item {
            id: headerContainer
            width: parent.width
            height: 128

            Row {
                id: header
                width: parent.width - 20
                height: parent.width
                anchors.fill: parent
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                spacing: 10

                Image {
                    id: icon
                    width: header.height
                    height: header.height
                    smooth: true
                    source: "https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Firefox_Logo%2C_2017.svg/512px-Firefox_Logo%2C_2017.svg.png"
                }

                Column {
                    id: info
                    width: header.width - icon.width - header.spacing
                    height: header.height
                    spacing: 10

                    Text {
                        id: name
                        width: info.width
                        font.pixelSize: 18
                        text: "Mozilla Firefox "
                    }

                    Text {
                        id: packageName
                        width: info.width
                        font.pixelSize: 12
                        opacity: 0.7
                        text: "MozillaFirefox 65.0.1"
                    }

                    Row {
                        id: packageTags
                        width: info.width
                        spacing: 5

                        PackageTag {
                            tag: 'Internet'
                        }
                        PackageTag {
                            tag: 'Web Browser'
                        }
                    }

                    Button {
                        text: qsTr("\u2713 Install")
                        highlighted: true
                    }
                }

            }
        }

        Image {
            id: screenshot
            width: parent.width
            height: parent.width / 2
            source: "https://upload.wikimedia.org/wikipedia/commons/9/98/Mozilla_Firefox_65.png"
            smooth: true
        }

    }
}
