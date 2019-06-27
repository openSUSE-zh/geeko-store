#ifndef OBSCLIENT_H
#define OBSCLIENT_H

#include <QObject>
#include <QQmlListProperty>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "obsinstance.h"
#include "rpmpackage.h"

class OBSClient : public QObject
{
    Q_OBJECT

public:
    explicit OBSClient(OBSInstance *obsInstance, QObject *parent = nullptr);

signals:
    void searchResultParsed(QVector<RPMPackage*> packages);

public slots:
    void search(QStringList keywords);
    void search(QString keywords);
    void parseSearchResult();

private:
    QNetworkAccessManager *manager;
    OBSInstance *obsInstance;
    QNetworkReply *searchReply;

    static const QUrl PROXY_URL;
    static const QString BINARY_SEARCH_PATH;

    QUrl getProxyUrl(QString url);
};

#endif // OBSCLIENT_H
