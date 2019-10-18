#include "inbound_dialog.h"
#include "ui_inbound_dialog.h"

inBound_Dialog::inBound_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inBound_Dialog)
{
    ui->setupUi(this);
}

inBound_Dialog::~inBound_Dialog()
{
    delete ui;
}
