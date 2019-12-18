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
#include<add_pk_dialog.h>
#include<query_pk_dialog.h>
#include<pk_alterdialog.h>

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

    PageWidget *PC_pageWidget;
    querySetDialog managmentQuery_dia;    //查询界面
    addMaterial_Dialog addMaterial_dia;   //增加物料界面
    inBound_Dialog  inBound_dia;        //入库
    outBound_Dialog outBound_dia;       //出库
    alterMaterial_Dialog alterMaterial_dia;   //修改物料
    //用途、 物料名称 、 型号、厂家、单价


   QTableWidgetItem  CP_waferNumItem[50];
   QTableWidgetItem  CP_productModelItem[50];
   QTableWidgetItem  CP_test_numItem[50];
   QTableWidgetItem  CP_chipNumItem[50];
   QTableWidgetItem  CP_test_specificationItem[50];
   QTableWidgetItem  CP_investmentItem[50];
   QTableWidgetItem  CP_process_demandItem[50];
   QTableWidgetItem  CP_outputItem[50];
   QTableWidgetItem  CP_yieldItem[50];
   QTableWidgetItem  CP_isChipedItem[50];
   QTableWidgetItem  CP_chip_yieldItem[50];
   QTableWidgetItem  CP_isBatchedItem[50];
   QTableWidgetItem  CP_batch_yieldItem[50];
   QTableWidgetItem  CP_operatorItem[50];
   QTableWidgetItem  CP_updateTimeItem[50];
   QTableWidgetItem  CP_noteItem[50];
   QStringList allDataList;
   int onePageNotesNum;     //一页显示的条目数量  初始化为50
   QLabel *lable1 ;
   int currentClickIndex;   //当前选中的TableWidget的行号：




   //PK查询界面相关的
   PageWidget *PK_pageWidget;
   QLabel *PK_label;
   add_PK_Dialog addPk_dia;
   query_pk_Dialog pK_query_dia;
   PK_alterDialog PK_alter_dia;
   QStringList PK_allDataList;
   int pk_currentClickedIndex;

   QTableWidgetItem  PK_waferNumItem[50];
   QTableWidgetItem  PK_cpTestItem[50];
   QTableWidgetItem  PK_numItem[50];
   QTableWidgetItem  PK_packageTypeItem[50];
   QTableWidgetItem  PK_package_specificationItem[50];
   QTableWidgetItem  PK_investmentItem[50];
   QTableWidgetItem  PK_process_demandItem[50];
   QTableWidgetItem  PK_outputItem[50];
   QTableWidgetItem  PK_yieldItem[50];
   QTableWidgetItem  PK_operatorItem[50];
   QTableWidgetItem  PK_updateTimeItem[50];
   QTableWidgetItem  PK_noteItem[50];



   //FT查询界面相关的
   PageWidget *FT_pageWidget;
   QLabel *FT_label;

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
    void on_CP_addMaterial_pushButton_clicked();
    void on_CP_managerQuery_pushButton_clicked();

    void selectResult_slot(QStringList);    //物资管理 接收查询条件界面的查询信息的槽函数

    void showSpecifiedPage(int pageNum);   //物资管理 显示指定页数的槽函数

    void on_CP_returnALL_pushButton_clicked();

    void on_CP_tableWidget_clicked(const QModelIndex &index);

    void on_CP_alterMaterial_pushButton_clicked();

    void on_inBound_pushButton_clicked();

    void on_outBound_pushButton_clicked();

    void alterMaterial_slot(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);

    void delMaterial_slot();

    void on_CP_managerOutExcel_pushBotton_clicked();   //文件导出


    /*********PK************************/
    void on_PK_addMaterial_pushButton_clicked();

    void on_PK_managerQuery_pushButton_2_clicked();

    void on_PK_alterMaterial_pushButton_clicked();

    void on_PK_returnALL_pushButton_clicked();

    void on_PK_managerOutExcel_pushBotton_clicked();

    void PK_selectResult_slot(QStringList);

    void PK_showSpecifiedPage(int pageNum);

    void on_PK_tableWidget_clicked(const QModelIndex &index);

    void PK_alterSlot(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);




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

    void on_inBoundOutExecel_pushButton_clicked();

    void on_outBoundOutExcel_pushButton_clicked();




signals:
    void setMaxPage_signal(int);

    void PK_setMaxPage_signal(int);

    void setInBoundPage_signal(int);

    void setOutBoundPage_signal(int);
};

#endif // UIDEMO01_H
