#include "add_pk_dialog.h"
#include "ui_add_pk_dialog.h"

add_PK_Dialog::add_PK_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_PK_Dialog)
{
    ui->setupUi(this);
}

add_PK_Dialog::~add_PK_Dialog()
{
    delete ui;
}
