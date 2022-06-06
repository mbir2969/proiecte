/********************************************************************************
** Form generated from reading UI file 'Magazin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGAZIN_H
#define UI_MAGAZIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MagazinClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MagazinClass)
    {
        if (MagazinClass->objectName().isEmpty())
            MagazinClass->setObjectName(QString::fromUtf8("MagazinClass"));
        MagazinClass->resize(600, 400);
        menuBar = new QMenuBar(MagazinClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MagazinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MagazinClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MagazinClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MagazinClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MagazinClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MagazinClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MagazinClass->setStatusBar(statusBar);

        retranslateUi(MagazinClass);

        QMetaObject::connectSlotsByName(MagazinClass);
    } // setupUi

    void retranslateUi(QMainWindow *MagazinClass)
    {
        MagazinClass->setWindowTitle(QCoreApplication::translate("MagazinClass", "Magazin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MagazinClass: public Ui_MagazinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGAZIN_H
