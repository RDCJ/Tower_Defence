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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *chapter1;
    QPushButton *chapter2;
    QPushButton *chapter3;
    QPushButton *pause;
    QGroupBox *groupBox;
    QPushButton *contin;
    QPushButton *back;
    QPushButton *restart;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPushButton *re;
    QPushButton *next;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 640);
        MainWindow->setMouseTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chapter1 = new QPushButton(centralwidget);
        chapter1->setObjectName(QString::fromUtf8("chapter1"));
        chapter1->setGeometry(QRect(150, 200, 171, 111));
        QFont font;
        font.setPointSize(12);
        chapter1->setFont(font);
        chapter1->setCursor(QCursor(Qt::PointingHandCursor));
        chapter2 = new QPushButton(centralwidget);
        chapter2->setObjectName(QString::fromUtf8("chapter2"));
        chapter2->setGeometry(QRect(420, 200, 181, 111));
        chapter2->setFont(font);
        chapter2->setCursor(QCursor(Qt::PointingHandCursor));
        chapter3 = new QPushButton(centralwidget);
        chapter3->setObjectName(QString::fromUtf8("chapter3"));
        chapter3->setGeometry(QRect(700, 200, 181, 111));
        chapter3->setFont(font);
        chapter3->setCursor(QCursor(Qt::PointingHandCursor));
        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(10, 10, 41, 41));
        pause->setCursor(QCursor(Qt::PointingHandCursor));
        pause->setStyleSheet(QString::fromUtf8("border-image: url(:/image/pause.png);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(340, 130, 351, 231));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));
        contin = new QPushButton(groupBox);
        contin->setObjectName(QString::fromUtf8("contin"));
        contin->setGeometry(QRect(130, 50, 101, 29));
        contin->setCursor(QCursor(Qt::PointingHandCursor));
        back = new QPushButton(groupBox);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(130, 170, 101, 29));
        back->setCursor(QCursor(Qt::PointingHandCursor));
        restart = new QPushButton(groupBox);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(130, 110, 101, 29));
        restart->setCursor(QCursor(Qt::PointingHandCursor));
        restart->raise();
        contin->raise();
        back->raise();
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(110, 400, 361, 111));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(550, 400, 451, 141));
        re = new QPushButton(centralwidget);
        re->setObjectName(QString::fromUtf8("re"));
        re->setGeometry(QRect(720, 70, 181, 111));
        re->setFont(font);
        re->setCursor(QCursor(Qt::PointingHandCursor));
        next = new QPushButton(centralwidget);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(840, 290, 181, 111));
        next->setFont(font);
        next->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralwidget);
        chapter1->raise();
        chapter2->raise();
        chapter3->raise();
        pause->raise();
        groupBox->raise();
        textBrowser->raise();
        textBrowser_2->raise();
        next->raise();
        re->raise();
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
        QObject::connect(chapter1, SIGNAL(clicked()), textBrowser, SLOT(hide()));
        QObject::connect(chapter2, SIGNAL(clicked()), textBrowser, SLOT(hide()));
        QObject::connect(chapter3, SIGNAL(clicked()), textBrowser, SLOT(hide()));
        QObject::connect(chapter1, SIGNAL(clicked()), textBrowser_2, SLOT(hide()));
        QObject::connect(chapter2, SIGNAL(clicked()), textBrowser_2, SLOT(hide()));
        QObject::connect(chapter3, SIGNAL(clicked()), textBrowser_2, SLOT(hide()));
        QObject::connect(next, SIGNAL(clicked()), next, SLOT(hide()));
        QObject::connect(re, SIGNAL(clicked()), re, SLOT(hide()));

        pause->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        chapter1->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\345\205\263", nullptr));
        chapter2->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\345\205\263", nullptr));
        chapter3->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\211\345\205\263", nullptr));
        pause->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "             \350\217\234\345\215\225", nullptr));
        contin->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
        back->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        restart->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">	      </span><span style=\" font-family:'SimSun'; font-size:11pt;\">\346\270\270\346\210\217\350\257\264\346\230\216</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">1.\346\224\276\347\275\256\351\230\262\345\276\241\345\241\224\357\274\214\346\212\265\345\276\241\350\277\233\346\224\273\347\232\204\346\200\252\347\211\251</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">2.\345\210\251\347\224\250\345\207\273\346\235\200\346\200\252\347\211\251\350\216\267\345\276\227\347\232\204\351\207\221\351\222\261\345\215\207\347\272\247\351\230\262\345\276\241\345\241\224</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">3.\350\265\242\345\276\227\346\270\270\346\210\217, \350\216\267\345\276\227\347\247\257\345\210\206</span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt;\">            \346\200\252\347\211\251\345\233\276\351\211\264</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\350\231\261\350\231\253:\346\234\200\346\231\256\351\200\232\347\232\204\346\200\252\347\211\251\357\274\214\347\247\273\345\212\250\351\200\237\345\272\246\350\276\203\345\277\253</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\345\217\262\350\216\261\345\247\206:\350\242\253\345\207\273\346\235\200\345\220\216\344\274\232\345\210\206\350\243\202\346\210\220\344\270\244\344\270\252\345\260\217\345\217\262\350\216\261\345\247\206\357\274\214\347\247\273\345\212\250\351\200\237\345\272\246\350\276\203\346\205\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:10pt;\">\345\244\247\351\242\232\350\231\253:\345\270\246\346\234\211\344\270\211\345\261\202\346\212\244\347\224\262\357\274\214\345\217\257\344\273\245\346\212\265\346\214\241\344\270\211\346\254\241\346\224\273\345\207\273</span></p></body></html>", nullptr));
        re->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
