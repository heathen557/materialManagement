#ifndef OUTBOUND_DIALOG_H
#define OUTBOUND_DIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QDateTime>

namespace Ui {
class outBound_Dialog;
}

class outBound_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit outBound_Dialog(QWidget *parent = 0);
    ~outBound_Dialog();

    void initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);

private slots:
    void on_ok_pushButton_2_clicked();

    void on_cancel_pushButton_2_clicked();

private:
    Ui::outBound_Dialog *ui;

    QString userType;
    QString materialName;
    QString materialModel;
    QString factoryStr;
    float singlePrice;
    int ExistingNum;
    QDateTime currentDateTime;

signals:
    void outBoundNum_Signal(int,float);
};

#endif // OUTBOUND_DIALOG_H
