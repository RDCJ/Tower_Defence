#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    buttonMove = false;
    ui->setupUi(this);
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_chapter.show(pa, buttonMove, mouse_x, mouse_y);
    pa->end();
    delete pa;
}

void MainWindow::move()
{
    _chapter.place_monster();
    _chapter.monster_move();
    _chapter.tower_detect();
    _chapter.tower_shoot();
    _chapter.bullet_move();
    _chapter.check_monster();
    _chapter.check_status();
    this->repaint();
}


void MainWindow::on_Start_clicked()
{
    this->_chapter.initChapter(1, Player());
    timer->start(100);
    timer->setInterval(20);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    double mx = e->x();
    double my = e->y();

    if ((mx > 0 && mx < 80) && (my > 0 && my < 80))
    {
        buttonMove = true;
        mouse_x = mx;
        mouse_y = my;
    }
    else buttonMove = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    double mx = e->x();
    double my = e->y();
    if (buttonMove == true)
    {
        mouse_x = mx;
        mouse_y = my;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    double mx = e->x();
    double my = e->y();
    if (buttonMove == true)
    {
        this->_chapter.createTower(mx, my);
        buttonMove = false;
    }
}
