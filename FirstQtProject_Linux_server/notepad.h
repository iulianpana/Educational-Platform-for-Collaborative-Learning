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
#include <unistd.h>
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
    QString getCurrentFileName() const;
    void setCurrentFileName(const QString &value);

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_NewFolder_clicked();

    void on_NewFile_clicked();

    void on_Delete_clicked();

    void updateError();

    void updateText();

    void on_Save_clicked();

    void on_Quit_clicked();

    void on_execute_clicked();

private:
    Ui::Dialog *ui;
    QFileSystemModel *dirmodel;
    QString currentFileName;
    QProcess myProcess;
    QProcess proc;
    QString data;
};

#endif // DIALOG_H
