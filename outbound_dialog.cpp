#include "outbound_dialog.h"
#include "ui_outbound_dialog.h"

outBound_Dialog::outBound_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outBound_Dialog)
{
    ui->setupUi(this);
}

outBound_Dialog::~outBound_Dialog()
{
    delete ui;
}
