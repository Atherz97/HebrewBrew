#ifndef TORAH_H
#define TORAH_H

#include <QDialog>
#include "program.h"

namespace Ui {
class Torah;
}

class Torah : public QDialog
{
    Q_OBJECT

public:
    explicit Torah(QWidget *parent = nullptr);
    ~Torah();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

private:
    Ui::Torah *ui;
    Program* p;
};

#endif // TORAH_H
