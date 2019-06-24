#include "rpmpackage.h"

RPMPackage::RPMPackage(QObject *parent) : QObject(parent)
{

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

QString RPMPackage::getObsInstance() {
    return obsInstance;
}

void RPMPackage::setObsInstance(QString obsInstance) {
    this->obsInstance = obsInstance;
    emit obsInstanceChanged(obsInstance);
}
