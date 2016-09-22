#ifndef VERSIONCONTROLMODULE_H
#define VERSIONCONTROLMODULE_H
#include <QString>
#include <QProcess>
#include <git2.h>
#include <QDebug>
class VersionControlModule
{
public:
    VersionControlModule();
    static void checkoutBranchToPath(QString projectPath, QString branch, QString link);
    static bool push(QString dirPath);
    static bool pull(QString dirPath);
};

#endif // VERSIONCONTROLMODULE_H
