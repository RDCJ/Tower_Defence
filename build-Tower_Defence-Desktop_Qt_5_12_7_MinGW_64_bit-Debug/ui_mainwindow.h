/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menuChapter1;
    QAction *menuChapter2;
    QAction *menuChapter3;
    QWidget *centralwidget;
    QPushButton *chapter1;
    QPushButton *chapter2;
    QPushButton *chapter3;
    QPushButton *pause;
    QGroupBox *groupBox;
    QPushButton *contin;
    QPushButton *back;
    QPushButton *restart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 640);
        MainWindow->setMouseTracking(true);
        menuChapter1 = new QAction(MainWindow);
        menuChapter1->setObjectName(QString::fromUtf8("menuChapter1"));
        menuChapter2 = new QAction(MainWindow);
        menuChapter2->setObjectName(QString::fromUtf8("menuChapter2"));
        menuChapter3 = new QAction(MainWindow);
        menuChapter3->setObjectName(QString::fromUtf8("menuChapter3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chapter1 = new QPushButton(centralwidget);
        chapter1->setObjectName(QString::fromUtf8("chapter1"));
        chapter1->setGeometry(QRect(150, 200, 171, 111));
        chapter2 = new QPushButton(centralwidget);
        chapter2->setObjectName(QString::fromUtf8("chapter2"));
        chapter2->setGeometry(QRect(420, 200, 181, 111));
        chapter3 = new QPushButton(centralwidget);
        chapter3->setObjectName(QString::fromUtf8("chapter3"));
        chapter3->setGeometry(QRect(700, 200, 181, 111));
        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(20, 20, 61, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(340, 160, 351, 231));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));
        contin = new QPushButton(groupBox);
        contin->setObjectName(QString::fromUtf8("contin"));
        contin->setGeometry(QRect(130, 50, 101, 29));
        back = new QPushButton(groupBox);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(130, 170, 101, 29));
        restart = new QPushButton(groupBox);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(130, 110, 101, 29));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(chapter1, SIGNAL(clicked()), chapter1, SLOT(hide()));
        QObject::connect(chapter2, SIGNAL(clicked()), chapter2, SLOT(hide()));
        QObject::connect(chapter3, SIGNAL(clicked()), chapter3, SLOT(hide()));
        QObject::connect(chapter1, SIGNAL(clicked()), chapter2, SLOT(hide()));
        QObject::connect(chapter2, SIGNAL(clicked()), chapter1, SLOT(hide()));
        QObject::connect(chapter2, SIGNAL(clicked()), chapter3, SLOT(hide()));
        QObject::connect(chapter3, SIGNAL(clicked()), chapter2, SLOT(hide()));
        QObject::connect(chapter3, SIGNAL(clicked()), chapter1, SLOT(hide()));
        QObject::connect(chapter1, SIGNAL(clicked()), chapter3, SLOT(hide()));
        QObject::connect(chapter1, SIGNAL(clicked()), pause, SLOT(show()));
        QObject::connect(chapter2, SIGNAL(clicked()), pause, SLOT(show()));
        QObject::connect(chapter3, SIGNAL(clicked()), pause, SLOT(show()));
        QObject::connect(pause, SIGNAL(clicked()), groupBox, SLOT(show()));
        QObject::connect(pause, SIGNAL(clicked()), pause, SLOT(hide()));
        QObject::connect(contin, SIGNAL(clicked()), groupBox, SLOT(hide()));
        QObject::connect(restart, SIGNAL(clicked()), groupBox, SLOT(hide()));
        QObject::connect(back, SIGNAL(clicked()), groupBox, SLOT(hide()));
        QObject::connect(contin, SIGNAL(clicked()), pause, SLOT(show()));
        QObject::connect(restart, SIGNAL(clicked()), pause, SLOT(show()));
        QObject::connect(back, SIGNAL(clicked()), chapter1, SLOT(show()));
        QObject::connect(back, SIGNAL(clicked()), chapter3, SLOT(show()));
        QObject::connect(back, SIGNAL(clicked()), chapter2, SLOT(show()));

        pause->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        menuChapter1->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\345\205\263", nullptr));
        menuChapter2->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\345\205\263", nullptr));
        menuChapter3->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\211\345\205\263", nullptr));
        chapter1->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\345\205\263", nullptr));
        chapter2->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\345\205\263", nullptr));
        chapter3->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\211\345\205\263", nullptr));
        pause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
        contin->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
        back->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        restart->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
