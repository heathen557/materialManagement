#ifndef ALTERMATERIAL_DIALOG_H
#define ALTERMATERIAL_DIALOG_H

#include <QDialog>

namespace Ui {
class alterMaterial_Dialog;
}

class alterMaterial_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit alterMaterial_Dialog(QWidget *parent = 0);
    ~alterMaterial_Dialog();

private:
    Ui::alterMaterial_Dialog *ui;
};

#endif // ALTERMATERIAL_DIALOG_H
