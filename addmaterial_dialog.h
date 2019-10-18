#ifndef ADDMATERIAL_DIALOG_H
#define ADDMATERIAL_DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDebug>

namespace Ui {
class addMaterial_Dialog;
}

class addMaterial_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addMaterial_Dialog(QWidget *parent = 0);
    ~addMaterial_Dialog();

    void initTableWidget();

private slots:
    void on_ok_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addMaterial_Dialog *ui;

    int currentItemIndex;      //item的当前序号

     //用途、 物料名称 、 型号、厂家、单价
    QTableWidgetItem  userTypeItem[50];
    QTableWidgetItem  materialNameItem[50];
    QTableWidgetItem  materialModelItem[50];
    QTableWidgetItem  factoryItem[50];
    QTableWidgetItem  singlePriceItem[50];
    QTableWidgetItem  noteItem[50];

    QString sqlStr;

};

#endif // ADDMATERIAL_DIALOG_H
