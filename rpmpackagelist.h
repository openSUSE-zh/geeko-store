#ifndef RPMPACKAGELIST_H
#define RPMPACKAGELIST_H

#include <QObject>

#include "obsclient.h"
#include "rpmpackage.h"

class RPMPackageList : public QObject
{
    Q_OBJECT
public:
    explicit RPMPackageList(OBSInstance *obsInstance, QObject *parent = nullptr);

signals:
    void progress(qint64 bytesRead, qint64 totalBytes);
    void parsed(QList<RPMPackage> binaries, QStringList packages);

public slots:
    void parse();
    void search(QString keywords);
    void search(QStringList keywords);

private:
    OBSClient *obs;
    QNetworkReply *reply;
};

#endif // RPMPACKAGELIST_H
