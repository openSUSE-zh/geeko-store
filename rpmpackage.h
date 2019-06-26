#ifndef RPMPACKAGE_H
#define RPMPACKAGE_H

#include <QObject>
#include <QXmlStreamAttributes>

#include "obsinstance.h"

class RPMPackage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString project READ getProject WRITE setProject NOTIFY projectChanged)
    Q_PROPERTY(QString package READ getPackage WRITE setPackage NOTIFY packageChanged)
    Q_PROPERTY(QString repository READ getRepository WRITE setRepository NOTIFY repositoryChanged)
    Q_PROPERTY(QString version READ getVersion WRITE setVersion NOTIFY versionChanged)
    Q_PROPERTY(QString release READ getRelease WRITE setRelease NOTIFY releaseChanged)
    Q_PROPERTY(QString arch READ getArch WRITE setArch NOTIFY archChanged)
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString filePath READ getFilePath WRITE setFilePath NOTIFY filePathChanged)
    Q_PROPERTY(QString baseProject READ getBaseProject WRITE setBaseProject NOTIFY baseProjectChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(const OBSInstance *obsInstance READ getObsInstance WRITE setObsInstance NOTIFY obsInstanceChanged)
    Q_PROPERTY(ProjectType projectType READ getProjectType)
    Q_PROPERTY(PackageType packageType READ getPackageType)

public:
    RPMPackage(QObject *parent = nullptr);
    RPMPackage(const QXmlStreamAttributes attributes, const OBSInstance *obsInstance = nullptr, QObject *parent = nullptr);
    RPMPackage(const RPMPackage& other, QObject *parent = nullptr);
    RPMPackage& operator=(const RPMPackage& other);

    enum ProjectType { OfficialProject, DevelopmentProject, PersonalProject, VendorProject };
    Q_ENUM(ProjectType)
    enum PackageType { NormalPackage, LibraryPackage, LanguagePackage, DocumentPackage, FontPackage, DevelopmentPackage, DebugInfoPackage, SourcePackage };
    Q_ENUM(PackageType)

    void copy(const RPMPackage& other);

    QString getName();
    void setName(QString name);

    QString getProject();
    void setProject(QString project);

    QString getPackage();
    void setPackage(QString package);

    QString getRepository();
    void setRepository(QString repository);

    QString getVersion();
    void setVersion(QString version);

    QString getRelease();
    void setRelease(QString release);

    QString getArch();
    void setArch(QString arch);

    QString getFileName();
    void setFileName(QString fileName);

    QString getFilePath();
    void setFilePath(QString filePath);

    QString getBaseProject();
    void setBaseProject(QString baseProject);

    QString getType();
    void setType(QString type);

    const OBSInstance* getObsInstance();
    void setObsInstance(const OBSInstance *obsInstance);

    ProjectType getProjectType();
    PackageType getPackageType();

signals:
    void nameChanged(QString name);
    void projectChanged(QString project);
    void packageChanged(QString package);
    void repositoryChanged(QString repository);
    void versionChanged(QString version);
    void releaseChanged(QString release);
    void archChanged(QString arch);
    void fileNameChanged(QString fileName);
    void filePathChanged(QString filePath);
    void baseProjectChanged(QString baseProject);
    void typeChanged(QString type);
    void obsInstanceChanged(const OBSInstance *obsInstance);

public slots:

private:
    QString name;
    QString project;
    QString package;
    QString repository;
    QString version;
    QString release;
    QString arch;
    QString fileName;
    QString filePath;
    QString baseProject;
    QString type;
    const OBSInstance *obsInstance;
};

#endif // RPMPACKAGE_H
