#ifndef INBOUND_DIALOG_H
#define INBOUND_DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QDateTime>

namespace Ui {
class inBound_Dialog;
}

class inBound_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit inBound_Dialog(QWidget *parent = 0);
    ~inBound_Dialog();

    void initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::inBound_Dialog *ui;

    QString userType;
    QString materialName;
    QString materialModel;
    QString factoryStr;
    float singlePrice;
    int ExistingNum;
    QDateTime currentDateTime;
signals:
    void inBoundNum_Signal(int,float);
};

#endif // INBOUND_DIALOG_H
