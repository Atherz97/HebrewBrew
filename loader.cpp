#include "loader.h"
#include "ui_loader.h"

#include <QTimer>

Loader::Loader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loader)
{
    ui->setupUi(this);
    QTimer::singleShot(3500,this,SLOT(startApp()));
}

Loader::~Loader()
{
    delete ui;
}

void Loader::startApp() {
    w->show();

    this->setVisible(false);

}
