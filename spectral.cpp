#include "spectral.h"
#include "ui_spectral.h"
#include "program.h"

Spectral::Spectral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spectral)
{
    ui->setupUi(this);
    filled = new QTableWidgetItem("o");
    blank = new QTableWidgetItem("");
}

Spectral::~Spectral()
{
    delete ui;
}

void Spectral::on_wordInput_textChanged()
{

}

void Spectral::on_pushButton_clicked()
{
    redraw();
}

void Spectral::redraw() {
    if (this->skipper == 1)
        return;

    QString t = ui->wordInput->toPlainText();
    QString _t = t;
    // clean up unnecessary characters (Nekkudot, letters, numbers, punc.)
    for (int i = 0; i < _t.length(); i++) {
        QChar k = _t[i];
        if (Program::cval(k) == -2) {
            t = _t.remove(i,1);
            i--;
        }
    }

    // initial clear
    ui->tableWidget->setColumnCount(t.length());

    for (int r = 0; r < ui->tableWidget->rowCount(); r++) {
        for (int c = 0; c < ui->tableWidget->columnCount(); c++) {
            ui->tableWidget->setItem(r,c,new QTableWidgetItem(""));
            ui->tableWidget->setHorizontalHeaderItem(21-c,new QTableWidgetItem("  "));
        }
    }

    // redot according to characters
    for (int i = 0; i < t.length(); i++) {
        int c = Program::cval(t[i]);
        int k = ui->tableWidget->columnCount()-1-i;
        if (c == -1) {
            ui->tableWidget->setItem(21-c,k,new QTableWidgetItem(""));
            ui->tableWidget->setHorizontalHeaderItem(k,new QTableWidgetItem("  "));
        }
        else {
            ui->tableWidget->setItem(21-c,k,new QTableWidgetItem("■"));
            ui->tableWidget->setHorizontalHeaderItem(k,new QTableWidgetItem(QString(t[i])));
        }
    }

    // show the user a clean version to potentially analyze one by one
    this->skipper = 1;
    //ui->wordInput->setPlainText(t);
    this->skipper = 0;
}

void Spectral::on_pushButton_2_clicked()
{
    ui->wordInput->setPlainText(Program::spell());

}

void Spectral::on_singleWord_textChanged(const QString &heb)
{
    ui->singleWordGem->setText("(" + QString::number(Program::calculateGematria(heb)) + ")");
    ui->singleWordPron->setPlainText(Program::pronounce(heb));
}
