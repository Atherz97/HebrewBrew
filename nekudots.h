#ifndef NEKUDOTS_H
#define NEKUDOTS_H

#include <QDialog>

namespace Ui {
class nekudots;
}

class nekudots : public QDialog
{
    Q_OBJECT

public:
    explicit nekudots(QWidget *parent = nullptr);
    ~nekudots();

private:
    Ui::nekudots *ui;
};

#endif // NEKUDOTS_H
