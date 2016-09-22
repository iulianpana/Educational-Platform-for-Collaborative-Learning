#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notepad.h"
#include <qprocess.h>
#include <qdir.h>
#include "notepad.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    username = new QString(QInputDialog::getText(this,"Username","Enter username!"));
    if(username->isEmpty())
    {
        return;
    }

    QFile databaseFile(".CourseDatabase_" + *username);

    if(!databaseFile.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file CourseDatabase! Please connect to server or update file location to current location!"));
    }
    else
        //update
    {
        QTextStream in(&databaseFile);
        QString fileline ;
        Course *tmpCourse=NULL;
        while((fileline = in.readLine()).isNull() != true){
            qDebug() << fileline;

            if(fileline.contains("course_id",Qt::CaseInsensitive))
            {
                if(tmpCourse != NULL)
                    (this->courses) << *tmpCourse;

                tmpCourse = new Course();
                tmpCourse->setCourseName(new QString((fileline.split("=")).at(1)));
                tmpCourse->setAssignement_id( new QList<QString>);
                tmpCourse->setAssignment_link( new QList<QString>);
                tmpCourse->setBranch( new QList<QString>);
            }//read project assignements
            if(fileline.contains("assignement_id",Qt::CaseInsensitive))
            {

                QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
                tmpCourse->addAssignement_id(tmp.at(2));
            }

            if(fileline.contains("assignement_link",Qt::CaseInsensitive))
            {

                QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
                tmpCourse->addAssignment_link(tmp.at(2));

            }

            if(fileline.contains("branch_id",Qt::CaseInsensitive))
            {

                QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
                tmpCourse->addBranch(tmp.at(2));

            }
        }
        if(tmpCourse!=NULL)
            courses.append(*tmpCourse);

    }
    Course course;
    ui->treeWidget->setHeaderLabels(QStringList()<<"Projects" << "Description");
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    if(!courses.isEmpty())
    {  foreach (course, courses) {
            QTreeWidgetItem *childCourse = new QTreeWidgetItem(ui->treeWidget);
            childCourse->setText(0, * course.getCourseName());
            childCourse->setExpanded(true);
            QString urlProject;
            foreach (urlProject, *(course.getAssignement_id())) {
                QTreeWidgetItem *projectUrl = new QTreeWidgetItem(childCourse);
                projectUrl->setText(0, urlProject);
            }
        }
    }
    else
        qDebug()<<"no assignements";
    //git part
    git_libgit2_init();

    projectDir = new QDir();
    if(!projectDir->exists(".Projects_" + *username))
    {
        projectDir->mkdir(".Projects_" + *username);
    }
    rightClickMenu = new QMenu(this);
    rightClickMenu->setContextMenuPolicy(Qt::CustomContextMenu);
    rightClickMenu->addAction("Open Project",this,SLOT(openProject()));
    rightClickMenu->addAction("Refresh", this, SLOT(Refresh()));
    rightClickMenu->addAction("Check for assignements",this,SLOT(on_actionConnect_To_Server_triggered()));
}

MainWindow::~MainWindow()
{
    git_libgit2_shutdown();
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered(){
    Notepad *Dialog = new Notepad();
    Dialog->setWindowFlags(Qt::Window );//for minimize/maximize button
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), QString(),
                                                    tr("Any (*);;C++ Files (*.cpp *.h);;Text Files (*.txt)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        Dialog->setCurrentFileName(fileName);
        Dialog->setTextEdit(&file);
        Dialog->showMaximized();
        file.close();
    }
}

Notepad *MainWindow::getMyDialog() const
{
    return myDialog;
}

void MainWindow::setMyDialog(Notepad *value)
{
    myDialog = value;
}

void MainWindow::on_actionConnect_To_Server_triggered()
{
    Client *client = new Client();
    client->setUsername(*username);
    client->show();

}

void MainWindow::on_actionMain_Page_triggered()
{
    showMaximized();
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    if(!index.isValid())
        return;
    if(ui->treeWidget->selectedItems().at(0)->parent() == NULL)
        rightClickMenu->actions().at(0)->setEnabled(false);
    else
        rightClickMenu->actions().at(0)->setEnabled(true);

    rightClickMenu->exec(QCursor::pos());
}

void MainWindow::addNewAssignements()
{

    QTreeWidgetItem* crtItem = ui->treeWidget->selectedItems().at(0), *crtCourseWidget;
    QString courseParam ;
    if(crtItem->parent() == NULL)
        //is course
    {
        crtCourseWidget = crtItem;
    }
    else//is project
    {
        crtCourseWidget = crtItem->parent();
    }
    courseParam = crtCourseWidget->text(0);


    //if course name matches the one selected from the main page
    //initialize the projects that are not created
    //synchronyze with the rest

    //    char *courseName = courseParam.toLocal8Bit().data();
    char path[1200] ;
    Course *crtCourse,aux;
    foreach (aux, courses) {
        if(*(aux.getCourseName()) == courseParam )
        {  crtCourse=&aux;
            break;
        }
    }
    QDir *dir = new QDir(projectDir->absolutePath() +"/.Projects_" +*username +"/" +  courseParam.toLocal8Bit().data() + "/");

    strcpy(path,dir->absolutePath().toLocal8Bit().data());

    for(int i=0;i<crtCourse->getAssignment_link()->size();i++){
        //foreach child check if git repo for project name exists
        QString projectName = crtCourse->getAssignment_link()->at(i).split("/").at(
                    crtCourse->getAssignment_link()->at(i).split("/").size()-1);

        //make local copy of path for every project
        char generalPathCopy [1200];//local copy with parent path
        strcpy(generalPathCopy,path);
        strcat(generalPathCopy,"/");//add delimitator

        if(dir->entryList(QDir::NoDotAndDotDot | QDir::AllEntries).contains(projectName) == false)
        {//if project dir does not exists,then create
            strcat(generalPathCopy, projectName.toLocal8Bit().data());

            //QString aux;
            //foreach (aux, crtCourse->getProjects()) {
            //            char initcommand[1200] = "git init ";

            //            strcat (initcommand, generalPathCopy);
            //            strcat (initcommand, " ");
            //            qDebug() << initcommand;
            //            system(initcommand);
            //            //            int error = git_clone(&repo,crtCourse->getProjects().at(i).toLocal8Bit().data(),generalPathCopy,NULL );
            //            if (error != 0) {
            //                const git_error *err = giterr_last();
            //                if (err) printf("ERROR %d: %s\n", err->klass, err->message);
            //                else printf("ERROR %d: no detailed info\n", error);
            //            }
            //else if (repo) git_repository_free(repo);
            //qDebug()<<"Succesfull clone!";
            setCrtCourse(crtCourse);
            setCrtCourseWidget(crtCourseWidget);
            setCrtProjectPath(QString(generalPathCopy));
            //}
        }
        else
            qDebug()<<"Already there";
    }
}

void MainWindow::openProject()
{   QString crtProjectName = ui->treeWidget->selectedItems().at(0)->text(0);
    QString courseName = ui->treeWidget->selectedItems().at(0)->parent()->text(0);
    QString projectPath =  projectDir->absolutePath() +"/Projects_"+*username +"/" +
            courseName + "/" +
            crtProjectName;
    foreach(Course course, courses)
    {
        if((course.getCourseName()) == courseName)
        {
            setCrtCourse(&course);
            break;
        }
    }
    QDir *dir = new QDir();
    //mkdir project
    if(!dir->exists(projectPath))
    {
        if(dir->mkpath(projectPath)==true)
            qDebug() << "succes";
        else
        {qDebug()<<"fail";
            return;
        }
    }


    //else;

    git_repository *repo;
    //initialize new repo
    if(git_repository_init(&repo,projectPath.toLocal8Bit().data(),false) == 0)
    {
        qDebug()<<"Succesful initilization of repo!" << projectPath;
    }
    QString branch,link;
    int ind;
    //find branch
    if((ind = crtCourse->getAssignement_id()->indexOf(crtProjectName))!=-1)
    {

        branch = crtCourse->getBranch()->at(ind);
        link = crtCourse->getAssignment_link()->at(ind);
        VersionControlModule::checkoutBranchToPath(projectPath, branch, link);

    }


    Notepad *browser = new Notepad();
    browser->getDirmodel()->setRootPath(dir->absolutePath() + "/Projects_"+*username+"/" +
                                        courseName);
    QModelIndex index = browser->getDirmodel()->index(dir->absolutePath() + "/Projects_"+*username+"/" +
                                                      courseName);
    browser->setCrtIndex(index);
    browser->setRootIndex(index);
    browser->showMaximized();


}

void MainWindow::Refresh()
{
    ui->treeWidget->clear();
    courses.clear();
    QFile databaseFile(".CourseDatabase_" + *username);

    if(!databaseFile.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file CourseDatabase! Please connect to server or update file location to current location!"));
    }
    QTextStream in(&databaseFile);
    QString fileline ;
    Course *tmpCourse=NULL;
    while((fileline = in.readLine()).isNull() != true){
        qDebug() << fileline;

        if(fileline.contains("course_id",Qt::CaseInsensitive))
        {
            if(tmpCourse != NULL)
                (this->courses) << *tmpCourse;

            tmpCourse = new Course();
            tmpCourse->setCourseName(new QString((fileline.split("=")).at(1)));
            tmpCourse->setAssignement_id( new QList<QString>);
            tmpCourse->setAssignment_link( new QList<QString>);
            tmpCourse->setBranch( new QList<QString>);
        }//read project assignements
        if(fileline.contains("assignement_id",Qt::CaseInsensitive))
        {

            QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
            tmpCourse->addAssignement_id(tmp.at(2));
        }

        if(fileline.contains("assignement_link",Qt::CaseInsensitive))
        {

            QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
            tmpCourse->addAssignment_link(tmp.at(2));

        }

        if(fileline.contains("branch_id",Qt::CaseInsensitive))
        {

            QList<QString> tmp = fileline.split(QRegExp("[= \t\n]"));
            tmpCourse->addBranch(tmp.at(2));

        }
    }
    if(tmpCourse!=NULL)
        courses.append(*tmpCourse);



    if(!courses.isEmpty())
    {Course course;

        foreach (course, courses) {
            QTreeWidgetItem *childCourse = new QTreeWidgetItem(ui->treeWidget);
            childCourse->setText(0, * course.getCourseName());
            childCourse->setExpanded(true);
            QString urlProject;
            foreach (urlProject, *(course.getAssignement_id())) {
                QTreeWidgetItem *projectUrl = new QTreeWidgetItem(childCourse);
                projectUrl->setText(0, urlProject);
            }
        }
    }
    else
        qDebug()<<"no assignements";
}


QTreeWidgetItem *MainWindow::getCrtCourseWidget() const
{
    return crtCourseWidget;
}

void MainWindow::setCrtCourseWidget(QTreeWidgetItem *value)
{
    crtCourseWidget = value;
}
Course* MainWindow::getCrtCourse() const
{
    return crtCourse;
}

void MainWindow::setCrtCourse(Course *value)
{
    crtCourse = value;
}


QString MainWindow::getCrtProjectPath() const
{
    return crtProjectPath;
}

void MainWindow::setCrtProjectPath(const QString &value)
{
    crtProjectPath = value;
}

void MainWindow::on_actionRefresh_triggered()
{
    Refresh();

}
