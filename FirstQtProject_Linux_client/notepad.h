#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QDebug>
#include <QInputDialog>
#include <QProcess>
#include <QToolBar>
#include <QMenu>
#include <git2.h>
#include <versioncontrolmodule.h>

namespace Ui {
class Dialog;
}

class Notepad : public QDialog
{
    Q_OBJECT

public:

    explicit Notepad(QWidget *parent = 0);
    ~Notepad();
    void on_Open_clicked();
    Ui::Dialog *getUi() const;
    void setUi(Ui::Dialog *value);
    void setTextEdit(QFile* file);
    QString getCurrentFilePathString() const;
    void setCurrentFileName(const QString &value);


    QFileSystemModel *getDirmodel() const;
    void setDirmodel(QFileSystemModel *value);

    QModelIndex getCrtIndex() const;
    void setCrtIndex(const QModelIndex &value);
    void setRootIndex(const QModelIndex &value);

private slots:
    void pushAllModifications();
    void pullAllModifications();

    void on_browser_clicked(const QModelIndex &index);

    void newFolder();

    void newFile();

    void Delete();

    void updateError();

    void updateText();

    void save();

    void quit();

    void on_execute_clicked();

    void customContextMenuRequested(const QPoint &pos);

    void on_browser_doubleClicked(const QModelIndex &index);

    void on_editWindow_customContextMenuRequested(const QPoint &pos);

    void commitLocalChanges();
private:
    Ui::Dialog *ui;
    QFileSystemModel *dirmodel;
    QString currentFileName;
    QProcess myProcess;
    QProcess proc;
    QString data;
    QModelIndex crtIndex;
    QMenu* rightClickMenuBrowser,*rightClickMenuEditor;
};

#endif // DIALOG_H
