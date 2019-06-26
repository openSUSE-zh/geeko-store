#include "rpmpackage.h"

RPMPackage::RPMPackage(QObject *parent) : QObject(parent)
{

}

RPMPackage::RPMPackage(const QXmlStreamAttributes attributes, const OBSInstance *obsInstance, QObject *parent) : QObject(parent)
{
    name = attributes.value("name").toString();
    project = attributes.value("project").toString();
    package = attributes.value("package").toString();
    repository = attributes.value("repository").toString();
    version = attributes.value("version").toString();
    release = attributes.value("release").toString();
    arch = attributes.value("arch").toString();
    fileName = attributes.value("filename").toString();
    filePath = attributes.value("filepath").toString();
    baseProject = attributes.value("baseproject").toString();
    this->obsInstance = obsInstance;
}

RPMPackage::RPMPackage(const RPMPackage& other, QObject *parent) : QObject(parent)
{
    copy(other);
}

RPMPackage& RPMPackage::operator=(const RPMPackage& other)
{
    copy(other);
    return *this;
}

void RPMPackage::copy(const RPMPackage& other)
{
    name = other.name;
    project = other.project;
    package = other.package;
    repository = other.repository;
    version = other.version;
    release = other.release;
    arch = other.arch;
    fileName = other.fileName;
    filePath = other.filePath;
    baseProject = other.baseProject;
    obsInstance = other.obsInstance;
}

QString RPMPackage::getName() {
    return name;
}

void RPMPackage::setName(QString name) {
    this->name = name;
    emit nameChanged(name);
}

QString RPMPackage::getProject() {
    return project;
}

void RPMPackage::setProject(QString project) {
    this->project = project;
    emit projectChanged(project);
}

QString RPMPackage::getPackage() {
    return package;
}

void RPMPackage::setPackage(QString package) {
    this->package = package;
    emit packageChanged(package);
}

QString RPMPackage::getRepository() {
    return repository;
}

void RPMPackage::setRepository(QString repository) {
    this->repository = repository;
    emit repositoryChanged(repository);
}

QString RPMPackage::getVersion() {
    return version;
}

void RPMPackage::setVersion(QString version) {
    this->version = version;
    emit versionChanged(version);
}

QString RPMPackage::getRelease() {
    return release;
}

void RPMPackage::setRelease(QString release) {
    this->release = release;
    emit releaseChanged(release);
}

QString RPMPackage::getArch() {
    return arch;
}

void RPMPackage::setArch(QString arch) {
    this->arch = arch;
    emit archChanged(arch);
}

QString RPMPackage::getFileName() {
    return fileName;
}

void RPMPackage::setFileName(QString fileName) {
    this->fileName = fileName;
    emit fileNameChanged(fileName);
}

QString RPMPackage::getFilePath() {
    return filePath;
}

void RPMPackage::setFilePath(QString filePath) {
    this->filePath = filePath;
    emit filePathChanged(filePath);
}

QString RPMPackage::getBaseProject() {
    return baseProject;
}

void RPMPackage::setBaseProject(QString baseProject) {
    this->baseProject = baseProject;
    emit baseProjectChanged(baseProject);
}

QString RPMPackage::getType() {
    return type;
}

void RPMPackage::setType(QString type) {
    this->type = type;
    emit typeChanged(type);
}

const OBSInstance* RPMPackage::getObsInstance() {
    return obsInstance;
}

void RPMPackage::setObsInstance(const OBSInstance* obsInstance) {
    this->obsInstance = obsInstance;
    emit obsInstanceChanged(obsInstance);
}

RPMPackage::ProjectType RPMPackage::getProjectType()
{
    if (project.left(9) == "openSUSE:") {
        return OfficialProject;
    }

    if (project.left(5) == "home:") {
        return PersonalProject;
    }

    if (project.left(4) == "isv:") {
        return VendorProject;
    }

    return DevelopmentProject;
}

RPMPackage::PackageType RPMPackage::getPackageType()
{
    if (arch == "src") {
        return SourcePackage;
    }

    if (name.left(3) == "lib") {
        return LibraryPackage;
    }

    if (name.right(4) == "-doc" || name.right(5) == "-docs") {
        return DocumentPackage;
    }

    if (name.right(5) == "-lang") {
        return LanguagePackage;
    }

    if (name.right(5) == "-font" || name.right(6) == "-fonts") {
        return FontPackage;
    }

    if (name.right(6) == "-devel") {
        return DevelopmentPackage;
    }

    if (name.right(6) == "-debuginfo") {
        return DebugInfoPackage;
    }

    return NormalPackage;
}
