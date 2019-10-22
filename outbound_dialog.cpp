#include "outbound_dialog.h"
#include "ui_outbound_dialog.h"


extern QSqlQuery sql_query;
outBound_Dialog::outBound_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outBound_Dialog)
{
    ui->setupUi(this);
}

outBound_Dialog::~outBound_Dialog()
{
    delete ui;
}


void outBound_Dialog::initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum)
{
    ui->material_label_2->setText(material_Name);

    singlePrice = Price;
    ExistingNum = currentNum;

    //插入出库表时所需的字段
    userType = user_Type;
    materialName = material_Name;
    materialModel = material_Model;
    factoryStr = manu_Factory;
}

void outBound_Dialog::on_ok_pushButton_2_clicked()
{
    QString materialName = ui->material_label_2->text();
    int outNum = ui->outBoundNum_lineEdit->text().toInt();
    QString operationName = ui->operator_lineEdit_2->text();
    QString addNoteName = ui->note_lineEdit_2->text();
    QString recipientName = ui->Recipient_lineEdit->text();

    if(ExistingNum < outNum)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("出库失败！选择的出库数量超过库存"));
        return;
    }

    int numResult = ExistingNum - outNum;          //出库以后 库存的总量
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
        qDebug("on_ok_pushButton_clicked, outBound,  update INVENTORY_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("出库失败"));
        return;
    }


    //入库表信息的导入
    float outBoundPrice = singlePrice * outNum;    //出库的总价值
    sql_query.prepare("INSERT INTO OUTBOUND_TABLE(USE_TYPE,MATERIAL_NAME,MATERIAL_MODEL,MANUFACTOR,NUMBER,SINGLE_PRICE,ALL_PRICE,OPERATION_USER, RECIPIENT,OPERATION_TIME,NOTE) VALUES(:USE_TYPE,:MATERIAL_NAME,:MATERIAL_MODEL,:MANUFACTOR,:NUMBER,:SINGLE_PRICE,:ALL_PRICE,:OPERATION_USER,:RECIPIENT,:OPERATION_TIME,:NOTE)");
    sql_query.bindValue(":USE_TYPE",userType);
    sql_query.bindValue(":MATERIAL_NAME",materialName);
    sql_query.bindValue(":MATERIAL_MODEL",materialModel);
    sql_query.bindValue(":MANUFACTOR",factoryStr);
    sql_query.bindValue(":NUMBER",outNum);
    sql_query.bindValue(":SINGLE_PRICE",singlePrice);
    sql_query.bindValue(":ALL_PRICE",outBoundPrice);
    sql_query.bindValue(":OPERATION_USER",operationName);
    sql_query.bindValue(":RECIPIENT",recipientName);
    sql_query.bindValue(":OPERATION_TIME",current_time);
    sql_query.bindValue(":NOTE",addNoteName);
    buscess = sql_query.exec();

    qDebug()<<"name = "<<materialName<<endl;
    if (!buscess)
    {
        qDebug("on_ok_pushButton_clicked,add inBound,  update INBOUND_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("出库失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit outBoundNum_Signal(numResult,allPrice);        //和入库可以共用一个槽函数
    this->hide();

    ui->material_label_2->clear();
    ui->outBoundNum_lineEdit->clear();
    ui->Recipient_lineEdit->clear();
    ui->operator_lineEdit_2->clear();
    ui->note_lineEdit_2->clear();
}

void outBound_Dialog::on_cancel_pushButton_2_clicked()
{
    this->hide();

    ui->material_label_2->clear();
    ui->outBoundNum_lineEdit->clear();
    ui->Recipient_lineEdit->clear();
    ui->operator_lineEdit_2->clear();
    ui->note_lineEdit_2->clear();
}
