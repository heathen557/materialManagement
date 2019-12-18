#ifndef ADD_PK_DIALOG_H
#define ADD_PK_DIALOG_H

#include <QDialog>

namespace Ui {
class add_PK_Dialog;
}

class add_PK_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_PK_Dialog(QWidget *parent = 0);
    ~add_PK_Dialog();

private:
    Ui::add_PK_Dialog *ui;
};

#endif // ADD_PK_DIALOG_H
