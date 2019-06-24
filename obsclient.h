#ifndef OBSCLIENT_H
#define OBSCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <obsinstance.h>

class OBSClient : public QObject
{
public:
    explicit OBSClient(OBSInstance *obsInstance, QObject *parent = nullptr);

    QNetworkReply* searchBinary(QStringList keywords, QString distribution);

private:
    QNetworkAccessManager *manager;
    OBSInstance *obsInstance;

    static const QUrl PROXY_URL;
    static const QString BINARY_SEARCH_PATH;
    QUrl getProxyUrl(QUrl url);
};

#endif // OBSCLIENT_H
