#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>

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

    protected slots:
        void move();

private slots:
        void on_Start_clicked();

        void on_MainWindow_customContextMenuRequested(const QPoint &pos);

private:
        Ui::MainWindow *ui;
        Chapter _chapter;
        QTimer *timer;
        bool creatTower, lvlupTower;
        double mouse_x, mouse_y, drag_x, drag_y;
};
#endif // MAINWINDOW_H
