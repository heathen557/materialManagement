#include "altermaterial_dialog.h"
#include "ui_altermaterial_dialog.h"


extern QSqlQuery sql_query;
alterMaterial_Dialog::alterMaterial_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterMaterial_Dialog)
{
    ui->setupUi(this);
}

alterMaterial_Dialog::~alterMaterial_Dialog()
{
    delete ui;
}

void alterMaterial_Dialog::initMaterialInfo(QString materialName,QString userType,QString materialModel,QString factory,QString singlePrice,int num)
{
    ui->materialName_label->setText(materialName);
    ui->userType_lineEdit->setText(userType);
    ui->materialModel_lineEdit->setText(materialModel);
    ui->factory_lineEdit->setText(factory);
    ui->singlePrice_lineEdit->setText(singlePrice);

    materialNum = num;       //增加此变量是为了 计算改变单价后 总价字段的值

}

//确认修改的槽函数
void alterMaterial_Dialog::on_alter_pushButton_clicked()
{
    bool buscess;

    QString materialName = ui->materialName_label->text();
    QString userType = ui->userType_lineEdit->text();
    QString materialModel = ui->materialModel_lineEdit->text();
    QString factoryName = ui->factory_lineEdit->text();
    QString noteStr = ui->note_lineEdit->text();
    float singlePrice = ui->singlePrice_lineEdit->text().toFloat();
    float allPrice = singlePrice * materialNum;



    //数据库部分的修改,根据商品的名称
    sql_query.prepare("UPDATE INVENTORY_TABLE SET USE_TYPE = :USETYPE,MATERIAL_MODEL=:MATERIAL_MODEL,MANUFACTOR=:MANUFACTOR,SINGLE_PRICE=:SINGLE_PRICE,ALL_PRICE=:ALL_PRICE,NOTE=:NOTE WHERE MATERIAL_NAME=:MATERIAL_NAME;");
    sql_query.bindValue(":USETYPE",userType);
    sql_query.bindValue(":MATERIAL_NAME",materialName);
    sql_query.bindValue(":MATERIAL_MODEL",materialModel);
    sql_query.bindValue(":MANUFACTOR",factoryName);
    sql_query.bindValue(":SINGLE_PRICE",singlePrice);
    sql_query.bindValue(":ALL_PRICE",allPrice);
    sql_query.bindValue(":NOTE",noteStr);
    buscess = sql_query.exec();
    if (!buscess)
    {
        qDebug("on_alter_pushButton_clicked  update INVENTORY_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("修改失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit alterMaterial_signal(userType,materialName,materialModel,factoryName,noteStr,singlePrice,allPrice);

    this->hide();

    ui->materialName_label->clear();
    ui->userType_lineEdit->clear();
    ui->materialModel_lineEdit->clear();
    ui->factory_lineEdit->clear();
    ui->note_lineEdit->clear();
    ui->singlePrice_lineEdit->clear();


}


//删除槽函数
void alterMaterial_Dialog::on_delete_pushButton_clicked()
{
    if(0 != materialNum)
    {
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("存在库存,请出库后再执行删除"));
        return;
    }

    bool buscess;
    QString materialName = ui->materialName_label->text();

    //数据库部分的修改，根据商品名称删除信息
    sql_query.prepare("DELETE  FROM INVENTORY_TABLE WHERE MATERIAL_NAME=:MATERIAL_NAME;");
    sql_query.bindValue(":MATERIAL_NAME",materialName);
    buscess = sql_query.exec();

    if (!buscess)
    {
        qDebug("on_delete_pushButton_clicked  update INVENTORY_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("修改失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit alterMaterial_signal("-","-","-","-","-",0,0);

    this->hide();

    ui->materialName_label->clear();
    ui->userType_lineEdit->clear();
    ui->materialModel_lineEdit->clear();
    ui->factory_lineEdit->clear();
    ui->note_lineEdit->clear();
    ui->singlePrice_lineEdit->clear();





}
