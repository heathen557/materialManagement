#include "inboundquery_dialog.h"
#include "ui_inboundquery_dialog.h"

extern QSqlQuery sql_query;
inBoundQuery_Dialog::inBoundQuery_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inBoundQuery_Dialog)
{
    ui->setupUi(this);

    currentItemIndex = 0;

    initTableWidget();
}

inBoundQuery_Dialog::~inBoundQuery_Dialog()
{
    delete ui;
}


void inBoundQuery_Dialog::initTableWidget()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");


    for(int i=0;i<50;i++)
    {
        ui->tableWidget->setItem(i,0,&userTypeItem[i]);
        ui->tableWidget->setItem(i,1,&materialNameItem[i]);
        ui->tableWidget->setItem(i,2,&materialModelItem[i]);
        ui->tableWidget->setItem(i,3,&factoryItem[i]);
        ui->tableWidget->setItem(i,4,&numItem[i]);
        ui->tableWidget->setItem(i,5,&operationItem[i]);
        ui->tableWidget->setItem(i,6,&operationTime[i]);
        ui->tableWidget->setItem(i,7,&noteItem[i]);

        userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        factoryItem[i].setTextAlignment(Qt::AlignCenter);
        numItem[i].setTextAlignment(Qt::AlignCenter);
        operationItem[i].setTextAlignment(Qt::AlignCenter);
        operationTime[i].setTextAlignment(Qt::AlignCenter);
        noteItem[i].setTextAlignment(Qt::AlignCenter);
    }
}




void inBoundQuery_Dialog::initSelect()
{
    QString sqlStr;
    //查询所有的用途
    sqlStr = "SELECT DISTINCT USE_TYPE FROM INBOUND_TABLE;";
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
    ui->useType_comboBox->clear();
    ui->useType_comboBox->addItems(useTypeList);


    //查询所有的名称
    sqlStr = "SELECT DISTINCT MATERIAL_NAME FROM INBOUND_TABLE; ";
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
    ui->name_comboBox->clear();
    ui->name_comboBox->addItems(materialList);

    //查询所有的型号
    sqlStr = "SELECT DISTINCT MATERIAL_MODEL FROM INBOUND_TABLE; ";
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
    ui->model_comboBox->clear();
    ui->model_comboBox->addItems(materialModelList);

    //查询所有的厂家
    sqlStr = "SELECT DISTINCT MANUFACTOR FROM INBOUND_TABLE; ";
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
    ui->factory_comboBox->clear();
    ui->factory_comboBox->addItems(manuFactorList);

    //查询所有操作人
    sqlStr = "SELECT DISTINCT OPERATION_USER FROM INBOUND_TABLE;";
    buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"inBoundQuery_Dialog::initSelect() ,selcet operator error! "<<endl;
        return;
    }
    QStringList operationList;
    operationList.append("");
    while (sql_query.next()) {
        QString tmpStr = sql_query.value(0).toString();
        operationList.append(tmpStr);
    }
    ui->operator_comboBox->clear();
    ui->operator_comboBox->addItems(operationList);


    //查询最早的日期 以及最新的日期，更新控件上的日期的时间间隔
    sqlStr = "SELECT MIN(OPERATION_TIME),MAX(OPERATION_TIME) FROM INBOUND_TABLE;";
    buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"inBoundQuery_Dialog::initSelect() ,selcet operator_time error! "<<endl;
        return;
    }
    while(sql_query.next())
    {
        QDateTime beginTime = sql_query.value(0).toDateTime();
        QDateTime endTime = sql_query.value(1).toDateTime();
        ui->dateEdit->setDateTime(beginTime);
        ui->dateEdit_2->setDateTime(endTime);
    }
}

//确定槽函数
void inBoundQuery_Dialog::on_ok_pushButton_clicked()
{
    QString str[7];

    str[0] = ui->useType_comboBox->currentText();
    str[1] = ui->name_comboBox->currentText();
    str[2] = ui->model_comboBox->currentText();
    str[3] = ui->factory_comboBox->currentText();
    int num = ui->number_lineEdit->text().toInt();
    str[4] = ui->operator_comboBox->currentText();
    str[5] = ui->dateEdit->date().toString("yyyy-MM-dd/").append(ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    str[6] = ui->note_lineEdit->text();

   for(int i=0;i<7; i++)
       if(str[i].isEmpty())
           str[i] = "-";

    userTypeItem[currentItemIndex].setText(str[0]);
    materialNameItem[currentItemIndex].setText(str[1]);
    materialModelItem[currentItemIndex].setText(str[2]);
    factoryItem[currentItemIndex].setText(str[3]);
    numItem[currentItemIndex].setText(QString::number(num));
    operationItem[currentItemIndex].setText(str[4]);
    operationTime[currentItemIndex].setText(str[5]);
    noteItem[currentItemIndex].setText(str[6]);

    currentItemIndex++;

    ui->number_lineEdit->clear();
    ui->note_lineEdit->clear();
}


//开始查询槽函数    用途、 数量 、以及时间是查询条件必须的
void inBoundQuery_Dialog::on_select_pushButton_clicked()
{
    QStringList sqlList;
    QString sqlStr,tmpStr;
    QString userType,materialName,materialModel,factory, operatorStr, beginTime,endTime , note;
    int num;

    this->hide();

    for(int i=0; i<currentItemIndex; i++)
    {
        userType = userTypeItem[i].text();
        materialName = materialNameItem[i].text();
        materialModel = materialModelItem[i].text();
        factory = factoryItem[i].text();
        num = numItem[i].text().toInt();
        note = noteItem[i].text();
        operatorStr = operationItem[i].text();
        beginTime = operationTime[i].text().left(10) + " 00:00:00";
        endTime = operationTime[i].text().right(10) + " 23:59:59";
        qDebug()<<"beginTime="<<beginTime<<"  endTime="<<endTime<<endl;

        sqlStr = "SELECT * FROM INBOUND_TABLE WHERE USE_TYPE='"+userType+"' and NUMBER>="+QString::number(num) + " and OPERATION_TIME>='"+beginTime + "' and OPERATION_TIME <='"+endTime+"'" ;
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
        if("-" != operatorStr)
        {
            tmpStr = " and OPERATION_USER='"+operatorStr+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != note)
        {
            tmpStr = " and NOTE LIKE '%"+note+"%'";
            sqlStr.append(tmpStr);
        }
        sqlStr.append(";");

        sqlList.append(sqlStr);

    }

    qDebug()<<sqlList<<endl;

    //将此列表发送给主线程
//    emit selectResult_signal(sqlList);

    emit inBoundSQLResult_signal(sqlList);

    //清空tableWidget上面的数据
    for(int i=0; i<currentItemIndex; i++)
    {
        userTypeItem[i].setText("");
        materialNameItem[i].setText("");
        materialModelItem[i].setText("");
        factoryItem[i].setText("");
        numItem[i].setText("");
        operationItem[i].setText("");
        operationTime[i].setText("");
        noteItem[i].setText("");
    }
    currentItemIndex = 0;
}
