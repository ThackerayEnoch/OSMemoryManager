#include <QApplication>
#include "Headers/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("模拟实现操作系统内存分配与回收");
    // DPI适用 保证在高DPI下显示正常
    qreal devicePixelRatio = w.devicePixelRatio();
    w.resize(int(1250.00 / devicePixelRatio), int(950.00 / devicePixelRatio));
    w.show();
    return QApplication::exec();
}
