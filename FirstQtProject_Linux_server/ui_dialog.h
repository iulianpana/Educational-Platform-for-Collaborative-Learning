/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QTextEdit *compiler;
    QPushButton *pushButton_2;
    QPushButton *execute;
    QTextEdit *textEdit;
    QPushButton *NewFolder;
    QPushButton *NewFile;
    QTextEdit *command;
    QTextEdit *parameters;
    QPushButton *Delete;
    QPushButton *pushButton_3;
    QPushButton *Save;
    QPushButton *Quit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(570, 437);
        Dialog->setMouseTracking(true);
        Dialog->setAutoFillBackground(true);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(Dialog);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(treeView, 0, 0, 1, 4);

        compiler = new QTextEdit(Dialog);
        compiler->setObjectName(QStringLiteral("compiler"));

        gridLayout->addWidget(compiler, 4, 0, 1, 8);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 5, 1, 3);

        execute = new QPushButton(Dialog);
        execute->setObjectName(QStringLiteral("execute"));

        gridLayout->addWidget(execute, 3, 4, 1, 1);

        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777, 16777));

        gridLayout->addWidget(textEdit, 0, 4, 1, 4);

        NewFolder = new QPushButton(Dialog);
        NewFolder->setObjectName(QStringLiteral("NewFolder"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NewFolder->sizePolicy().hasHeightForWidth());
        NewFolder->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(NewFolder, 1, 0, 1, 1);

        NewFile = new QPushButton(Dialog);
        NewFile->setObjectName(QStringLiteral("NewFile"));
        sizePolicy1.setHeightForWidth(NewFile->sizePolicy().hasHeightForWidth());
        NewFile->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(NewFile, 1, 1, 1, 1);

        command = new QTextEdit(Dialog);
        command->setObjectName(QStringLiteral("command"));
        sizePolicy.setHeightForWidth(command->sizePolicy().hasHeightForWidth());
        command->setSizePolicy(sizePolicy);
        command->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(command, 3, 0, 1, 2);

        parameters = new QTextEdit(Dialog);
        parameters->setObjectName(QStringLiteral("parameters"));
        sizePolicy.setHeightForWidth(parameters->sizePolicy().hasHeightForWidth());
        parameters->setSizePolicy(sizePolicy);

        gridLayout->addWidget(parameters, 3, 2, 1, 2);

        Delete = new QPushButton(Dialog);
        Delete->setObjectName(QStringLiteral("Delete"));
        sizePolicy1.setHeightForWidth(Delete->sizePolicy().hasHeightForWidth());
        Delete->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Delete, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_3, 1, 3, 1, 1);

        Save = new QPushButton(Dialog);
        Save->setObjectName(QStringLiteral("Save"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Save->sizePolicy().hasHeightForWidth());
        Save->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(Save, 1, 4, 1, 2);

        Quit = new QPushButton(Dialog);
        Quit->setObjectName(QStringLiteral("Quit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Quit->sizePolicy().hasHeightForWidth());
        Quit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(Quit, 1, 6, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "PushButton", 0));
        execute->setText(QApplication::translate("Dialog", "Execute", 0));
        NewFolder->setText(QApplication::translate("Dialog", "New Folder", 0));
        NewFile->setText(QApplication::translate("Dialog", "New File", 0));
#ifndef QT_NO_TOOLTIP
        command->setToolTip(QApplication::translate("Dialog", "<html><head/><body><p>Command</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        parameters->setToolTip(QApplication::translate("Dialog", "<html><head/><body><p>Parameters</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        parameters->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        Delete->setText(QApplication::translate("Dialog", "Delete", 0));
        pushButton_3->setText(QApplication::translate("Dialog", "Some other Function", 0));
        Save->setText(QApplication::translate("Dialog", "Save", 0));
        Quit->setText(QApplication::translate("Dialog", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
