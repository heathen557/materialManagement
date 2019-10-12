#include "querysetdialog.h"
#include "ui_querysetdialog.h"

querySetDialog::querySetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::querySetDialog)
{
    ui->setupUi(this);
}

querySetDialog::~querySetDialog()
{
    delete ui;
}
