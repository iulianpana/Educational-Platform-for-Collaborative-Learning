/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"

Server::Server(QWidget *parent)
    :   QDialog(parent), tcpServer(0), networkSession(0)
{
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    } else {
        sessionOpened();
    }


    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    //! [3]
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));


    //! [3]

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Server"));
}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    //! [0] //! [1]
    tcpServer = new QTcpServer(this);
    tcpServer->setMaxPendingConnections(5000);
    if (!tcpServer->listen(QHostAddress::Any, (quint16)5000)) {
        QMessageBox::critical(this, tr("Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
    //! [0]
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Client now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
    //! [1]
}

//! [4]
void Server::sendAssignements(QString username)
{
    //! [5]
    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_0);
    //! [4] //! [6]
    QDir dir("Database") ;
    
    foreach(const QFileInfo item, dir.entryInfoList())
    {
        if(item.isDir() == true)
            continue;

        QFile *databaseFile = new QFile(item.absoluteFilePath());

        if(!databaseFile->open(QIODevice::ReadWrite))
            qDebug()<< "Error opening file" << databaseFile->fileName();
        else
            qDebug()<< "Succesful opening file" << databaseFile->fileName();
        
        QString line;
        QString assignement_id,assignement_link,team;


        if(studentEnroledToCourse(username,databaseFile) == true)
        {
            qDebug()<<username << " " << databaseFile->fileName();
            //search for assignement
            while(!(line=databaseFile->readLine()).isEmpty()){

                if(line.contains("assignement_id"))
                {//read assignement id and link

                    assignement_id=line.split("=").at(1);

                    line=databaseFile->readLine();
                    assignement_link=line.split("=").at(1);

                    while(!(line=databaseFile->readLine()).isEmpty()){
                        //qDebug() << line;
                        if(line.contains("team"))
                            team=line.split(QRegExp("[= ]")).at(1);
                        if(line.contains(username))
                            //found assignement for username

                        {   qDebug()<<"aici"<<databaseFile->fileName()<<assignement_id<<assignement_link<<team;
                            out<<QString(databaseFile->fileName().split(QDir::separator()).at(databaseFile->fileName().split(QDir::separator()).size()-1));
                           // out<<QString("ceva");
                            out<<QString(assignement_id)<<QString(assignement_link)<<QString(team);

                            if (clientConnection->write(block) < 0)
                                qDebug()<<"error at writing";
                            clientConnection->waitForBytesWritten(10000);

                            block.clear();
                        }
                        else
                            team.clear();
                    }

//                    out<<QFileInfo(*databaseFile).fileName();
//                    clientConnection->write(block);
                    block.clear();

                    assignement_id.clear();
                    assignement_link.clear();

                }
            }
        }
//        else
//            continue;
    }
    //! [7] //! [8]
    clientConnection->waitForBytesWritten(10000);
    clientConnection->disconnectFromHost();
    //! [5]
}
bool Server::studentEnroledToCourse(QString name, QFile* course)
{
    QString line;
    while(!(line = course->readLine()).isEmpty())
    {
        if(line.contains("student_id"))
            if(line.contains(name))
            {
                return true;
            }
    }
    return false;
}

void Server::readUsername()
{

    QDataStream in(clientConnection);
    int length;
    QString username;

    if(clientConnection->bytesAvailable() < sizeof(qint32))
        return;
    in>>length;
    //qDebug()<<"l "<<length;

    if(clientConnection->bytesAvailable() < length)
        return;
    in>>username;
    //qDebug()<<" u " << username;
    while(!clientConnection->isWritable())
        qDebug()<<"wait for write";
    crtUsername = new QString(username);
    qDebug()<<"starting search for assig";
    sendAssignements(username);
    qDebug()<<"ended search for assig";
    //clientConnection->disconnectFromHost();
}

void Server::newConnection()
{
    clientConnection = tcpServer->nextPendingConnection();

    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    connect(clientConnection,SIGNAL(readyRead()),
            this, SLOT(readUsername()));
}
//! [8]
