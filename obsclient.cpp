#include "obsclient.h"

#include <QtNetwork>

#include <QObject>
#include <QNetworkReply>

#include "rpmpackage.h"

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

void OBSClient::search(QStringList keywords)
{
    QUrl url = obsInstance->getApiRootUrl();
    url.setPath(BINARY_SEARCH_PATH);
    QUrlQuery query;
    QString names = QString("'") + keywords.join(QString(",")) + QString("'");
    QString xpath = QString("contains-ic(@name,%1) and path/project='%2'").arg(names).arg(obsInstance->getDistPrefix() + "openSUSE:Factory");
    query.addQueryItem(QString("match"), QUrl::toPercentEncoding(xpath));
    url.setQuery(query);
    QUrl proxyUrl = getProxyUrl(url.toEncoded());

    searchReply = manager->get(QNetworkRequest(proxyUrl));

    connect(searchReply, &QNetworkReply::finished, this, &OBSClient::parseSearchResult);
}

void OBSClient::search(QString keywords)
{
    search(keywords.split(" ", QString::SkipEmptyParts));
}

void OBSClient::parseSearchResult()
{
    QVector<RPMPackage*> packages;
    QString body = searchReply->readAll();
    QXmlStreamReader xml(body);
    xml.readNextStartElement();
    if (xml.name() == "collection") {
        while (xml.readNextStartElement()) {
            if (xml.name() == "binary") {
                RPMPackage *rpm = new RPMPackage(xml.attributes());
                packages << rpm;
                xml.readElementText();
            } else {
                xml.skipCurrentElement();
            }
        }
    }
    emit searchResultParsed(packages);
}


QUrl OBSClient::getProxyUrl(QString url)
{
    QUrlQuery query;
    query.addQueryItem(QString("obs_instance"), obsInstance->getName());
    query.addQueryItem(QString("obs_api_link"), QUrl::toPercentEncoding(url));
    QUrl proxyUrl(PROXY_URL);
    proxyUrl.setQuery(query);
    return proxyUrl;
}
