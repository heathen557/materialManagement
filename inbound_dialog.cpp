#include "inbound_dialog.h"
#include "ui_inbound_dialog.h"


extern QSqlQuery sql_query;
inBound_Dialog::inBound_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inBound_Dialog)
{
    ui->setupUi(this);
}

void inBound_Dialog::initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum,QString UserName)
{
    ui->material_label->setText(material_Name);
    ui->operator_lineEdit->setText(UserName);

    singlePrice = Price;
    ExistingNum = currentNum;

    //插入入库表时所需的字段
    userType = user_Type;
    materialName = material_Name;
    materialModel = material_Model;
    factoryStr = manu_Factory;
}


inBound_Dialog::~inBound_Dialog()
{
    delete ui;
}


//确定 添加库存
void inBound_Dialog::on_ok_pushButton_clicked()
{
    QString materialName = ui->material_label->text();
    int addNum = ui->inBoundNum_lineEdit->text().toInt();
    QString operationName = ui->operator_lineEdit->text();
    QString addNoteName = ui->note_lineEdit->text();      //入库表中的备注

    int numResult = addNum + ExistingNum;          //入库以后 库存的总量
    float allPrice = numResult * singlePrice ;     //总价值

    currentDateTime = QDateTime::currentDateTime();
    QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");



    bool buscess;
    //数据库INVENTORY_TABLE表的修改,根据商品的名称
    sql_query.prepare("UPDATE INVENTORY_TABLE SET NUMBER=:NUMBER, ALL_PRICE=:ALL_PRICE WHERE MATERIAL_NAME=:MATERIAL_NAME;");
    sql_query.bindValue(":NUMBER",numResult);
    sql_query.bindValue(":ALL_PRICE",allPrice);
    sql_query.bindValue(":MATERIAL_NAME",materialName);
    buscess = sql_query.exec();
    if (!buscess)
    {
        qDebug("on_ok_pushButton_clicked,add inBound,  update INVENTORY_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("入库失败"));
        return;
    }


    //入库表信息的导入
    float inBoundPrice = singlePrice * addNum;    //入库的总价值
    sql_query.prepare("INSERT INTO INBOUND_TABLE(USE_TYPE,MATERIAL_NAME,MATERIAL_MODEL,MANUFACTOR,NUMBER,SINGLE_PRICE,ALL_PRICE,OPERATION_USER,OPERATION_TIME,NOTE) VALUES(:USE_TYPE,:MATERIAL_NAME,:MATERIAL_MODEL,:MANUFACTOR,:NUMBER,:SINGLE_PRICE,:ALL_PRICE,:OPERATION_USER,:OPERATION_TIME,:NOTE)");
    sql_query.bindValue(":USE_TYPE",userType);
    sql_query.bindValue(":MATERIAL_NAME",materialName);
    sql_query.bindValue(":MATERIAL_MODEL",materialModel);
    sql_query.bindValue(":MANUFACTOR",factoryStr);
    sql_query.bindValue(":NUMBER",addNum);
    sql_query.bindValue(":SINGLE_PRICE",singlePrice);
    sql_query.bindValue(":ALL_PRICE",inBoundPrice);
    sql_query.bindValue(":OPERATION_USER",operationName);
    sql_query.bindValue(":OPERATION_TIME",current_time);
    sql_query.bindValue(":NOTE",addNoteName);
    buscess = sql_query.exec();

    qDebug()<<"name = "<<materialName<<endl;
    if (!buscess)
    {
        qDebug("on_ok_pushButton_clicked,add inBound,  update INBOUND_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("入库失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit inBoundNum_Signal(numResult,allPrice);
    this->hide();

    ui->material_label->clear();
    ui->inBoundNum_lineEdit->clear();
    ui->operator_lineEdit->clear();
    ui->note_lineEdit->clear();

}


//取消
void inBound_Dialog::on_cancel_pushButton_clicked()
{
    this->hide();

    ui->material_label->clear();
    ui->inBoundNum_lineEdit->clear();
    ui->operator_lineEdit->clear();
    ui->note_lineEdit->clear();
}
