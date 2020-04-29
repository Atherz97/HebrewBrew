#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setWindowTitle(QString("HebrewBrew Translator ").append(VERSION));
    p = new Program();
    p->loadDictionary(FILENAME);
}

MainWindow::~MainWindow()
{
    QCoreApplication::quit();
    delete ui;
}

void MainWindow::on_rootForm_textChanged(){}

void MainWindow::on_actionSave_Dictionary_triggered()
{
    p->saveDictionary(FILENAME);
}

void MainWindow::on_actionLoad_Dictionary_triggered()
{
    p->loadDictionary(FILENAME);
}

///
/// \brief MainWindow::push
///
/// When a user updates the root word,
/// Pass through database of root words.
///
void MainWindow::push()
{
    ui->productWord->setText(p->present(ui->rootForm->toPlainText(),modcode));
}

void MainWindow::on_Modifier_AND_clicked()
{
    modcode = AND;
    this->push();
}

void MainWindow::on_Modifier_OR_clicked()
{
    modcode = PLURFEM;
    this->push();
}

void MainWindow::on_Modifier_NOT_clicked()
{
    modcode = YOUR;
    this->push();
}

void MainWindow::on_Modifier_PREPOSITION_clicked()
{
    modcode = PREP;
    this->push();
}

void MainWindow::on_Modifier_MY_clicked()
{
    modcode = PLURMASC;
    this->push();
}

void MainWindow::on_Modifier_OUR_clicked()
{
    modcode = OUR;
    this->push();
}

void MainWindow::on_Modifier_ITS_clicked()
{
    modcode = ITS;
    this->push();
}

void MainWindow::on_Modifier_THEIR_clicked()
{
    modcode = THEIR;
    this->push();
}

void MainWindow::on_Modifier_Clear_clicked()
{
    ui->copyText->setText(" ");
}

void MainWindow::on_OkButton_clicked()
{
    this->push();
}

void MainWindow::on_actionEmpty_Dictionary_triggered()
{
    p->clearDict();
}

void MainWindow::on_Modifier_THE_clicked()
{
    modcode = THE;
    this->push();
}

void MainWindow::on_Modifier_FORTO_clicked()
{
    modcode = FORTO;
    this->push();
}

void MainWindow::on_Modifier_NOUN_clicked()
{
    modcode = TONOUN;
    this->push();
}

void MainWindow::on_Modifier_PERSON_clicked()
{
    modcode = TOPERSON;
    this->push();
}

void MainWindow::on_Modifier_FORTO_2_clicked()
{
    modcode = FROM;
    this->push();
}

void MainWindow::on_productClearButton_clicked()
{
    ui->copyText->setText(" ");
}

void MainWindow::on_productAddButton_clicked()
{
    ui->copyText->setText(ui->copyText->toPlainText() + " " + ui->productWord->toPlainText());
}

void MainWindow::on_actionView_Dictionary_triggered()
{
    dictionaryView *dict = new dictionaryView(this,p);
    dict->show();
}

void MainWindow::on_productWord_textChanged()
{
    // update the gematria value
    ui->GemProduct->display(p->calculateGematria(ui->productWord->toPlainText()));
}

void MainWindow::on_copyText_textChanged()
{
    // update the gematria value
    ui->GemSentence->display(p->calculateGematria(ui->copyText->toPlainText()));
}

void MainWindow::on_spellButton_clicked()
{
    ui->productWord->setText(p->spell());
}

void MainWindow::on_actionSpectral_Speller_triggered()
{
    Spectral *spec = new Spectral(this);
    spec->show();
}

void MainWindow::on_actionNekudot_Guide_triggered()
{
    nekudots *nek = new nekudots(this);
    nek->show();
}

void MainWindow::on_actionTorah_Study_triggered()
{
    Torah *torah = new Torah(this);
    torah->show();
}
