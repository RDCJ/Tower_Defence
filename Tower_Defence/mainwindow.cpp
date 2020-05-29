#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->_chapter.initChapter();
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    timer->setInterval(500);
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
    this->repaint();
}

