#include "rpmpackagelist.h"

#include <QXmlStreamReader>

RPMPackageList::RPMPackageList(OBSInstance *obsInstance, QObject *parent) : QObject(parent)
{
    obs = new OBSClient(obsInstance);
}

void RPMPackageList::search(QStringList keywords) {
    reply = obs->searchBinary(keywords, "openSUSE:Factory");
    // Update progress while waiting response data
    connect(reply, &QNetworkReply::downloadProgress, this, &RPMPackageList::progress);
    // Response finished and data is ready to read
    connect(reply, &QNetworkReply::finished, this, &RPMPackageList::parse);
}

void RPMPackageList::search(QString keywords)
{
    search(keywords.split(" ", QString::SkipEmptyParts));
}

void RPMPackageList::parse()
{
    QString body = reply->readAll();
    qDebug() << reply->error() << body;
    QXmlStreamReader xml(body);


    //emit parsed();
}
