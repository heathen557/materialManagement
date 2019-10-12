#ifndef QUERYSETDIALOG_H
#define QUERYSETDIALOG_H

#include <QDialog>

namespace Ui {
class querySetDialog;
}

class querySetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit querySetDialog(QWidget *parent = 0);
    ~querySetDialog();

private:
    Ui::querySetDialog *ui;
};

#endif // QUERYSETDIALOG_H
