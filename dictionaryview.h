#ifndef DICTIONARYVIEW_H
#define DICTIONARYVIEW_H

#include "program.h"

#include <QDialog>

namespace Ui {
class dictionaryView;
}

class dictionaryView : public QDialog
{
    Q_OBJECT

public:
    explicit dictionaryView(QWidget *parent = nullptr);
    dictionaryView(QWidget *parent = nullptr, Program *p = nullptr);
    ~dictionaryView();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::dictionaryView *ui;
    Program *p;
    void loadTable();
};

#endif // DICTIONARYVIEW_H
