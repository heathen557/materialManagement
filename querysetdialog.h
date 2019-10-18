﻿#ifndef QUERYSETDIALOG_H
#define QUERYSETDIALOG_H

#include <QDialog>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDebug>

namespace Ui {
class querySetDialog;
}

class querySetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit querySetDialog(QWidget *parent = 0);
    ~querySetDialog();

    void initSelect();
    void initTableWidget();
private slots:
    void on_pushButton_clicked();

    void on_select_pushButton_clicked();


private:
    Ui::querySetDialog *ui;


    int currentItemIndex;      //item的当前序号

     //用途、 物料名称 、 型号、厂家、单价
    QTableWidgetItem  userTypeItem[50];
    QTableWidgetItem  materialNameItem[50];
    QTableWidgetItem  materialModelItem[50];
    QTableWidgetItem  factoryItem[50];
    QTableWidgetItem  numItem[50];
    QTableWidgetItem  noteItem[50];

    QString sqlStr;

signals:
   void selectResult_signal(QStringList);
};

#endif // QUERYSETDIALOG_H
