#ifndef OBSINSTANCE_H
#define OBSINSTANCE_H

#include <QObject>
#include <QUrl>

class OBSInstance : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QUrl apiRootUrl READ getApiRootUrl)
    Q_PROPERTY(QUrl repoRootUrl READ getRepoRootUrl)

public:
    explicit OBSInstance(QString name, QUrl apiRootUrl, QUrl repoRootUrl, QString distPrefix = "", QObject *parent = nullptr);

    QString getName();
    QUrl getApiRootUrl();
    QUrl getRepoRootUrl();
    QString getDistPrefix();

    static OBSInstance* OBS;
    static OBSInstance* PMBS;

signals:

public slots:

private:
    QString name;
    QUrl apiRootUrl;
    QUrl repoRootUrl;
    QString distPrefix;
};

#endif // OBSINSTANCE_H
