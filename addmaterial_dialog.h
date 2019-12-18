#ifndef ADDMATERIAL_DIALOG_H
#define ADDMATERIAL_DIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDebug>
#include<QDateTime>

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

    QString userName;

    void setUserName(QString);

private slots:
    void on_ok_pushButton_clicked();

    void on_add_pushButton_clicked();

private:
    Ui::addMaterial_Dialog *ui;

    int currentItemIndex;      //item的当前序号

//    1、waferNum     			varchar(50)  晶圆批号
//    2、productModel 			varchar(50)  产品型号
//    3、CPtest_num       			varchar(50)  CP测试单号
//    4、chipNum		 			varchar(50)  芯片片号
//    5、CP_test_specification    varchar(50)  CP测试规范
//    6、CP_investment            varchar(50)  CP投入
//    7、process_demand           varchar(200) 特殊加工需求
//    8、CP_output                varchar(50)  CP产出
//    9、isChiped                varchar(50)  是否结片
//    10、isBatched               varchar(50)  是否结批
//    11、operator                varchar(50)  操作人员
//    12、updateTime              datetime     最后操作时间
//    13、note                    varchar(200) 备注
    QTableWidgetItem  waferNumItem[50];
    QTableWidgetItem  productModelItem[50];
    QTableWidgetItem  CPtest_numItem[50];
    QTableWidgetItem  chipNumItem[50];
    QTableWidgetItem  CP_test_specificationItem[50];
    QTableWidgetItem  CP_investmentItem[50];
    QTableWidgetItem  process_demandItem[50];
    QTableWidgetItem  CP_outputItem[50];
    QTableWidgetItem  isChipedItem[50];
    QTableWidgetItem  isBatchedItem[50];
    QTableWidgetItem  noteItem[50];


    QString sqlStr;

    QDateTime currentDateTime;

};

#endif // ADDMATERIAL_DIALOG_H
