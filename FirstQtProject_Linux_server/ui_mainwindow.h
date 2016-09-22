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
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionStart_Sever;
    QAction *actionAdd_Course;
    QAction *actionEnrol_Student;
    QAction *actionAdd_Assignement;
    QAction *actionCreate_branches_for_assignement;
    QAction *actionRefresh;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QTreeView *treeView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuCeva;
    QMenu *menuEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1016, 421);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionStart_Sever = new QAction(MainWindow);
        actionStart_Sever->setObjectName(QStringLiteral("actionStart_Sever"));
        actionAdd_Course = new QAction(MainWindow);
        actionAdd_Course->setObjectName(QStringLiteral("actionAdd_Course"));
        actionEnrol_Student = new QAction(MainWindow);
        actionEnrol_Student->setObjectName(QStringLiteral("actionEnrol_Student"));
        actionAdd_Assignement = new QAction(MainWindow);
        actionAdd_Assignement->setObjectName(QStringLiteral("actionAdd_Assignement"));
        actionCreate_branches_for_assignement = new QAction(MainWindow);
        actionCreate_branches_for_assignement->setObjectName(QStringLiteral("actionCreate_branches_for_assignement"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAutoFillBackground(true);
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../logo_sigle.png")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout->addWidget(treeView, 1, 0, 1, 1);

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
        menuCeva = new QMenu(menuBar);
        menuCeva->setObjectName(QStringLiteral("menuCeva"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuCeva->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuCeva->addSeparator();
        menuCeva->addAction(actionStart_Sever);
        menuCeva->addAction(actionAdd_Course);
        menuCeva->addAction(actionEnrol_Student);
        menuCeva->addAction(actionAdd_Assignement);
        menuCeva->addAction(actionCreate_branches_for_assignement);
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
        actionStart_Sever->setText(QApplication::translate("MainWindow", "Start Sever", 0));
        actionStart_Sever->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionAdd_Course->setText(QApplication::translate("MainWindow", "Add Course", 0));
        actionAdd_Course->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionEnrol_Student->setText(QApplication::translate("MainWindow", "Enrol Student", 0));
        actionEnrol_Student->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionAdd_Assignement->setText(QApplication::translate("MainWindow", "Add Assignement", 0));
        actionAdd_Assignement->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionCreate_branches_for_assignement->setText(QApplication::translate("MainWindow", "Create branches for assignement", 0));
        actionCreate_branches_for_assignement->setShortcut(QApplication::translate("MainWindow", "Alt+B", 0));
        actionRefresh->setText(QApplication::translate("MainWindow", "Refresh ", 0));
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        label_3->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menuCeva->setTitle(QApplication::translate("MainWindow", "Home", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
