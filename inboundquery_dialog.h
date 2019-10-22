#ifndef INBOUNDQUERY_DIALOG_H
#define INBOUNDQUERY_DIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QTableWidgetItem>

namespace Ui {
class inBoundQuery_Dialog;
}

class inBoundQuery_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit inBoundQuery_Dialog(QWidget *parent = 0);
    ~inBoundQuery_Dialog();

    void initSelect();     //初始化上方的查询信息

    void initTableWidget();

private slots:
    void on_ok_pushButton_clicked();

    void on_select_pushButton_clicked();

private:
    Ui::inBoundQuery_Dialog *ui;

    //用途、 物料名称 、 型号、厂家、单价
   QTableWidgetItem  userTypeItem[50];
   QTableWidgetItem  materialNameItem[50];
   QTableWidgetItem  materialModelItem[50];
   QTableWidgetItem  factoryItem[50];
   QTableWidgetItem  numItem[50];
   QTableWidgetItem  operationItem[50];
   QTableWidgetItem  operationTime[50];
   QTableWidgetItem  noteItem[50];

   int currentItemIndex;

signals:
   void inBoundSQLResult_signal(QStringList);
};

#endif // INBOUNDQUERY_DIALOG_H
