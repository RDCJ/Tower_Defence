#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    this->_chapter.show(pa);
    pa->end();
    delete pa;
}

void MainWindow::move()
{
    this->_chapter.monster_move();
    this->_chapter.tower_detect();
    this->_chapter.tower_shoot();
    this->_chapter.bullet_move();
    this->_chapter.check_monster();
    this->repaint();
}


void MainWindow::on_Start_clicked()
{
    this->_chapter.initChapter(1);
    timer->start(100);
    timer->setInterval(30);
}
