#ifndef LOADER_H
#define LOADER_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class Loader;
}

class Loader : public QDialog
{
    Q_OBJECT

public:
    explicit Loader(QWidget *parent = nullptr);
    ~Loader();
    MainWindow *w;

public slots:
    void startApp();

private:
    Ui::Loader *ui;

};

#endif // LOADER_H
