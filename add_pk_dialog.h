#ifndef ADD_PK_DIALOG_H
#define ADD_PK_DIALOG_H

#include <QDialog>
#include<QDebug>
#include<QTableWidgetItem>
#include <QSqlQuery>
#include<QDateTime>

namespace Ui {
class add_PK_Dialog;
}

class add_PK_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit add_PK_Dialog(QWidget *parent = 0);
    ~add_PK_Dialog();

    QString userName;

    void initSelect();

    void initTableWidgt();

    void setUserName(QString);

    QString sqlStr;

    QDateTime currentDateTime;

    QTableWidgetItem  PK_waferNumItem[50];
    QTableWidgetItem  PK_cpTestItem[50];
    QTableWidgetItem  PK_numItem[50];
    QTableWidgetItem  PK_packageTypeItem[50];
    QTableWidgetItem  PK_package_specificationItem[50];
    QTableWidgetItem  PK_investmentItem[50];
    QTableWidgetItem  PK_process_demandItem[50];
    QTableWidgetItem  PK_outputItem[50];
    QTableWidgetItem  PK_noteItem[50];

    int currentItemIndex;      //item的当前序号

private slots:

    void on_waferNum_comboBox_currentIndexChanged(const QString &arg1);

    void on_ok_pushButton_clicked();

    void on_addPK_pushButton_clicked();

private:
    Ui::add_PK_Dialog *ui;
};

#endif // ADD_PK_DIALOG_H
