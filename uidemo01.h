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
#include<addmaterial_dialog.h>

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

    PageWidget *pageWidget;

    querySetDialog managmentQuery_dia;

    addMaterial_Dialog addMaterial_dia;

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

    void selectResult_slot(QStringList);
};

#endif // UIDEMO01_H
