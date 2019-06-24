#include "obsinstance.h"

OBSInstance* OBSInstance::OBS = new OBSInstance(QString("openSUSE"), QUrl("https://build.opensuse.org/"), QUrl("https://download.opensuse.org/repositories/%1/%2/%1.repo"));
OBSInstance* OBSInstance::PMBS = new OBSInstance(QString("Packman"), QUrl("https://pmbs.links2linux.de/"), QUrl("https://ftp.gwdg.de/pub/linux/misc/packman/suse/%2/packman.repo"));

OBSInstance::OBSInstance(QObject *parent) : QObject(parent)
{

}

OBSInstance::OBSInstance(QString name, QUrl apiRootUrl, QUrl repoRootUrl, QObject *parent): QObject(parent)
{
    this->name = name;
    this->apiRootUrl = apiRootUrl;
    this->repoRootUrl = repoRootUrl;
}

QString OBSInstance::getName()
{
    return name;
}

void OBSInstance::setName(QString name)
{
    this->name = name;
    emit nameChanged(name);
}

QUrl OBSInstance::getApiRootUrl()
{
    return apiRootUrl;
}

void OBSInstance::setApiRootUrl(QUrl apiRootUrl)
{
    this->apiRootUrl = apiRootUrl;
    emit apiRootUrlChanged(apiRootUrl);
}

/**
 * @brief OBSInstance::getRepoRootUrl
 * @return String of RPM repository URL, %1 is project (home:guoyunhe), %2 is baseproject (openSUSE:Leap:15.1)
 */
QUrl OBSInstance::getRepoRootUrl()
{
    return repoRootUrl;
}

void OBSInstance::setRepoRootUrl(QUrl repoRootUrl)
{
    this->repoRootUrl = repoRootUrl;
    emit repoRootUrlChanged(repoRootUrl);
}
