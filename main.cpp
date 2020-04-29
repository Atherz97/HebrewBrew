#include "mainwindow.h"
#include "loader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Loader l;
    MainWindow w;
    l.w = &w;
    l.show();

    return a.exec();
}
