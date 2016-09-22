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
    QDir *dir = new QDir();
    if(!dir->exists("Database"))
        dir->mkdir("Database");
    else
        updateDatabase(new QDir("Database"));


    QFileSystemModel *fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files );


    fileModel->setReadOnly(true);
    fileModel->setRootPath("Database");
    //sorted output
    ui->treeView->setSortingEnabled(true);
    fileModel->sort(0,Qt::AscendingOrder);

    ui->treeView->setModel(fileModel);

    QModelIndex index = fileModel->index("Database");
    ui->treeView->setRootIndex(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);


    ui->treeView->header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->treeView->header()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->treeView->header()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    ui->treeView->header()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->treeView->setUpdatesEnabled(true);


}


MainWindow::~MainWindow()
{
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
        //qDebug()<<file.fileName();
        Dialog->setCurrentFileName(fileName);
        Dialog->setTextEdit(&file);
        Dialog->showMaximized();
        file.close();
    }
}

int MainWindow::studentCount(QString courseName)
{
    QDir dir;
    int count=0;
    if(dir.exists("Database"+ courseName))
    {
        QFile file("Database"+ courseName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"Error!","Could not open course for read!");
            return -1;
        }
        QString line;
        while(!(line=file.readLine()).isEmpty())
        {
            if(line.contains("student_id"))
                ++count;
        }
        file.close();
    }
    return count;
}



void MainWindow::on_actionStart_Sever_triggered()
{
    Server *server = new Server();
    server->show();
}

void MainWindow::readFromSocket()
{

}


void MainWindow::on_actionAdd_Course_triggered()
{
    QString courseName  = QInputDialog::getText(this, "Course Name", "Enter a name");
    if(courseName.isEmpty())
        return;

    QDir *dir = new QDir();
    if(!dir->exists("Database/"))
        dir->mkdir("Database/");
    QFile file("Database/" + courseName);
    if(!file.open(QIODevice::ReadWrite))
    {QMessageBox::critical(this, tr("Error"), tr("Could not create file!"));
    return;}
    file.close();

    //update program database
    Course *course = new Course();
    course->setCourseName(&courseName);
    course->setAssignement_id(new QList<QString>());
    course->setAssignment_link(new QList<QString>());
    course->setBranch(new QList<QString>());
    courseDatabase.append(*course);
    Course aux;
    foreach (aux, courseDatabase) {
        qDebug()<< * aux.getCourseName();
    }
}

void MainWindow::on_actionEnrol_Student_triggered()
{
    QString courseName  = QInputDialog::getText(this, "Course Name", "Enter a name");
    if(courseName.isEmpty())
        return;

    QFile file("Database/" +  courseName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open course!"));
        return;
    }


    QFile tmp("Database/" + QString(".tmp") );
    if(!tmp.open(QIODevice::Append))
       {
        QMessageBox::critical(this, tr("Error"), tr("Could not open tmp!"));
        return;
        }
    QString studentId  = QInputDialog::getText(this, "Username Id", "Enter an id");
    if(studentId.isEmpty())
        return;

    QString line;
    QTextStream out(&file);
    QTextStream outTmp(&tmp);

    //append a new student to the database
    if((line = file.readLine()).isNull() == false)
        while(line.contains("student_id"))
        {
            outTmp<<line;
            line = file.readLine();
        }

    outTmp<<"student_id=" + studentId + "\n";
    outTmp<<"\n";

    while(!(line = file.readLine()).isEmpty())
        outTmp<<line;

    file.close();
    tmp.close();
    if(!file.open(QIODevice::WriteOnly))
       {

        QMessageBox::critical(this, tr("Error"), tr("Could not open course!"));
        return;
}
    if(!tmp.open(QIODevice::ReadOnly)){

        QMessageBox::critical(this, tr("Error"), tr("Could not open tmp!"));
    return;
    }
    while(!(line = tmp.readLine()).isEmpty())
    {
        //qDebug()<<line;
        out<<line;
    }

    file.close();
    tmp.close();
    tmp.remove();

    //if(getCourseByName(courseName)== NULL)
    //  qDebug()<<"empty";


}

Course *MainWindow::getCourseByName(QString courseName){
    Course *course = NULL, aux;

    if( courseDatabase.isEmpty())
        return NULL;
    foreach (aux, courseDatabase) {
        qDebug()<<"ceva";
        if(aux.getCourseName()->compare(courseName, Qt::CaseInsensitive) == 0)
        {
            course = &aux;
            qDebug()<< aux.getCourseName();
        }
    }
    return course;
}

void MainWindow::updateDatabase(QDir *dir)
{
    QFileInfo var;
    foreach (var, dir->entryInfoList(QDir::AllEntries)) {
        if(var.isFile())
            //qDebug()<<var.absoluteFilePath();
        {
            Course *course = new Course();
            QString fileName = var.fileName();
            course->setCourseName(&fileName);

            //courseDatabase.append(*course);
        }
    }
}

void MainWindow::on_actionAdd_Assignement_triggered()
{

    QString assignementId  = QInputDialog::getText(this, "Assignement Name", "Enter a name");
    if(assignementId.isEmpty())
        return;
    QString assignementLink  = QInputDialog::getText(this, "Assignement Link", "Enter a link");
    if(assignementLink.isEmpty())
        return;

    int teamMembers=2;

    QString mode = QInputDialog::getText(this, "Assignement Mode", "Singlecourse  or Multicourse ?");
    if(mode.isEmpty())
        return;
    //assign students to teams
    //create the nr of students/2 + 1 teams
    //assign them random
    //create branches
    if(mode.contains("multi",Qt::CaseInsensitive))
    {
        int nrOfCourses = QInputDialog::getInt(this,"Number of Courses!","Enter the number of Courses:" );

        teamMembers = nrOfCourses;

        QList<QString> courses;
        QList< QList<QString> > allStudents;

        for(int j=0;j<nrOfCourses;j++)
        {
            QString courseName  = QInputDialog::getText(this, "Course Name", "Enter a name");
            if(courseName.isEmpty())
                return;
            courses.append(courseName);
            QFile file("Database/" +  courseName);
            if(!file.open(QIODevice::ReadWrite))
            {
                QMessageBox::critical(this, tr("Error"), tr("Could not add assignement!No such course!"));
                return;
            }

            //            else
            //                qDebug()<<"succes" <<file.fileName();
            QString line;
            QList<QString> students;

            //append a new student to the database
            while(!(line = file.readLine()).isEmpty())
            {   //qDebug()<<line;
                if(line.contains("student_id") && !line.contains("team"))
                {
                    students.append(line.split(QRegularExpression("[=\n]")).at(1));
                    //qDebug()<<line.split(QRegularExpression("[=\n]"));
                }
                else
                    break;
            }
            file.close();
            //qDebug()<<students;
            allStudents.append(students);
        }

        QFile file("Database/" + courses.at(0));
        if(!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not add assignement!No such course!"));
            return;
        }
        else
            file.seek(file.size());

        QTextStream out(&file);
        out<<"\nassignement_id=" <<assignementId << "\n" << "\tassignement_link="<< assignementLink <<"\n";
        int max = 0;
        foreach(QList<QString> var,allStudents){
            max = qMax(max,var.size()) ;
        }
        QTime midnight(0, 0, 0);
        qsrand(midnight.secsTo(QTime::currentTime()));
        for(int i=0;i<max;i++)
        {
            if(allStudents.isEmpty())
                break;

            out<<"\tteam_id=team" <<i<< " ";
            //qDebug()<<"team_id=team" <<i<< " ";

            foreach (QList<QString> students, allStudents)
            {
                if(students.size() == 1)
                {   qDebug()<<"students"<<students;
                    out<<"student_id="<< students.at(0);
                    //qDebug()<<"student_id="<< students.at(randIndex)<<" ";
                    students.clear();
                    allStudents.removeOne(students);
                    continue;

                }


                int randIndex = qrand()%students.size();
                //qDebug()<<students;

                if(!students.isEmpty() )
                {   out<<"student_id="<< students.at(randIndex) << " ";
                    //qDebug()<<"student_id="<< students.at(randIndex) << "\n";
                    students.removeAt(randIndex);
                    qDebug()<<"after" << students << students.size();
                }
            }
            out<<"\n";
        }
    }

    else
        if(mode.contains("single",Qt::CaseInsensitive))
        {
            QString courseName  = QInputDialog::getText(this, "Course Name", "Enter a name");
            if(courseName.isEmpty())
                return;

            QFile file("Database/" +  courseName);
            if(!file.open(QIODevice::ReadWrite))
            {
                QMessageBox::critical(this, tr("Error"), tr("Could not add assignement!No such course!"));
                return;
            }

            else
                qDebug()<<"succes" <<file.fileName();
            QString line;
            QTextStream out(&file);
            QStringList students;

            //append a new student to the database
            while(!(line = file.readLine()).isEmpty())
            {   //qDebug()<<line;
                if(line.contains("student_id") && !line.contains("team"))
                {
                    students.append(line.split(QRegularExpression("[=\n]")).at(1));
                    //qDebug()<<line.split(QRegularExpression("[=\n]"));
                }
                else
                    continue;

            }
            out<<"\nassignement_id=" <<assignementId << "\n" << "\tassignement_link="<< assignementLink <<"\n";
            int teamNumber = students.size()/teamMembers;

            for(int i=0;i<=teamNumber;i++)
            {
                if(students.isEmpty())
                    break;
                out<<"\tteam_id=team" <<i<< " ";
                qDebug()<<"team_id=team" <<i<< " ";

                if(students.size() == 1){
                    out<<"student_id="<< students.at(0) << " ";
                    //qDebug()<<"student_id="<< students.at(randIndex)<<" ";
                    students.removeAt(0);
                    break;
                }
                QTime midnight(0, 0, 0);
                qsrand(midnight.secsTo(QTime::currentTime()));


                int randIndex;// = qrand()%students.size();

                qDebug()<<students;
                int limit = qMin(teamMembers,students.size());
                for(int j=0;j<limit;j++)
                    if(!students.isEmpty() )
                    {
                        randIndex = qrand()%students.size() ;
                        out<<"student_id="<< students.at(randIndex)<< " ";
                        //qDebug()<<"student_id="<< students.at(randIndex) << "\n";
                        students.removeAt(randIndex);
                    }
                out<<"\n";
            }
            out<<"\n";
        }
}


void MainWindow::on_actionCreate_branches_for_assignement_triggered()
{
    QString courseName  = QInputDialog::getText(this, "Course Name", "Enter a name");
    if(courseName.isEmpty())
        return;

    QFile file("Database/" +  courseName);
    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open course!"));
        return;
    }
    QString assignementName  = QInputDialog::getText(this, "Assignement Name", "Enter a name");
    if(assignementName.isEmpty())
        return;
    QString line;


    while(1){
        while(!(line = file.readLine()).isEmpty()){
            if(line.contains("assignement_id"))
                break;
        }

        QString assignementId = line.split(QRegExp("[\t\n =]")).at(1);
        line = file.readLine();
        QString assignementLink = line.split(QRegExp("[\t\n =]")).at(2);

        //identify number of teams
         int linenr = 0;
        while(!(line = file.readLine()).isEmpty()){
            if(line.contains("assignement_id"))
                break;
            if(line.contains("team"))
                linenr++;
        }
        qDebug()<<"linenr " << linenr;

        if(assignementName.compare(assignementId,Qt::CaseInsensitive) == 0)
            //run script for creating branches
        {char line[1200];

            FILE *pipe;

            /* Get a pipe where the output from the scripts comes in */
            QString script = "./ScriptBranches.sh ";

            QString command = script + assignementLink + " " +QString::number(linenr);

            qDebug()<<command.toLocal8Bit().data();
            /*
                used git config --global credential.helper store in order to enable git not to ask for my password
            */

            pipe = popen(command.toLocal8Bit().data(), "r");
            if (pipe == NULL) {  /* check for errors */
                QMessageBox::critical(this, tr("Error"), tr("Could not open pipe"));
                /* return with exit code indicating error */
            }

            /* Read script output from the pipe line by line */
            linenr = 1;
            while (fgets(line, 1200, pipe) != NULL) {
                qDebug()<<"Script output line "<< linenr<< line;
                ++linenr;
            }

            /* Once here, out of the loop, the script has ended. */
            pclose(pipe); /* Close the pipe */
            qDebug()<<"Close pipe";
            break;
        }
        else
            continue;
    }

}

void MainWindow::on_actionRefresh_triggered()
{
    ui->treeView->show();
}
