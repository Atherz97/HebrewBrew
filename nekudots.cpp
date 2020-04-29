#include "nekudots.h"
#include "ui_nekudots.h"

nekudots::nekudots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nekudots)
{
    ui->setupUi(this);
}

nekudots::~nekudots()
{
    delete ui;
}
