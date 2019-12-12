#ifndef UIDEMO01_H
#define UIDEMO01_H

#include <QDialog>
#include<pagewidget.h>
#include<QWidget>
#include<QLineEdit>

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
#include<adduser_dialog.h>
#include<alteruser_dialog.h>
#include<QAxObject>
#include<QDesktopServices>
#include<QFileDialog>

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

    void init_tableWidget();

    void clear_tableWidgetItem();

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


   //用户管理界面相关
  QTableWidgetItem userNameItem[50];
  QLineEdit userPassWord_lineEdit[50];
  QTableWidgetItem authorityItem[50];
  QTableWidgetItem userNoteItem[50];

//  QLineEdit lineText[50];

  addUser_Dialog addUserDia;
  int currentIndex;
  int currentUserClickIndex;
  alteruser_Dialog alterUserDia;



  QString UserName;  //当前登录的用户名
  QString UserAuthority; //用户的权限

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

    void on_CP_tableWidget_clicked(const QModelIndex &index);

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

    void on_addUser_pushButton_clicked();

    void on_alterUser_pushButton_clicked();

    void on_delUser_pushButton_clicked();

    /************用户管理相关的槽函数****************************/
    void addUserOneNoteSlot(QString,QString,QString,QString); //接收添加后某一条的槽函数

    void initUserTableWidget();

    void on_user_tableWidget_clicked(const QModelIndex &index);

    void alterUserOneNoteSlot(QString,QString,QString,QString);  //接收修改后某一条的槽函数



    void loginUserName_slot(QString,QString);

    void on_managerOutExcel_pushBotton_clicked();

    void on_inBoundOutExecel_pushButton_clicked();

    void on_outBoundOutExcel_pushButton_clicked();

signals:
    void setMaxPage_signal(int);

    void setInBoundPage_signal(int);

    void setOutBoundPage_signal(int);
};

#endif // UIDEMO01_H
