#include "obsinstance.h"

OBSInstance* OBSInstance::OBS = new OBSInstance(QString("openSUSE"), QUrl("https://build.opensuse.org/"), QUrl("https://download.opensuse.org/repositories/%1/%2/%1.repo"));
OBSInstance* OBSInstance::PMBS = new OBSInstance(QString("Packman"), QUrl("https://pmbs.links2linux.de/"), QUrl("https://ftp.gwdg.de/pub/linux/misc/packman/suse/%2/packman.repo"), QString("openSUSE.org:"));

/**
 * @brief OBSInstance::OBSInstance
 * @param name
 * @param apiRootUrl
 * @param repoRootUrl
 * @param distPrefix Other OBS instance need a prefix "openSUSE.org:"
 * @param parent
 */
OBSInstance::OBSInstance(QString name, QUrl apiRootUrl, QUrl repoRootUrl, QString distPrefix, QObject *parent): QObject(parent)
{
    this->name = name;
    this->apiRootUrl = apiRootUrl;
    this->repoRootUrl = repoRootUrl;
    this->distPrefix = distPrefix;
}

QString OBSInstance::getName()
{
    return name;
}

QUrl OBSInstance::getApiRootUrl()
{
    return apiRootUrl;
}

/**
 * @brief OBSInstance::getRepoRootUrl
 * @return String of RPM repository URL, %1 is project (home:guoyunhe), %2 is baseproject (openSUSE:Leap:15.1)
 */
QUrl OBSInstance::getRepoRootUrl()
{
    return repoRootUrl;
}

QString OBSInstance::getDistPrefix()
{
    return distPrefix;
}
