#include "altermaterial_dialog.h"
#include "ui_altermaterial_dialog.h"

alterMaterial_Dialog::alterMaterial_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterMaterial_Dialog)
{
    ui->setupUi(this);
}

alterMaterial_Dialog::~alterMaterial_Dialog()
{
    delete ui;
}
