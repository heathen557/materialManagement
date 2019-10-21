#ifndef ALTERMATERIAL_DIALOG_H
#define ALTERMATERIAL_DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class alterMaterial_Dialog;
}

class alterMaterial_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit alterMaterial_Dialog(QWidget *parent = 0);
    ~alterMaterial_Dialog();

    void initMaterialInfo(QString,QString,QString,QString,QString,int);

private slots:
    void on_alter_pushButton_clicked();

    void on_delete_pushButton_clicked();

private:
    Ui::alterMaterial_Dialog *ui;

    QString sqlStr;

    int materialNum;

signals:
    void alterMaterial_signal(QString,QString,QString,QString,QString,float,float);

};

#endif // ALTERMATERIAL_DIALOG_H
