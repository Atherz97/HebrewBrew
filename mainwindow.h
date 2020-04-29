#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "program.h"
#include "dictionaryview.h"
#include "spectral.h"
#include "nekudots.h"
#include "torah.h"

#define VERSION "0.2.0"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Program *p;

private slots:
    void on_rootForm_textChanged();
    void on_actionSave_Dictionary_triggered();
    void on_actionLoad_Dictionary_triggered();
    void on_Modifier_AND_clicked();
    void on_Modifier_OR_clicked();
    void on_Modifier_NOT_clicked();
    void on_Modifier_PREPOSITION_clicked();
    void on_Modifier_MY_clicked();
    void on_Modifier_OUR_clicked();
    void on_Modifier_ITS_clicked();
    void on_Modifier_THEIR_clicked();
    void on_Modifier_Clear_clicked();
    void on_OkButton_clicked();
    void on_actionEmpty_Dictionary_triggered();
    void on_Modifier_THE_clicked();
    void on_Modifier_FORTO_clicked();
    void on_Modifier_NOUN_clicked();
    void on_Modifier_PERSON_clicked();
    void on_Modifier_FORTO_2_clicked();
    void on_productClearButton_clicked();
    void on_productAddButton_clicked();
    void on_actionView_Dictionary_triggered();
    void on_productWord_textChanged();
    void on_copyText_textChanged();
    void on_spellButton_clicked();
    void on_actionSpectral_Speller_triggered();

    void on_actionNekudot_Guide_triggered();

    void on_actionTorah_Study_triggered();

private:
    Ui::MainWindow *ui;
    int modcode;
    void push();
};

#endif // MAINWINDOW_H
