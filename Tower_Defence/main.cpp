#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Tower Defence");
    w.show();
    return a.exec();
}

/*
计划：
0. 判定成功与失败 (finished)
1. 显示血条（基地、怪物）(finished)
2. 通过文件读取关卡信息 (finished)
       地图路径
       出怪的数量与时间
       文件格式：
                    n（路径长度）
                    以下n行 xi yi 表示路径
                    num（怪物数量）
                    以下num行 ti 表示每个怪物出现的时间
                    最后一行为起始金钱
3. 防御塔升级系统(finished)
4. 多关卡切换(finished)
5. 更加美观的UI
6. 修正地图的大小规格(finished)
7. 更丰富的防御塔
8. 更丰富的怪物(finished)
9. 显示防御塔的攻击范围(finished)
*/
