#ifndef OBSCLIENT_H
#define OBSCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

class OBSClient : public QObject
{
public:
    OBSClient(QObject *parent = nullptr);

private:
    QNetworkAccessManager *manager;

    void replyFinished(QNetworkReply *reply);
};

#endif // OBSCLIENT_H
