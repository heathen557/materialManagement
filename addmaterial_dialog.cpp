#include "addmaterial_dialog.h"
#include "ui_addmaterial_dialog.h"

extern QSqlQuery sql_query;
addMaterial_Dialog::addMaterial_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMaterial_Dialog)
{
    ui->setupUi(this);

    currentItemIndex = 0;

    initTableWidget();
}


void addMaterial_Dialog::initTableWidget()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0)}");


    for(int i=0;i<50;i++)
    {
        ui->tableWidget->setItem(i,0,&userTypeItem[i]);
        ui->tableWidget->setItem(i,1,&materialNameItem[i]);
        ui->tableWidget->setItem(i,2,&materialModelItem[i]);
        ui->tableWidget->setItem(i,3,&factoryItem[i]);
        ui->tableWidget->setItem(i,4,&singlePriceItem[i]);
        ui->tableWidget->setItem(i,5,&noteItem[i]);

        userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        factoryItem[i].setTextAlignment(Qt::AlignCenter);
        singlePriceItem[i].setTextAlignment(Qt::AlignCenter);
        noteItem[i].setTextAlignment(Qt::AlignCenter);
    }
}

addMaterial_Dialog::~addMaterial_Dialog()
{
    delete ui;
}

//确定，在tableWidget控件中增加一行
void addMaterial_Dialog::on_ok_pushButton_clicked()
{
    //获取控件上的信息
    QString userType = ui->userType_lineEdit->text();
    QString materialName = ui->materialName_lineEdit->text();
    QString materialModel = ui->materialModel_lineEdit->text();
    QString factoryName = ui->factory_lineEdit->text();
    QString priceStr = ui->price_lineEdit->text();
    QString noteStr = ui->note_lineEdit->text();

    userTypeItem[currentItemIndex].setText(userType);
    materialNameItem[currentItemIndex].setText(materialName);
    materialModelItem[currentItemIndex].setText(materialModel);
    factoryItem[currentItemIndex].setText(factoryName);
    singlePriceItem[currentItemIndex].setText(priceStr);
    noteItem[currentItemIndex].setText(noteStr);


    currentItemIndex++;   //当前序号增加1

    ui->userType_lineEdit->clear();
    ui->materialName_lineEdit->clear();
    ui->materialModel_lineEdit->clear();
    ui->factory_lineEdit->clear();
    ui->price_lineEdit->clear();
    ui->note_lineEdit->clear();

}


//确定后 添加到数据库
void addMaterial_Dialog::on_pushButton_2_clicked()
{
    bool buscess;
    for(int i=0; i<currentItemIndex; i++)
    {

        QString userType =userTypeItem[i].text();
        QString materialName = materialNameItem[i].text();
        QString materialModel = materialModelItem[i].text();
        QString factoryName = factoryItem[i].text();
        float priceStr = singlePriceItem[i].text().toFloat();
        QString noteStr =  noteItem[i].text();

        qDebug()<<userType<<"  "<<materialName<<"  "<<materialModel<<" "<<factoryName<<"  "<<priceStr<<endl;

        sql_query.prepare("INSERT INTO INVENTORY_TABLE(USE_TYPE,MATERIAL_NAME,MATERIAL_MODEL,MANUFACTOR,NUMBER,SINGLE_PRICE,ALL_PRICE,NOTE) VALUES(:USE_TYPE,:MATERIAL_NAME,:MATERIAL_MODEL,:MANUFACTOR,:NUMBER,:SINGLE_PRICE,:ALL_PRICE,:NOTE);");
        sql_query.bindValue(":USE_TYPE",userType);
        sql_query.bindValue(":MATERIAL_NAME",materialName);
        sql_query.bindValue(":MATERIAL_MODEL",materialModel);
        sql_query.bindValue(":MANUFACTOR",factoryName);
        sql_query.bindValue(":NUMBER",0);
        sql_query.bindValue(":SINGLE_PRICE",priceStr);
        sql_query.bindValue(":ALL_PRICE",0);
        sql_query.bindValue(":NOTE",noteStr);
        buscess = sql_query.exec();


        if (!buscess)
        {
            qDebug("insert INVENTORY_TABLE error");
        }


    }


    for(int i=0; i<currentItemIndex; i++)
    {
        userTypeItem[i].setText("");
        materialNameItem[i].setText("");
        materialModelItem[i].setText("");
        factoryItem[i].setText("");
        singlePriceItem[i].setText("");
        noteItem[i].setText("");
    }


    currentItemIndex = 0;


}
