#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <iostream>
#include "Chapter.h"
#include "Object.h"
#include "Monster.h"
#include "Tower.h"
#include "Player.h"

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
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);
        void chapter_start(int k);

    protected slots:
        void move();

    private slots:

            void on_MainWindow_customContextMenuRequested(const QPoint &pos);
            void on_chapter1_clicked();
            void on_chapter2_clicked();
            void on_chapter3_clicked();

            void on_menuChapter1_triggered();

            void on_menuChapter2_triggered();

            void on_menuChapter3_triggered();

            void on_pause_clicked();

            void on_contin_clicked();

            void on_restart_clicked();

            void on_back_clicked();

private:
        Ui::MainWindow *ui;
        Chapter _chapter;
        QTimer *timer;
        bool creatTower, lvlupTower, ifPause;
        double mouse_x, mouse_y, drag_x, drag_y;
        int nowChapter;
};
#endif // MAINWINDOW_H
