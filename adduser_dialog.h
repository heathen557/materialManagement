#ifndef ADDUSER_DIALOG_H
#define ADDUSER_DIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QTableWidgetItem>

namespace Ui {
class addUser_Dialog;
}

class addUser_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addUser_Dialog(QWidget *parent = 0);
    ~addUser_Dialog();



private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::addUser_Dialog *ui;

signals:
    void addUserOneNoteSignal(QString,QString,QString,QString);
};

#endif // ADDUSER_DIALOG_H
