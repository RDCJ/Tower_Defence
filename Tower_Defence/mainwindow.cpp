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
    //std::cout<<mx<<' '<<my<<endl;
    if (lvlupTower == false)
    {
        if ((mx > 0 && mx < 80) && (my > 0 && my < 80))
        {
            creatTower = true;
            drag_x = mx;
            drag_y = my;
        }
        else if ((mx > 80 && mx < 160) && (my > 0 && my < 80))
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
