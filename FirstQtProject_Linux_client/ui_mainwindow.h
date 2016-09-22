/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionConnect_To_Server;
    QAction *actionMain_Page;
    QAction *actionRefresh;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *sigla;
    QTreeWidget *treeWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuHome;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1016, 421);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionConnect_To_Server = new QAction(MainWindow);
        actionConnect_To_Server->setObjectName(QStringLiteral("actionConnect_To_Server"));
        actionMain_Page = new QAction(MainWindow);
        actionMain_Page->setObjectName(QStringLiteral("actionMain_Page"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sigla = new QLabel(centralWidget);
        sigla->setObjectName(QStringLiteral("sigla"));
        sigla->setAutoFillBackground(true);
        sigla->setPixmap(QPixmap(QString::fromUtf8("../../logo_sigle.png")));
        sigla->setScaledContents(true);

        gridLayout->addWidget(sigla, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1016, 25));
        menuHome = new QMenu(menuBar);
        menuHome->setObjectName(QStringLiteral("menuHome"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuHome->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuHome->addSeparator();
        menuHome->addAction(actionMain_Page);
        menuHome->addAction(actionConnect_To_Server);
        menuEdit->addAction(actionOpen_File);
        menuEdit->addAction(actionRefresh);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen_File->setToolTip(QApplication::translate("MainWindow", "Open File", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionConnect_To_Server->setText(QApplication::translate("MainWindow", "Connect To  Server", 0));
        actionConnect_To_Server->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionMain_Page->setText(QApplication::translate("MainWindow", "Main Page", 0));
        actionMain_Page->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        sigla->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menuHome->setTitle(QApplication::translate("MainWindow", "Home", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
