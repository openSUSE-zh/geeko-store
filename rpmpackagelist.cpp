#include "rpmpackagelist.h"
#include "obsinstance.h"

RPMPackageList::RPMPackageList(QObject *parent) : QObject(parent)
{
    obs = new OBSClient(OBSInstance::OBS);
    pmbs = new OBSClient(OBSInstance::PMBS);

    connect(obs, &OBSClient::searchResultParsed, this, &RPMPackageList::receivePackages);
    connect(pmbs, &OBSClient::searchResultParsed, this, &RPMPackageList::receivePackages);
}

void RPMPackageList::search(QString keywords)
{
    m_allNames.clear();
    m_names.clear();
    m_allPackages.clear();
    m_packages.clear();

    m_selectedName = nullptr;
    m_selectedPackage = nullptr;

    obs->search(keywords);
    searchProcessCounter++;
    pmbs->search(keywords);
    searchProcessCounter++;

    emit isSearchingChanged(isSearching());
}

void RPMPackageList::receivePackages(QVector<RPMPackage*> packages)
{
    qDebug() << "receive packages";
    m_allPackages.append(packages);
    // TODO sort packages
    parseNames();

    searchProcessCounter--;
    emit isSearchingChanged(isSearching());
}

void RPMPackageList::parseNames()
{
    m_allNames.clear();
    for (int i = 0; i < m_allPackages.count(); i++) {
        RPMPackage *p = m_allPackages.at(i);
        QString name = p->getName();
        if (!m_allNames.contains(name)) {
            m_allNames << name;
        }
    }

    // TODO should sort packages, instead of names
    m_allNames.sort(Qt::CaseInsensitive);

    filterNames();
}

void RPMPackageList::filterNames()
{
    qDebug() << "filter names";
    qDebug() << m_names;
    // TODO filter names, exclude -devel, -lang, -doc, etc.
    m_names = m_allNames;
    emit namesChanged(m_names);
}

void RPMPackageList::filterPackages()
{
    m_packages.clear();
    if (!m_selectedName.isEmpty() && !m_allPackages.empty()) {
        for (int i = 0; i < m_allPackages.count(); i++) {
            RPMPackage *p = m_allPackages.at(i);
            if (p->getName() == m_selectedName) {
                m_packages << p;
            }
        }
    }
    emit packagesChanged(packages());
}

RPMPackage* RPMPackageList::selectedPackage()
{
    return m_selectedPackage;
}

void RPMPackageList::setSelectedPackage(RPMPackage *package)
{
    m_selectedPackage = package;

    emit selectedPackageChanged(package);
}

QString RPMPackageList::selectedName()
{
    return m_selectedName;
}

void RPMPackageList::setSelectedName(QString name)
{
    m_selectedName = name;
    emit selectedNameChanged(name);

    filterPackages();
}

QQmlListProperty<RPMPackage> RPMPackageList::packages()
{
    return QQmlListProperty<RPMPackage>(this, this,
                 &RPMPackageList::appendPackage,
                 &RPMPackageList::packageCount,
                 &RPMPackageList::package,
                 &RPMPackageList::clearPackages);
}

void RPMPackageList::appendPackage(RPMPackage* p)
{
    m_packages.append(p);
}

int RPMPackageList::packageCount() const
{
    return m_packages.count();
}

RPMPackage* RPMPackageList::package(int index) const
{
    return m_packages.at(index);
}

void RPMPackageList::clearPackages() {
    m_packages.clear();
}

void RPMPackageList::appendPackage(QQmlListProperty<RPMPackage>* list, RPMPackage* p) {
    reinterpret_cast< RPMPackageList* >(list->data)->appendPackage(p);
}

void RPMPackageList::clearPackages(QQmlListProperty<RPMPackage>* list) {
    reinterpret_cast< RPMPackageList* >(list->data)->clearPackages();
}

RPMPackage* RPMPackageList::package(QQmlListProperty<RPMPackage>* list, int i) {
    return reinterpret_cast< RPMPackageList* >(list->data)->package(i);
}

int RPMPackageList::packageCount(QQmlListProperty<RPMPackage>* list) {
    return reinterpret_cast< RPMPackageList* >(list->data)->packageCount();
}

QStringList RPMPackageList::names()
{
    return m_names;
}

bool RPMPackageList::isSearching()
{
    return searchProcessCounter > 0;
}
