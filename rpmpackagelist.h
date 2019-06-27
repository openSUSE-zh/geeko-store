#ifndef RPMPACKAGELIST_H
#define RPMPACKAGELIST_H

#include <QObject>
#include <QQmlListProperty>

#include "obsclient.h"
#include "rpmpackage.h"

class RPMPackageList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(RPMPackage* selectedPackage READ selectedPackage WRITE setSelectedPackage NOTIFY selectedPackageChanged)
    Q_PROPERTY(QString selectedName READ selectedName WRITE setSelectedName NOTIFY selectedNameChanged)
    Q_PROPERTY(QQmlListProperty<RPMPackage> packages READ packages NOTIFY packagesChanged)
    Q_PROPERTY(QStringList names READ names NOTIFY namesChanged)
    Q_PROPERTY(bool isSearching READ isSearching NOTIFY isSearchingChanged)

public:
    explicit RPMPackageList(QObject *parent = nullptr);

    RPMPackage* selectedPackage();
    void setSelectedPackage(RPMPackage *package);

    QString selectedName();
    void setSelectedName(QString name);

    QQmlListProperty<RPMPackage> packages();
    void appendPackage(RPMPackage* p);
    int packageCount() const;
    RPMPackage* package(int index) const;
    void clearPackages();

    QStringList names();

    bool isSearching();

signals:
    void selectedPackageChanged(RPMPackage *package);
    void selectedNameChanged(QString packageName);
    void packagesChanged(QQmlListProperty<RPMPackage> packages);
    void namesChanged(QStringList names);
    void isSearchingChanged(bool isSearching);

public slots:
    void search(QString keywords);
    void receivePackages(QVector<RPMPackage*> packages);

private:
    OBSClient *obs, *pmbs;

    RPMPackage *m_selectedPackage;

    QString m_selectedName;

    QVector<RPMPackage*> m_allPackages, m_packages;

    QVector<RPMPackage*> m_Packages;

    static void appendPackage(QQmlListProperty<RPMPackage>*, RPMPackage*);
    static int packageCount(QQmlListProperty<RPMPackage>*);
    static RPMPackage* package(QQmlListProperty<RPMPackage>*, int);
    static void clearPackages(QQmlListProperty<RPMPackage>*);

    QStringList m_allNames, m_names;

    void unselect();
    void parseNames();
    void filterNames();
    void filterPackages();

    int searchProcessCounter = 0;
};

#endif // RPMPACKAGELIST_H
