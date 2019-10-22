#ifndef OUTBOUNDQUERY_DIALOG_H
#define OUTBOUNDQUERY_DIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QTableWidgetItem>

namespace Ui {
class outboundquery_Dialog;
}

class outboundquery_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit outboundquery_Dialog(QWidget *parent = 0);
    ~outboundquery_Dialog();

    void initSelect();     //初始化上方的查询信息

    void initTableWidget();

private slots:
    void on_ok_pushButton_clicked();

    void on_select_pushButton_clicked();

private:
    Ui::outboundquery_Dialog *ui;

    //用途、 物料名称 、 型号、厂家、单价
   QTableWidgetItem  userTypeItem[50];
   QTableWidgetItem  materialNameItem[50];
   QTableWidgetItem  materialModelItem[50];
   QTableWidgetItem  factoryItem[50];
   QTableWidgetItem  numItem[50];
   QTableWidgetItem  operationItem[50];
   QTableWidgetItem  RecipientItem[50];
   QTableWidgetItem  operationTime[50];
   QTableWidgetItem  noteItem[50];

   int currentItemIndex;

signals:
   void outBoundSQLResult_signal(QStringList);
};

#endif // OUTBOUNDQUERY_DIALOG_H
