#include "torah.h"
#include "ui_torah.h"

Torah::Torah(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Torah)
{
    ui->setupUi(this);
}

Torah::~Torah()
{
    delete ui;
}

void Torah::on_lineEdit_textChanged(const QString &arg1)
{
    ui->gem1->display(Program::calculateGematria(arg1));
}

void Torah::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->gem2->display(Program::calculateGematria(arg1));
}

void Torah::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->gem3->display(Program::calculateGematria(arg1));
}

void Torah::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->gem4->display(Program::calculateGematria(arg1));
}

void Torah::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->gem5->display(Program::calculateGematria(arg1));
}

void Torah::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->gem6->display(Program::calculateGematria(arg1));
}
