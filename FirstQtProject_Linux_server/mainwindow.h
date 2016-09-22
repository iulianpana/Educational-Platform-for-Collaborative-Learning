#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notepad.h"
#include "server.h"
#include <QDebug>
#include <unistd.h>
#include <QProcess>
#include <QDirModel>
#include <QFile>
#include <course.h>
#include <QRegularExpression>
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Notepad *getMyDialog() const;
    void setMyDialog(Notepad *value);
    int studentCount(QString courseName);

private slots:
    void on_actionOpen_File_triggered();
    void on_actionStart_Sever_triggered();
    void readFromSocket();
    void on_actionAdd_Course_triggered();
    void on_actionEnrol_Student_triggered();
    void on_actionAdd_Assignement_triggered();
    void on_actionCreate_branches_for_assignement_triggered();
    void on_actionRefresh_triggered();
    Course *getCourseByName(QString courseName);
    void updateDatabase(QDir *dir);
private:
    Ui::MainWindow *ui;
    Notepad *myDialog;
    QList<Course> courseDatabase;

};

#endif // MAINWINDOW_H
