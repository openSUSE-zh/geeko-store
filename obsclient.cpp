#include "obsclient.h"

#include <QtNetwork>

#include <QDebug>
#include <QObject>
#include <QNetworkReply>

#include <curl/curl.h>
#include <string>

const QUrl OBSClient::PROXY_URL = QUrl("https://guoyunhe.me/opi/proxy/index.php");
const QString OBSClient::BINARY_SEARCH_PATH  = "/search/published/binary/id";

/**
 * @brief OBSClient::OBSClient
 * @param instance OBSClient::OBS or OBSClient::PMBS
 * @param apiRoot OBSClient::OBS_API_ROOT or OBSClient::PMBS_API_ROOT
 * @param parent
 */
OBSClient::OBSClient(OBSInstance *obsInstance, QObject *parent) : QObject(parent)
{
    this->obsInstance = obsInstance;
    this->manager = new QNetworkAccessManager(this);
}

QNetworkReply* OBSClient::searchBinary(QStringList keywords, QString distribution)
{
    QUrl url = obsInstance->getApiRootUrl();
    url.setPath(BINARY_SEARCH_PATH);
    QUrlQuery query;
    QString names = QString("'") + keywords.join(QString(", ")) + QString("'");
    QString xpath = QString("contains-ic(@name, %1) and path/project='%2'").arg(names).arg(distribution);
    query.addQueryItem(QString("match"), QString(QUrl(xpath).toEncoded()));
    url.setQuery(query);
    qDebug() << url.toEncoded();
    QUrl proxyUrl = getProxyUrl(url);
    return manager->get(QNetworkRequest(proxyUrl));
}

QUrl OBSClient::getProxyUrl(QUrl url)
{
    QUrlQuery query;
    query.addQueryItem(QString("obs_api_link"), QString(url.toEncoded()));
    query.addQueryItem(QString("obs_instance"), obsInstance->getName());
    QUrl proxyUrl(PROXY_URL);
    proxyUrl.setQuery(query);
    qDebug() << query.toString();
    return proxyUrl;
}
