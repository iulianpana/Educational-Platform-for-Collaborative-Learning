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
    dirmodel->setRootPath(QDir::currentPath());
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files );
    ui->browser->setModel(dirmodel);

    //http://www.bogotobogo.com/Qt/Qt5_QTreeView_QDirModel_ModelView_MVC.php
    //in order to manipulate the filesystem
    dirmodel->setReadOnly(false);

    //sorted output
    ui->browser->setSortingEnabled(true);
    dirmodel->sort(0,Qt::AscendingOrder);

    // Set initial selection
//    QFileInfo *info = new QFileInfo(getCurrentFilePathString());

//    QModelIndex index;
//    if(info->exists()==true)
//        index = dirmodel->index(getCurrentFilePathString());
//    else
//        index = dirmodel->index("C:/");
     QModelIndex index = dirmodel->index(QDir::currentPath());
    // Set initial view of directory
    // for the selected drive as expanded
     ui->browser->setRootIndex(index);
    ui->browser->expand(index);

    // Make it scroll to the selected
    ui->browser->scrollTo(index);

    // Highlight the selected
    ui->browser->setCurrentIndex(index);

    // Resizing the column - first column
    ui->browser->header()->setSectionResizeMode(0,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->browser->header()->setSectionResizeMode(1,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->browser->header()->setSectionResizeMode(2,QHeaderView::ResizeToContents);//resizeColumnToContents(0);
    ui->browser->header()->setSectionResizeMode(3,QHeaderView::ResizeToContents);//resizeColumnToContents(0);

    setWindowTitle("Notepad");
    
    rightClickMenuBrowser = new QMenu(this);
    ui->editWindow->setContextMenuPolicy(Qt::CustomContextMenu);
    rightClickMenuEditor = new QMenu(this);

    rightClickMenuBrowser->setContextMenuPolicy(Qt::CustomContextMenu);
    rightClickMenuEditor->setContextMenuPolicy(Qt::CustomContextMenu);

    rightClickMenuBrowser->addAction("New Folder",this,SLOT(newFolder()));
    rightClickMenuBrowser->addAction("New File",this,SLOT(newFile()));
    rightClickMenuBrowser->addAction("Delete",this,SLOT(Delete()));
    rightClickMenuBrowser->addAction("Upload modifications",this, SLOT(pushAllModifications()));
    rightClickMenuBrowser->addAction("Download modifications",this, SLOT(pullAllModifications()));

    rightClickMenuEditor->addAction("Save",this,SLOT(save()));
    rightClickMenuEditor->addAction("Quit",this,SLOT(quit()));
    rightClickMenuEditor->addAction("Commit this file", this,SLOT(commitLocalChanges()));

}

void Notepad::pushAllModifications(){
    QString dirPath = dirmodel->fileInfo(ui->browser->currentIndex()).absolutePath();
    qDebug()<<dirPath;
    VersionControlModule::push(dirPath);
}

void Notepad::pullAllModifications(){
    QString dirPath = dirmodel->fileInfo(ui->browser->currentIndex()).absolutePath();
    //qDebug()<<dirPath;

    VersionControlModule::pull(dirPath);
}
QFileSystemModel *Notepad::getDirmodel() const
{
    return dirmodel;
}

void Notepad::setDirmodel(QFileSystemModel *value)
{
    dirmodel = value;
}



Notepad::~Notepad()
{
    delete ui;
}

Ui::Dialog *Notepad::getUi() const
{
    return ui;
}
QModelIndex Notepad::getCrtIndex() const
{
    return crtIndex;
}

void Notepad::setCrtIndex(const QModelIndex &value)
{
    crtIndex = value;
    ui->browser->expand(crtIndex);

    // Make it scroll to the selected
    ui->browser->scrollTo(crtIndex);

    // Highlight the selected
    ui->browser->setCurrentIndex(crtIndex);
}

void Notepad::setRootIndex(const QModelIndex &value)
{
    ui->browser->setRootIndex(value);
}
void Notepad::setUi(Ui::Dialog *value)
{
    ui = value;
}

void Notepad::setTextEdit(QFile* file)
{
    QTextStream in(file);
    ui->editWindow->setText(in.readAll());
}

QString Notepad::getCurrentFilePathString() const
{
    return currentFileName;
}

void Notepad::setCurrentFileName(const QString &value)
{
    currentFileName = value;
}
void Notepad::on_browser_clicked(const QModelIndex &index)
{
    if(!index.isValid()) return;

    if(dirmodel->fileInfo(index).isDir())
    { // directory
    }
    else
    {   // file
        QFile fileLocal(dirmodel->fileInfo(index).absoluteFilePath());
        if (!fileLocal.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        Notepad::setTextEdit(&fileLocal);
        Notepad::setCurrentFileName(fileLocal.fileName());
        fileLocal.close();
    }

}

void Notepad::newFolder()
{
    // Make directory
    QModelIndex index = ui->browser->currentIndex();
    if(!index.isValid())
        return;
    QString name  = QInputDialog::getText(this, "Name", "Enter a name");
    if(name.isEmpty())
        return;

    dirmodel->mkdir(index, name);
}
void Notepad::newFile()
{
    QModelIndex index = ui->browser->currentIndex();
    if(!index.isValid()) return;

    QString name  = QInputDialog::getText(this, "Name", "Enter a name");
    if(name.isEmpty())
        return;
    QFile file( dirmodel->filePath(index) + QDir::separator() + name );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QMessageBox msgBox;
        msgBox.setText("Created file "+ file.fileName());
        msgBox.exec();
    }
    file.close();
}

void Notepad::Delete()
{    // Get the current selection
    QModelIndex index = ui->browser->currentIndex();
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
    ui->editWindow->clear();
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
}

void Notepad::save()
{
    QFile file(getCurrentFilePathString());
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this,tr("Error"), tr("Handling the file!"));
    } else {
        QTextStream stream(&file);
        stream << ui->editWindow->toPlainText();
        stream.flush();
        file.close();
    }
}

void Notepad::quit()
{
    ui->editWindow->clear();
    (QFile(getCurrentFilePathString())).close();
}

void Notepad::on_execute_clicked()
{
    QString program=QStandardPaths::findExecutable(ui->command->toPlainText());
    qDebug()<<program;
    QCoreApplication::processEvents();
    myProcess.setProcessChannelMode(QProcess::MergedChannels);
    qDebug() << connect(&myProcess, SIGNAL(readyReadStandardError()), this, SLOT(updateError()));
    qDebug() << connect(&myProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(updateText()));
    QStringList params = QStringList() << ui->parameters->toPlainText() ;//<< "  2>&1 >1";
    myProcess.start(program,params);


}

void Notepad::customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"\nMenu\n";
    rightClickMenuBrowser->exec(mapToGlobal(pos));
}

void Notepad::on_browser_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
        return;
    rightClickMenuBrowser->exec(QCursor::pos());
}

void Notepad::on_editWindow_customContextMenuRequested(const QPoint &pos)
{
    rightClickMenuEditor->exec(QCursor::pos());
}

void Notepad::commitLocalChanges()
{
    QModelIndex indexFile = ui->browser->currentIndex();
//    /*QString fileName = dirmodel->fileInfo(indexFile).fileName();
//    QDir dir = dirmodel->fileInfo(ui->browser->rootIndex()).dir(*/);
    //    qDebug()<<"filename" + fileName;
    //    qDebug() <<"dirpath" +  dirmodel->fileInfo(index).dir().absolutePath();


    git_buf buf = GIT_BUF_INIT_CONST(NULL, 0);
    git_repository *repo = NULL;
    git_signature *sig;
    /*
    Discovery stage -  discover to repository to which the file belongs to...
    */

   // qDebug()<<"dir" <<dirmodel->fileInfo(ui->browser->currentIndex()).filePath().toLocal8Bit().data();
    if(0 != git_repository_discover(&buf,dirmodel->fileInfo(ui->browser->currentIndex()).filePath().toLocal8Bit().data(),
                                    0, dirmodel->fileInfo(ui->browser->rootIndex()).filePath().toLocal8Bit().data()))
    {
        qDebug() << "Error: discovery failed" ;
    }
    else
    {
        qDebug() <<"Discovery succesfull";
    }
    /*
    Gain access to the repository
    */

    if(0 == git_repository_open(&repo, buf.ptr))
    {

        qDebug() << "Succesful open" << buf.ptr;
        git_oid oid;
        git_commit* old_head = NULL;
        git_revparse_single( (git_object**) &old_head,
                             repo, "HEAD" );
        if (git_signature_default(&sig, repo) < 0)
        {
            qDebug() << "Unable to create a commit signature." << "Perhaps 'user.name' and 'user.email' are not set";
            git_signature_new((git_signature **)&sig,
                              "iulianpana", "iulianpana@gmail.com", 123456789, 60);
        }
        /*
        If access gained then prepare to commit local file
        Step 1: create blob.
        */
        //qDebug()<< fileName.toLocal8Bit().data();
        QString filePath = dirmodel->fileInfo(ui->browser->currentIndex()).absoluteFilePath();
        qDebug() <<filePath;
        int err = git_blob_create_fromdisk(&oid, repo, filePath.toLocal8Bit().data());
        if (err != 0)
        {
            qDebug() << "Error: git_blob_create_fromdisk failed" ;
        }
        else
        {
            qDebug() <<"Created blob";

            git_index* index = 0;
            int err = git_repository_index(&index, repo);
            if (err == 0)
            {
                //Step 2:  Add the selected file to the staging area
                QString workingDir(buf.ptr);
                workingDir.remove(".git/", Qt::CaseInsensitive);
                filePath.remove(workingDir);
                qDebug()<<filePath;
                err = git_index_add_bypath(index, filePath.toLocal8Bit().data());
                if (err == 0)
                {
                    // Write the updated staging area file back to disk
                    err = git_index_write(index);
                    if (err != 0)
                    {
                        qDebug() << "Error: git_index_write failed";
                    }
                    else
                    {   git_oid tree_id;
                        if (git_index_write_tree(&tree_id, index) < 0)
                            qDebug()<< "Unable to write initial tree from index" ;
                        else
                        {   git_tree *tree;
                            if (git_tree_lookup(&tree, repo, &tree_id) < 0)
                                qDebug()<<"Could not look up initial tree";
                            else
                            {
                                err = git_commit_create_v(
                                            &oid, /* out id */
                                            repo,
                                            "HEAD", /*  update the HEAD */
                                            sig,
                                            sig,
                                            NULL, /* use default message encoding */
                                            QInputDialog::getText(this, "Comment", "Enter a comment").toLocal8Bit().data(),
                                            tree,
                                            1, old_head ); /* <-- HERE */
                            }
                        }
                    }
                }
                else
                {
                    qDebug() << "Error: git_index_add_bypath failed";
                }
                git_index_free(index);

            }
            else
            {
                qDebug() << "Error: git_repository_index failed" ;
            }
        }
        git_repository_free(repo);
    }
    else
        qDebug()<<"Could not open repository";

}
