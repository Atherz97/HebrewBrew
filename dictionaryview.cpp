#include "dictionaryview.h"
#include "ui_dictionaryview.h"

dictionaryView::dictionaryView(QWidget *parent) : QDialog(parent), ui(new Ui::dictionaryView)
{
    ui->setupUi(this);
}

dictionaryView::dictionaryView(QWidget *parent, Program *p) : QDialog(parent), ui(new Ui::dictionaryView)
{
    ui->setupUi(this);
    this->p = p;

    loadTable();

}

dictionaryView::~dictionaryView()
{
    delete ui;
}

void dictionaryView::on_pushButton_clicked()
{
    bool ok = false;
    int id = QInputDialog::getInt(this, "Remove from Dictionary",
        "Enter the ID of the word to remove.", 1, 0, 2000000, 1, &ok);
    if (ok) {
        int r = p->removeFromDictionary(p->getValue(id-1));
        if (r == 1) {
            QErrorMessage().showMessage("That word isn't in the dictionary.");
        }
        else {
            loadTable();
        }
    }
}

void dictionaryView::loadTable()
{
    int i = 0;
    ui->tableWidget->setRowCount(0);

    for (QString k : p->getKeys()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(k));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(p->getValue(k)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(QString::number(p->calculateGematria(p->getValue(k)))));
        i++;
    }
}

void dictionaryView::on_tableWidget_cellActivated(int row, int column)
{
    /*
    column = 0;

    // ask to remove the word at the table?
    QMessageBox *q = new QMessageBox();
    q->setText("Would you like to remove this word?");
    q->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    q->setDefaultButton(QMessageBox::Ok);

    if (q->exec() == QMessageBox::Ok) {
        int r = p->removeFromDictionary(p->getValue(row-1));
        if (r == 1) {
            QErrorMessage().showMessage("Error.");
        }
        else {
            loadTable();
        }
    }
    */
    return;
}
