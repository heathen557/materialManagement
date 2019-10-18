#ifndef OUTBOUND_DIALOG_H
#define OUTBOUND_DIALOG_H

#include <QDialog>

namespace Ui {
class outBound_Dialog;
}

class outBound_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit outBound_Dialog(QWidget *parent = 0);
    ~outBound_Dialog();

private:
    Ui::outBound_Dialog *ui;
};

#endif // OUTBOUND_DIALOG_H
