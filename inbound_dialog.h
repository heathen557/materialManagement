#ifndef INBOUND_DIALOG_H
#define INBOUND_DIALOG_H

#include <QDialog>

namespace Ui {
class inBound_Dialog;
}

class inBound_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit inBound_Dialog(QWidget *parent = 0);
    ~inBound_Dialog();

private:
    Ui::inBound_Dialog *ui;
};

#endif // INBOUND_DIALOG_H
