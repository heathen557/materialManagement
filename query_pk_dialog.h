#ifndef QUERY_PK_DIALOG_H
#define QUERY_PK_DIALOG_H

#include <QDialog>

namespace Ui {
class query_pk_Dialog;
}

class query_pk_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit query_pk_Dialog(QWidget *parent = 0);
    ~query_pk_Dialog();

private:
    Ui::query_pk_Dialog *ui;
};

#endif // QUERY_PK_DIALOG_H
