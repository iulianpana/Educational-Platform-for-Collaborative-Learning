#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notepad.h"
#include <QDebug>
#include "client.h"
#include <course.h>
#include <QComboBox>
#include <QTreeWidgetItem>
#include <QtGui>
#include <git2.h>
#include <git2/clone.h>
#include <versioncontrolmodule.h>
#define LOCAL_SERVER_PORT 5000
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

    Course *getCrtCourse() const;
    void setCrtCourse(Course *value);


    QTreeWidgetItem *getCrtCourseWidget() const;
    void setCrtCourseWidget(QTreeWidgetItem *value);

    QString getCrtProjectPath() const;
    void setCrtProjectPath(const QString &value);

private slots:
    void on_actionOpen_File_triggered();

    void on_actionConnect_To_Server_triggered();

    void on_actionMain_Page_triggered();

    void on_treeWidget_clicked(const QModelIndex &index);

    void addNewAssignements();

    void openProject();

    void Refresh();


    void on_actionRefresh_triggered();

private:
    Ui::MainWindow *ui;
    Notepad *myDialog;
    QString *username;
    QList<Course> courses ;
    QDir *projectDir;
    QMenu *rightClickMenu;
    Course *crtCourse;
    QTreeWidgetItem* crtCourseWidget;
    QString crtProjectPath;
};

#endif // MAINWINDOW_H
