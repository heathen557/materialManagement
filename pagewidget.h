#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QDialog>

namespace Ui {
class PageWidget;
}

class PageWidget : public QDialog
{
    Q_OBJECT

public:
    explicit PageWidget(QWidget *parent = 0);
    ~PageWidget();

private:
    Ui::PageWidget *ui;
};

#endif // PAGEWIDGET_H
