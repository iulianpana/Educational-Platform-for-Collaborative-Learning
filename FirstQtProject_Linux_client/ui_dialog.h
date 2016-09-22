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
    QTextEdit *parameters;
    QTextEdit *command;
    QPushButton *execute;
    QTextEdit *compiler;
    QTreeView *browser;
    QTextEdit *editWindow;

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
        parameters = new QTextEdit(Dialog);
        parameters->setObjectName(QStringLiteral("parameters"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(parameters->sizePolicy().hasHeightForWidth());
        parameters->setSizePolicy(sizePolicy);

        gridLayout->addWidget(parameters, 2, 2, 1, 2);

        command = new QTextEdit(Dialog);
        command->setObjectName(QStringLiteral("command"));
        sizePolicy.setHeightForWidth(command->sizePolicy().hasHeightForWidth());
        command->setSizePolicy(sizePolicy);
        command->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(command, 2, 0, 1, 2);

        execute = new QPushButton(Dialog);
        execute->setObjectName(QStringLiteral("execute"));

        gridLayout->addWidget(execute, 2, 4, 1, 1);

        compiler = new QTextEdit(Dialog);
        compiler->setObjectName(QStringLiteral("compiler"));

        gridLayout->addWidget(compiler, 3, 0, 1, 6);

        browser = new QTreeView(Dialog);
        browser->setObjectName(QStringLiteral("browser"));
        sizePolicy.setHeightForWidth(browser->sizePolicy().hasHeightForWidth());
        browser->setSizePolicy(sizePolicy);

        gridLayout->addWidget(browser, 0, 0, 1, 2);

        editWindow = new QTextEdit(Dialog);
        editWindow->setObjectName(QStringLiteral("editWindow"));
        editWindow->setMaximumSize(QSize(16777, 16777));

        gridLayout->addWidget(editWindow, 0, 2, 1, 4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        parameters->setToolTip(QApplication::translate("Dialog", "<html><head/><body><p>Parameters</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        parameters->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        command->setToolTip(QApplication::translate("Dialog", "<html><head/><body><p>Command</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        execute->setText(QApplication::translate("Dialog", "Execute", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
