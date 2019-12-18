#include "query_pk_dialog.h"
#include "ui_query_pk_dialog.h"

extern QSqlQuery sql_query;
query_pk_Dialog::query_pk_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::query_pk_Dialog)
{
    ui->setupUi(this);

    isSelectFinished = false;    //初始化时 列表全部展现，不能进行下一级的选择；初始化完成以后，用户选择晶圆批号、测试单号，后面列表要同步更新

    currentItemIndex = 0;

    initTableWidget();
}

void query_pk_Dialog::initTableWidget()
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
        ui->tableWidget->setItem(i,0,&PK_waferNumItem[i]);
        ui->tableWidget->setItem(i,1,&PK_cpTestItem[i]);
        ui->tableWidget->setItem(i,2,&PK_numItem[i]);
        ui->tableWidget->setItem(i,3,&PK_userNameItem[i]);
        ui->tableWidget->setItem(i,4,&PK_updateTimeItem[i]);
        ui->tableWidget->setItem(i,5,&PK_noteItem[i]);

        PK_waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        PK_cpTestItem[i].setTextAlignment(Qt::AlignCenter);
        PK_numItem[i].setTextAlignment(Qt::AlignCenter);
        PK_userNameItem[i].setTextAlignment(Qt::AlignCenter);
        PK_updateTimeItem[i].setTextAlignment(Qt::AlignCenter);
        PK_noteItem[i].setTextAlignment(Qt::AlignCenter);
    }
}

void query_pk_Dialog::initSelect()
{
    //查询所有的晶圆批号
    sqlStr = "SELECT DISTINCT waferNum FROM PK_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
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
    ui->waferNum_comboBox->clear();
    ui->waferNum_comboBox->addItems(waferNumList);



    //查询所有的CPtest_num
    sqlStr = "SELECT DISTINCT CPtest_num FROM PK_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select CPtest_num error"<<endl;
        return;
    }
    QStringList CPtest_numList;
    CPtest_numList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        CPtest_numList.append(tmpStr);
    }
    ui->cpTestNum_comboBox->clear();
    ui->cpTestNum_comboBox->addItems(CPtest_numList);


    //查询所有的封装单号
    sqlStr = "SELECT DISTINCT PK_num FROM PK_TABLE; ";
    buscess =  sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"select PK_num error"<<endl;
        return;
    }
    QStringList  PK_numList;
    PK_numList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        PK_numList.append(tmpStr);
    }
    ui->pk_packageNum_comboBox->clear();
    ui->pk_packageNum_comboBox->addItems(PK_numList);

    //查询所有的用户
    sqlStr = "SELECT DISTINCT operator FROM PK_TABLE; ";
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
    sqlStr = "SELECT MIN(updateTime),MAX(updateTime) FROM PK_TABLE;";
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


    isSelectFinished = true;    //激活控件响应
}

//!
//! \brief query_pk_Dialog::on_waferNum_comboBox_currentIndexChanged
//! \param arg1
//! 选择晶圆批号 后更新 CP测试单号的内容
void query_pk_Dialog::on_waferNum_comboBox_currentIndexChanged(const QString &arg1)
{
    if(!isSelectFinished)   //初始化时不进行此项操作
        return;

    QString waferNum = arg1;
    //查询所有的CPtest_num
    sql_query.prepare("SELECT DISTINCT CPtest_num FROM PK_TABLE WHERE waferNum = :waferNum;");
    sql_query.bindValue(":waferNum",waferNum);
    buscess = sql_query.exec();
    if(!buscess)
    {
        qDebug()<<"select CPtest_num error"<<endl;
        return;
    }
    QStringList CPtest_numList;
    CPtest_numList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        CPtest_numList.append(tmpStr);
    }
    ui->cpTestNum_comboBox->clear();
    ui->cpTestNum_comboBox->addItems(CPtest_numList);
    ui->cpTestNum_comboBox->setCurrentIndex(0);

    //清空封装单号
    ui->pk_packageNum_comboBox->clear();
    ui->cpTestNum_comboBox->setCurrentIndex(0);

}

//!
//! \brief query_pk_Dialog::on_cpTestNum_comboBox_currentIndexChanged
//! \param arg1
//!选择CP测试单号后，更新封装单号的内容
void query_pk_Dialog::on_cpTestNum_comboBox_currentIndexChanged(const QString &arg1)
{
    if(!isSelectFinished)   //初始化时不进行此项操作
        return;

    QString cpTestNum = arg1;
    //查询所有的封装单号
    sql_query.prepare("SELECT DISTINCT PK_num FROM PK_TABLE WHERE CPtest_num = :CPtest_num;");
    sql_query.bindValue(":CPtest_num",cpTestNum);
    buscess = sql_query.exec();

    if(!buscess)
    {
        qDebug()<<"select PK_num error"<<endl;
        return;
    }
    QStringList  PK_numList;
    PK_numList.append("");
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        PK_numList.append(tmpStr);
    }
    ui->pk_packageNum_comboBox->clear();
    ui->pk_packageNum_comboBox->addItems(PK_numList);
    ui->pk_packageNum_comboBox->setCurrentIndex(0);
}

//!
//! \brief query_pk_Dialog::on_ok_pushButton_clicked
//!确定 则添加一行查询条件
void query_pk_Dialog::on_ok_pushButton_clicked()
{
    QString str[6];

    str[0] = ui->waferNum_comboBox->currentText();
    str[1] = ui->cpTestNum_comboBox->currentText();
    str[2] = ui->pk_packageNum_comboBox->currentText();
    str[3] = ui->operator_comboBox->currentText();
    str[4] = ui->dateEdit->date().toString("yyyy-MM-dd/").append(ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    str[5] = ui->note_lineEdit->text();

    for(int i=0;i<6; i++)
        if(str[i].isEmpty())
            str[i] = "-";

    PK_waferNumItem[currentItemIndex].setText(str[0]);
    PK_cpTestItem[currentItemIndex].setText(str[1]);
    PK_numItem[currentItemIndex].setText(str[2]);
    PK_userNameItem[currentItemIndex].setText(str[3]);
    PK_updateTimeItem[currentItemIndex].setText(str[4]);
    PK_noteItem[currentItemIndex].setText(str[5]);

    currentItemIndex++;

    ui->note_lineEdit->clear();
}

//!
//! \brief query_pk_Dialog::on_select_pushButton_clicked
//!开始查询
void query_pk_Dialog::on_select_pushButton_clicked()
{
    QStringList sqlList;
    QString sqlStr,tmpStr;
    QString waferNum,CPTestNum,pkPackageNum, operatorName,note,beginTime,endTime;

    this->hide();

    for(int i=0; i<currentItemIndex; i++)
    {
        waferNum = PK_waferNumItem[i].text();
        CPTestNum = PK_cpTestItem[i].text();
        pkPackageNum = PK_numItem[i].text();
        operatorName = PK_userNameItem[i].text();
        beginTime = PK_updateTimeItem[i].text().left(10) + " 00:00:00";
        endTime = PK_updateTimeItem[i].text().right(10) + " 23:59:59";
        note = PK_noteItem[i].text();

        sqlStr = "SELECT * FROM PK_TABLE WHERE updateTime>= '" +beginTime + "' and updateTime<='"+endTime+"' ";
        if("-" != waferNum)
        {
            tmpStr = " and waferNum='"+waferNum+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != CPTestNum)
        {
            tmpStr = " and CPtest_num='"+CPTestNum+"'";
            sqlStr.append(tmpStr);
        }
        if("-" != pkPackageNum)
        {
            tmpStr = " and PK_num='"+pkPackageNum+"'";
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
    emit PK_selectResult_signal(sqlList);

    //清空tableWidget上面的数据
    for(int i=0; i<currentItemIndex; i++)
    {
        PK_waferNumItem[i].setText("");
        PK_cpTestItem[i].setText("");
        PK_numItem[i].setText("");
        PK_userNameItem[i].setText("");
        PK_updateTimeItem[i].setText("");
        PK_noteItem[i].setText("");
    }
    currentItemIndex = 0;
}


query_pk_Dialog::~query_pk_Dialog()
{
    delete ui;
}



