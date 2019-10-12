#include "pagewidget.h"
#include "ui_pagewidget.h"

PageWidget::PageWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PageWidget)
{
    ui->setupUi(this);
}

PageWidget::~PageWidget()
{
    delete ui;
}
