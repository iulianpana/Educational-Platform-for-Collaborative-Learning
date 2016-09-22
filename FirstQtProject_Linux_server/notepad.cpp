#include "notepad.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QWidget>
#include <QStandardPaths>
#include <iostream>
Notepad::Notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //https://www.youtube.com/watch?v=92biLZST6Vg
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath("C:/");
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files );

    ui->treeView->resizeColumnToContents(2);
    ui->treeView->setModel(dirmodel);
    //http://www.bogotobogo.com/Qt/Qt5_QTreeView_QDirModel_ModelView_MVC.php
    //in order to manipulate the filesystem
    dirmodel->setReadOnly(false);

    //sorted output
    ui->treeView->setSortingEnabled(true);
    dirmodel->sort(0,Qt::AscendingOrder);

    // Set initial selection
    QFileInfo *info = new QFileInfo(getCurrentFileName());

    QModelIndex index;
    if(info->exists()==true)
        index = dirmodel->index(getCurrentFileName());
    else
        index = dirmodel->index("C:/");
    // Set initial view of directory
    // for the selected drive as expanded
    ui->treeView->expand(index);

    // Make it scroll to the selected
    ui->treeView->scrollTo(index);

    // Highlight the selected
    ui->treeView->setCurrentIndex(index);

    // Resizing the column - first column
    ui->treeView->header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->treeView->header()->setSectionResizeMode(1,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->treeView->header()->setSectionResizeMode(2,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->treeView->header()->setSectionResizeMode(3,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    setWindowTitle("Notepad");

    }

Notepad::~Notepad()
{
    delete ui;
}

Ui::Dialog *Notepad::getUi() const
{
    return ui;
}

void Notepad::setUi(Ui::Dialog *value)
{
    ui = value;
}

void Notepad::setTextEdit(QFile* file)
{
    QTextStream in(file);
    ui->textEdit->setText(in.readAll());
}

QString Notepad::getCurrentFileName() const
{
    return currentFileName;
}

void Notepad::setCurrentFileName(const QString &value)
{
    currentFileName = value;
}
void Notepad::on_treeView_clicked(const QModelIndex &index)
{
    // TreeView clicked
    // 1. We need to extract path
    // 2. Set that path into our ListView

    // Get the full path of the item that's user clicked on
    //QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    if(dirmodel->fileInfo(index).isDir())
    { // directory
    }
    else
    {
        // file
        QFile fileLocal(dirmodel->fileInfo(index).absoluteFilePath());

        if (!fileLocal.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        Notepad::setTextEdit(&fileLocal);
        Notepad::setCurrentFileName(fileLocal.fileName());
        qDebug()<<getCurrentFileName();
        fileLocal.close();
    }

}
void Notepad::on_NewFolder_clicked()
{
    // Make directory
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    QString name  = QInputDialog::getText(this, "Name", "Enter a name");
    if(name.isEmpty())
        return;
    dirmodel->mkdir(index, name);
}
void Notepad::on_NewFile_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;

    QString name  = QInputDialog::getText(this, "Name", "Enter a name");
    if(name.isEmpty())
        return;

    dirmodel->setReadOnly(false);
    QFile file( dirmodel->filePath(index) + QDir::separator() + name );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QMessageBox msgBox;
        msgBox.setText("Created file "+ file.fileName());
        msgBox.exec();
    }
    file.close();
}

void Notepad::on_Delete_clicked()
{    // Get the current selection
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;
    if(dirmodel->fileInfo(index).isDir())
    {        // directory
        dirmodel->rmdir(index);
    }
    else
    {   // file
        dirmodel->remove(index);
    }
}

void Notepad::updateError()
{
    QByteArray data = myProcess.readAllStandardError();
    qDebug() << data;
    ui->compiler->append(QString(data));
//    if(myProcess.isOpen())
//        myProcess.close();
}

void Notepad::updateText()
{
    QByteArray data = myProcess.readAllStandardOutput();
    qDebug() << data;
    ui->compiler->append(QString(data));

    ui->command->clear();
    ui->parameters->clear();
//    if(myProcess.isOpen())
//        myProcess.close();
}

void Notepad::on_Save_clicked()
{
    QFile file(getCurrentFileName());
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug()<< "error message";
        ui->textEdit->append(QString("Error handling file!\n"));
    } else {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        stream.flush();
        file.close();
    }
}

void Notepad::on_Quit_clicked()
{
    ui->textEdit->clear();
    (QFile(getCurrentFileName())).close();
}


void Notepad::on_execute_clicked()
{
        QString program=QStandardPaths::findExecutable(ui->command->toPlainText());
        qDebug()<<program;
        QCoreApplication::processEvents();
        myProcess.setProcessChannelMode(QProcess::MergedChannels);
        qDebug() << connect(&myProcess, SIGNAL(readyReadStandardError()), this, SLOT(updateError()));
        qDebug() << connect(&myProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(updateText()));
        QStringList params = QStringList() << ui->parameters->toPlainText();// << "  2>&1 >1";
        myProcess.start(program,params);


}
