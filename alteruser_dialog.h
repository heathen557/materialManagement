#ifndef ALTERUSER_DIALOG_H
#define ALTERUSER_DIALOG_H

#include <QDialog>
#include<QDebug>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class alteruser_Dialog;
}

class alteruser_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit alteruser_Dialog(QWidget *parent = 0);
    ~alteruser_Dialog();

    void initUserInfo(QString,QString,QString,QString);

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::alteruser_Dialog *ui;

signals:
    void alterUserOneNoteSignal(QString,QString,QString,QString);
};

#endif // ALTERUSER_DIALOG_H
