#ifndef OBSINSTANCE_H
#define OBSINSTANCE_H

#include <QObject>
#include <QUrl>

class OBSInstance : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl apiRootUrl READ getApiRootUrl WRITE setApiRootUrl NOTIFY apiRootUrlChanged)
    Q_PROPERTY(QUrl repoRootUrl READ getRepoRootUrl WRITE setRepoRootUrl NOTIFY repoRootUrlChanged)

public:
    explicit OBSInstance(QObject *parent = nullptr);
    explicit OBSInstance(QString name, QUrl apiRootUrl, QUrl repoRootUrl, QObject *parent = nullptr);

    QString getName();
    void setName(QString name);

    QUrl getApiRootUrl();
    void setApiRootUrl(QUrl apiRootUrl);

    QUrl getRepoRootUrl();
    void setRepoRootUrl(QUrl repoRootUrl);

    static OBSInstance* OBS;
    static OBSInstance* PMBS;

signals:
    void nameChanged(QString name);
    void apiRootUrlChanged(QUrl apiRootUrl);
    void repoRootUrlChanged(QUrl repoRootUrl);

public slots:

private:
    QString name;
    QUrl apiRootUrl;
    QUrl repoRootUrl;
};

#endif // OBSINSTANCE_H
