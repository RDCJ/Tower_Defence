#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setMouseTracking(true);
    setMouseTracking(true);
    creatTower = false;
    lvlupTower = false;
    ifPause = false;
    ui->pause->setHidden(true);
    ui->groupBox->setHidden(true);
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
    this->_chapter.show(pa, creatTower, drag_x, drag_y);
    pa->end();
    delete pa;
}

void MainWindow::move()
{
    if (ifPause == false)
    {
        _chapter.place_monster();
        _chapter.monster_move();
        _chapter.tower_detect();
        _chapter.tower_shoot();
        _chapter.bullet_move();
        _chapter.check_monster();
        _chapter.check_status();
    }
    this->repaint();
}


void MainWindow::mousePressEvent(QMouseEvent *e)
{
    double mx = e->x();
    double my = e->y();
    //std::cout<<mx<<' '<<my<<endl;
    if (lvlupTower == false)
    {
        if ((mx > 400 && mx < 480) && (my > 560 && my < 640))
        {
            creatTower = true;
            drag_x = mx;
            drag_y = my;
        }
        else if ((mx > 560 && mx < 640) && (my > 560 && my < 640))
        {
            lvlupTower = true;
            QCursor m_harmmer(QPixmap(":/image/mouse_Harmmer.png"));
            QApplication::setOverrideCursor(m_harmmer);
        }
    }
    else
    {
        QApplication::restoreOverrideCursor();
        _chapter.lvlupTower(mx, my);
        lvlupTower = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mouse_x = e->x();
    mouse_y = e->y();
    _chapter.setMxy(mouse_x, mouse_y);
    if (creatTower == true)
    {
        drag_x = mouse_x;
        drag_y = mouse_y;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    double mx = e->x();
    double my = e->y();
    if (creatTower == true)
    {
        this->_chapter.createTower(mx, my);
        creatTower = false;
    }
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::chapter_start(int k)
{
    nowChapter = k;
    this->_chapter.initChapter(k);
    timer->start(100);
    timer->setInterval(20);
}

void MainWindow::on_chapter1_clicked()
{
    chapter_start(1);
}


void MainWindow::on_chapter2_clicked()
{
    chapter_start(2);
}

void MainWindow::on_chapter3_clicked()
{
    chapter_start(3);
}


void MainWindow::on_pause_clicked()
{
    this->ifPause = true;
}

void MainWindow::on_contin_clicked()
{
    this->ifPause = false;
}

void MainWindow::on_restart_clicked()
{
    this->ifPause = false;
    chapter_start(nowChapter);
}

void MainWindow::on_back_clicked()
{
    this->ifPause = false;
    timer->stop();
}
