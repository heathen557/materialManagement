#ifndef UIDEMO01_H
#define UIDEMO01_H

#include <QDialog>
#include<pagewidget.h>
#include<QWidget>

#include <QtSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>
#include<querysetdialog.h>
#include<QTableWidgetItem>
#include<addmaterial_dialog.h>
#include<inbound_dialog.h>
#include<outbound_dialog.h>
#include<altermaterial_dialog.h>
#include<inboundquery_dialog.h>
#include<outboundquery_dialog.h>

namespace Ui {
class UIDemo01;
}

class UIDemo01 : public QDialog
{
    Q_OBJECT

public:
    explicit UIDemo01(QWidget *parent = 0);
    ~UIDemo01();

    void initSql();

    void initConnect();

    void initTableWidget();

    PageWidget *pageWidget;

    querySetDialog managmentQuery_dia;    //查询界面

    addMaterial_Dialog addMaterial_dia;   //增加物料界面

    inBound_Dialog  inBound_dia;        //入库

    outBound_Dialog outBound_dia;       //出库

    alterMaterial_Dialog alterMaterial_dia;   //修改物料




    //用途、 物料名称 、 型号、厂家、单价
   QTableWidgetItem  userTypeItem[50];
   QTableWidgetItem  materialNameItem[50];
   QTableWidgetItem  materialModelItem[50];
   QTableWidgetItem  factoryItem[50];
   QTableWidgetItem  numberItem[50];
   QTableWidgetItem  singlePriceItem[50];
   QTableWidgetItem  allPriceItem[50];
   QTableWidgetItem  noteItem[50];

   QStringList allDataList;

   int onePageNotesNum;     //一页显示的条目数量  初始化为50
   QLabel *lable1 ;

   int currentClickIndex;   //当前选中的TableWidget的行号：

   //入库查询界面
   QTableWidgetItem  inBound_userTypeItem[50];
   QTableWidgetItem  inBound_materialNameItem[50];
   QTableWidgetItem  inBound_materialModelItem[50];
   QTableWidgetItem  inBound_factoryItem[50];
   QTableWidgetItem  inBound_numberItem[50];
   QTableWidgetItem  inBound_singlePriceItem[50];
   QTableWidgetItem  inBound_allPriceItem[50];
   QTableWidgetItem  inBound_operatiorItem[50];
   QTableWidgetItem  inBound_operaTimeItem[50];
   QTableWidgetItem  inBound_noteItem[50];

   inBoundQuery_Dialog inBoundQuery_dia;
   PageWidget *inBound_PageWidget;
   QLabel *inBound_label;
   QStringList inBound_DataList;


   //出库查询界面相关
   QTableWidgetItem  outBound_userTypeItem[50];
   QTableWidgetItem  outBound_materialNameItem[50];
   QTableWidgetItem  outBound_materialModelItem[50];
   QTableWidgetItem  outBound_factoryItem[50];
   QTableWidgetItem  outBound_numberItem[50];
   QTableWidgetItem  outBound_singlePriceItem[50];
   QTableWidgetItem  outBound_allPriceItem[50];
   QTableWidgetItem  outBound_operatiorItem[50];
   QTableWidgetItem  outBound_RecipientItem[50];
   QTableWidgetItem  outBound_operaTimeItem[50];
   QTableWidgetItem  outBound_noteItem[50];

   outboundquery_Dialog outBoundQuery_dia;
   PageWidget *outBound_PageWidget;
   QLabel *outBound_label;
   QStringList outBound_DataList;



protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::UIDemo01 *ui;

private slots:
    void initForm();
    void buttonClick();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_addMaterial_pushButton_clicked();
    void on_managerQuery_pushButton_clicked();

    void selectResult_slot(QStringList);    //物资管理 接收查询条件界面的查询信息的槽函数

    void showSpecifiedPage(int pageNum);   //物资管理 显示指定页数的槽函数

    void on_returnALL_pushButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_alterMaterial_pushButton_clicked();

    void on_inBound_pushButton_clicked();

    void on_outBound_pushButton_clicked();

    void alterMaterial_slot(QString,QString,QString,QString,QString,float,float);


    /**********入库相关槽函数*****************/
    void inBoundNum_Slot(int ,float);        //此槽函数 出库入库共用

    void on_inBoundQuery_pushButton_clicked();

    void inBoundSQLResult_slot(QStringList);   //接收入库查询 查询SQL 语句的槽函数

    void showinBound_SpecifiedPage(int pageNum);


    /**********出库相关槽函数*****************/
    void on_outBoundQuery_pushButton_clicked();

    void outBoundSQLResult_slot(QStringList);

    void showoutBound_SpecifiedPage(int pageNum);

signals:
    void setMaxPage_signal(int);

    void setInBoundPage_signal(int);

    void setOutBoundPage_signal(int);
};

#endif // UIDEMO01_H
