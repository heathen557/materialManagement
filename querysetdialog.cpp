#include "querysetdialog.h"
#include "ui_querysetdialog.h"

extern QSqlQuery sql_query;
querySetDialog::querySetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::querySetDialog)
{
    ui->setupUi(this);
    initTableWidget();
    currentItemIndex = 0;
}


void querySetDialog::initSelect()
{
    //查询所有的用途
    sqlStr = "SELECT DISTINCT USE_TYPE FROM INVENTORY_TABLE ";
    bool buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList useTypeList;
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        useTypeList.append(tmpStr);
    }
    ui->useType_comboBox->addItems(useTypeList);


    //查询所有的名称
    sqlStr = "SELECT DISTINCT MATERIAL_NAME FROM INVENTORY_TABLE ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList  materialList;
    materialList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        materialList.append(tmpStr);
    }
    ui->name_comboBox->addItems(materialList);

    //查询所有的型号
    sqlStr = "SELECT DISTINCT MATERIAL_MODEL FROM INVENTORY_TABLE ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList  materialModelList;
    materialModelList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        materialModelList.append(tmpStr);
    }
    ui->model_comboBox->addItems(materialModelList);

    //查询所有的厂家
    sqlStr = "SELECT DISTINCT MANUFACTOR FROM INVENTORY_TABLE ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList  manuFactorList;
    manuFactorList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        manuFactorList.append(tmpStr);
    }
    ui->factory_comboBox->addItems(manuFactorList);


}

void querySetDialog::initTableWidget()
{
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
        ui->tableWidget->setItem(i,4,&numItem[i]);
        ui->tableWidget->setItem(i,5,&noteItem[i]);

        userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        factoryItem[i].setTextAlignment(Qt::AlignCenter);
        numItem[i].setTextAlignment(Qt::AlignCenter);
        noteItem[i].setTextAlignment(Qt::AlignCenter);
    }
}


querySetDialog::~querySetDialog()
{
    delete ui;
}

//点击确认按钮，忘TABLEWIDGET上添加数据
void querySetDialog::on_pushButton_clicked()
{
    QString str[5];

    str[0] = ui->useType_comboBox->currentText();
    str[1] = ui->name_comboBox->currentText();
    str[2] = ui->model_comboBox->currentText();
    str[3] = ui->factory_comboBox->currentText();
    int num = ui->number_lineEdit->text().toInt();
    str[4] = ui->note_lineEdit->text();

   for(int i=0;i<5; i++)
       if(str[i].isEmpty())
           str[i] = "-";

    userTypeItem[currentItemIndex].setText(str[0]);
    materialNameItem[currentItemIndex].setText(str[1]);
    materialModelItem[currentItemIndex].setText(str[2]);
    factoryItem[currentItemIndex].setText(str[3]);
    numItem[currentItemIndex].setText(QString::number(num));
    noteItem[currentItemIndex].setText(str[4]);

    currentItemIndex++;

    ui->number_lineEdit->clear();
    ui->note_lineEdit->clear();
}

//查询按键
void querySetDialog::on_select_pushButton_clicked()
{
    QStringList sqlList;
    QString sqlStr,tmpStr;
    QString userType,materialName,materialModel,factory,note;
    int num;
    for(int i=0; i<currentItemIndex; i++)
    {
        userType = userTypeItem[i].text();
        materialName = materialNameItem[i].text();
        materialModel = materialModelItem[i].text();
        factory = factoryItem[i].text();
        num = numItem[i].text().toInt();
        note = noteItem[i].text();

        sqlStr = "SELECT * FROM INVENTORY_TABLE WHERE USE_TYPE='"+userType+"' and NUMBER>="+QString::number(num);
        if("-" != materialName)
        {
            tmpStr = " and MATERIAL_NAME='"+materialName+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != materialModel)
        {
            tmpStr = " and MATERIAL_MODEL='"+materialModel+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != factory)
        {
            tmpStr = " and MANUFACTOR='"+factory+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != note)
        {
            tmpStr = " and NOTE LIKE '%"+note+"%';";
            sqlStr.append(tmpStr);
        }

        sqlList.append(sqlStr);

    }

//    qDebug()<<sqlList<<endl;

    //将此列表发送给主线程
    emit selectResult_signal(sqlList);

    //清空tableWidget上面的数据
    for(int i=0; i<currentItemIndex; i++)
    {
        userTypeItem[i].setText("");
        materialNameItem[i].setText("");
        materialModelItem[i].setText("");
        factoryItem[i].setText("");
        numItem[i].setText("");
        noteItem[i].setText("");
    }
    currentItemIndex = 0;







    this->hide();
}


