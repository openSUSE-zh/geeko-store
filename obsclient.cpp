#include "obsclient.h"

#include <QObject>
#include <QtNetwork>
#include <QDebug>

OBSClient::OBSClient(QObject *parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &OBSClient::replyFinished);

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));

    qDebug() << "na";
}

void OBSClient::replyFinished(QNetworkReply *reply) {

}
