#ifndef QUERY_PK_DIALOG_H
#define QUERY_PK_DIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class query_pk_Dialog;
}

class query_pk_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit query_pk_Dialog(QWidget *parent = 0);
    ~query_pk_Dialog();

    void initSelect();

    void initTableWidget();

    QString sqlStr;

    bool buscess ;

    bool isSelectFinished;

    int currentItemIndex;

    QTableWidgetItem  PK_waferNumItem[50];
    QTableWidgetItem  PK_cpTestItem[50];
    QTableWidgetItem  PK_numItem[50];
    QTableWidgetItem  PK_userNameItem[50];
    QTableWidgetItem  PK_updateTimeItem[50];
    QTableWidgetItem  PK_noteItem[50];

private slots:
    void on_ok_pushButton_clicked();

    void on_select_pushButton_clicked();

    void on_waferNum_comboBox_currentIndexChanged(const QString &arg1);

    void on_cpTestNum_comboBox_currentIndexChanged(const QString &arg1);

signals:
    void PK_selectResult_signal(QStringList);


private:
    Ui::query_pk_Dialog *ui;
};

#endif // QUERY_PK_DIALOG_H
