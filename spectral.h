#ifndef SPECTRAL_H
#define SPECTRAL_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class Spectral;
}

class Spectral : public QDialog
{
    Q_OBJECT

public:
    explicit Spectral(QWidget *parent = nullptr);
    ~Spectral();

private slots:
    void on_wordInput_textChanged();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_singleWord_textChanged(const QString &arg1);

private:
    Ui::Spectral *ui;
    QTableWidgetItem *filled;
    QTableWidgetItem *blank;
    void redraw();
    int skipper = 0;
};

#endif // SPECTRAL_H
