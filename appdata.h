#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>

#include "obsinstance.h"
#include "rpmpackage.h"

class AppData : public QObject
{
    Q_OBJECT

public:
    explicit AppData(QObject *parent = nullptr);

signals:

public slots:

private:
};

#endif // APPDATA_H
