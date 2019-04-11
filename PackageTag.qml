import QtQuick 2.0
import QtQuick.Controls 2.4

Label {
    property string tag;
    function getName(tag) {
        switch(tag) {
        case 'Internet':
            return qsTr('Internet')
        case 'Web Browser':
            return qsTr('Web Browser')
        default:
            return qsTr('Unknown')
        }
    }

    function getColor(tag) {
        switch(tag) {
        case 'Internet':
            return '#336699'
        case 'Web Browser':
            return '#993366'
        default:
            return '#777777'
        }
    }

    leftPadding: 3
    rightPadding: 3
    text: getName(tag)
    color: '#ffffff'
    background: Rectangle {
        color: getColor(tag)
        radius: 3
    }
}
