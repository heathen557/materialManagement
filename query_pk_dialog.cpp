#include "query_pk_dialog.h"
#include "ui_query_pk_dialog.h"

query_pk_Dialog::query_pk_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::query_pk_Dialog)
{
    ui->setupUi(this);
}

query_pk_Dialog::~query_pk_Dialog()
{
    delete ui;
}
