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

    void selectResult_slot(QStringList);    //接收查询条件界面的查询信息的槽函数

    void showSpecifiedPage(int pageNum);   //显示指定页数的槽函数

    void on_returnALL_pushButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_alterMaterial_pushButton_clicked();

    void on_inBound_pushButton_clicked();

    void on_outBound_pushButton_clicked();

signals:
    void setMaxPage_signal(int);
};

#endif // UIDEMO01_H
