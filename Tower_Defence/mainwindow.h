#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QTimer>

#include "Chapter.h"
#include "Object.h"
#include "Monster.h"
#include "Tower.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void paintEvent(QPaintEvent *);

    protected slots:
        void move();

private slots:
        void on_Start_clicked();

private:
        Ui::MainWindow *ui;
        Chapter _chapter;
        QTimer *timer;
};
#endif // MAINWINDOW_H
