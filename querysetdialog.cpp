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

//!
//! \brief querySetDialog::initSelect
//!查询方式：所有单元都有缺省项，
//! 注意：当选择晶圆批号后，自动更新测试单号的内容，并将测试单号 封装单号置为默认
//!      当选择测试单号后，自动更新封装单号的内容，并将封装单号置为默认
void querySetDialog::initSelect()
{
    //查询所有的晶圆批号
    sqlStr = "SELECT DISTINCT waferNum FROM CP_TABLE; ";
    bool buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select waferNum error"<<endl;
        return;
    }
    QStringList waferNumList;
    waferNumList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        waferNumList.append(tmpStr);
    }
    ui->CP_waferNum_comboBox->clear();
    ui->CP_waferNum_comboBox->addItems(waferNumList);



    //查询所有的产品型号
    sqlStr = "SELECT DISTINCT productModel FROM CP_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select productModel error"<<endl;
        return;
    }
    QStringList productModelList;
    productModelList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        productModelList.append(tmpStr);
    }
    ui->productModel_comboBox->clear();
    ui->productModel_comboBox->addItems(productModelList);


    //查询所有的测试单号
    sqlStr = "SELECT DISTINCT CPtest_num FROM CP_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList  CPtest_numList;
    CPtest_numList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        CPtest_numList.append(tmpStr);
    }
    ui->CP_testNum_comboBox->clear();
    ui->CP_testNum_comboBox->addItems(CPtest_numList);

    //查询所有的用户
    sqlStr = "SELECT DISTINCT operator FROM CP_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select error"<<endl;
        return;
    }
    QStringList  operatorList;
    operatorList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        operatorList.append(tmpStr);
    }
    ui->operator_comboBox->clear();
    ui->operator_comboBox->addItems(operatorList);


    //查询最早的日期 以及最新的日期，更新控件上的日期的时间间隔
    sqlStr = "SELECT MIN(updateTime),MAX(updateTime) FROM CP_TABLE;";
    buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"querySetDialog::initSelect() ,selcet updateTime error! "<<endl;
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


void querySetDialog::initTableWidget()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");


    for(int i=0;i<50;i++)
    {
        ui->tableWidget->setItem(i,0,&waferNumItem[i]);
        ui->tableWidget->setItem(i,1,&productNumItem[i]);
        ui->tableWidget->setItem(i,2,&CP_testNumItem[i]);
        ui->tableWidget->setItem(i,3,&operatorItem[i]);
        ui->tableWidget->setItem(i,4,&operationTimeItem[i]);
        ui->tableWidget->setItem(i,5,&noteItem[i]);

        waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        productNumItem[i].setTextAlignment(Qt::AlignCenter);
        CP_testNumItem[i].setTextAlignment(Qt::AlignCenter);
        operatorItem[i].setTextAlignment(Qt::AlignCenter);
        operationTimeItem[i].setTextAlignment(Qt::AlignCenter);
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
    QString str[6];

    str[0] = ui->CP_waferNum_comboBox->currentText();
    str[1] = ui->productModel_comboBox->currentText();
    str[2] = ui->CP_testNum_comboBox->currentText();
    str[3] = ui->operator_comboBox->currentText();
    str[4] = ui->dateEdit->date().toString("yyyy-MM-dd/").append(ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    str[5] = ui->note_lineEdit->text();

    for(int i=0;i<6; i++)
        if(str[i].isEmpty())
            str[i] = "-";

    waferNumItem[currentItemIndex].setText(str[0]);
    productNumItem[currentItemIndex].setText(str[1]);
    CP_testNumItem[currentItemIndex].setText(str[2]);
    operatorItem[currentItemIndex].setText(str[3]);
    operationTimeItem[currentItemIndex].setText(str[4]);
    noteItem[currentItemIndex].setText(str[5]);

    currentItemIndex++;

    ui->note_lineEdit->clear();

}

//查询按键

//! \brief querySetDialog::on_select_pushButton_clicked
//!  将查询语句封装成 QString=list 传递给主函数  主函数根据查询语句进行查询
void querySetDialog::on_select_pushButton_clicked()
{


    QStringList sqlList;
    QString sqlStr,tmpStr;
    QString waferNum,productModel,CPTestNum,operatorName,note,beginTime,endTime;
    int num;

    this->hide();

    for(int i=0; i<currentItemIndex; i++)
    {
        waferNum = waferNumItem[i].text();
        productModel = productNumItem[i].text();
        CPTestNum = CP_testNumItem[i].text();
        operatorName = operatorItem[i].text();
        beginTime = operationTimeItem[i].text().left(10) + " 00:00:00";
        endTime = operationTimeItem[i].text().right(10) + " 23:59:59";
        note = noteItem[i].text();

        sqlStr = "SELECT * FROM CP_TABLE WHERE updateTime>= '" +beginTime + "' and updateTime<='"+endTime+"' ";
        if("-" != waferNum)
        {
            tmpStr = " and waferNum='"+waferNum+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != productModel)
        {
            tmpStr = " and productModel='"+productModel+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != CPTestNum)
        {
            tmpStr = " and CPtest_num='"+CPTestNum+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != operatorName)
        {
            tmpStr = " and operator='"+operatorName+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != note)
        {
            tmpStr = " and note LIKE '%"+note+"%';";
            sqlStr.append(tmpStr);
        }

        sqlList.append(sqlStr);

    }

    qDebug()<<sqlList<<endl;

    //将此列表发送给主线程
    emit selectResult_signal(sqlList);

    //清空tableWidget上面的数据
    for(int i=0; i<currentItemIndex; i++)
    {
        waferNumItem[i].setText("");
        productNumItem[i].setText("");
        CP_testNumItem[i].setText("");
        operatorItem[i].setText("");
        operationTimeItem[i].setText("");
        noteItem[i].setText("");
    }
    currentItemIndex = 0;
}


