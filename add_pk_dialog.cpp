#include "add_pk_dialog.h"
#include "ui_add_pk_dialog.h"

extern QSqlQuery sql_query;
add_PK_Dialog::add_PK_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_PK_Dialog)
{
    ui->setupUi(this);

    currentItemIndex = 0;

    initTableWidgt();
}

//!
//! \brief add_PK_Dialog::initTableWidgt
//!
void add_PK_Dialog::initTableWidgt()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");

    for(int i=0;i<50;i++)
    {
        ui->tableWidget->setItem(i,0,&PK_waferNumItem[i]);
        ui->tableWidget->setItem(i,1,&PK_cpTestItem[i]);
        ui->tableWidget->setItem(i,2,&PK_numItem[i]);
        ui->tableWidget->setItem(i,3,&PK_packageTypeItem[i]);
        ui->tableWidget->setItem(i,4,&PK_package_specificationItem[i]);
        ui->tableWidget->setItem(i,5,&PK_investmentItem[i]);
        ui->tableWidget->setItem(i,6,&PK_process_demandItem[i]);
        ui->tableWidget->setItem(i,7,&PK_outputItem[i]);
        ui->tableWidget->setItem(i,8,&PK_noteItem[i]);

        PK_waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        PK_cpTestItem[i].setTextAlignment(Qt::AlignCenter);
        PK_numItem[i].setTextAlignment(Qt::AlignCenter);
        PK_packageTypeItem[i].setTextAlignment(Qt::AlignCenter);
        PK_package_specificationItem[i].setTextAlignment(Qt::AlignCenter);
        PK_investmentItem[i].setTextAlignment(Qt::AlignCenter);
        PK_process_demandItem[i].setTextAlignment(Qt::AlignCenter);
        PK_outputItem[i].setTextAlignment(Qt::AlignCenter);
        PK_noteItem[i].setTextAlignment(Qt::AlignCenter);

        PK_noteItem[i].setText(QString::number(i));
    }

}

//!
//! \brief add_PK_Dialog::setUserName
//! \param name
//!
void add_PK_Dialog::setUserName(QString name)
{
    userName = name;
}


//!
//! \brief add_PK_Dialog::initSelect
//!//初始化  添加列表上面的 控件   初始化 晶圆批号 ，CP测试单号 为默认晶圆批号的第一个  ；
//! 晶圆批号修改后，CP测试单号会刷新数据信息重新载入
void add_PK_Dialog::initSelect()
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
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        waferNumList.append(tmpStr);
    }
    ui->waferNum_comboBox->clear();
    ui->waferNum_comboBox->addItems(waferNumList);

}


//!
//! \brief add_PK_Dialog::on_waferNum_comboBox_currentIndexChanged
//! \param arg1
//!  晶圆批号更新后，同步更新 测试单号的数据信息
void add_PK_Dialog::on_waferNum_comboBox_currentIndexChanged(const QString &arg1)
{
    //查询cp测试单号，在控件上显示
    qDebug()<<"arg1 = "<<arg1;
    bool buscess;
    QString waferNum = arg1;
    sql_query.prepare("SELECT DISTINCT CPtest_num FROM CP_TABLE WHERE waferNum = :waferNum;");
    sql_query.bindValue(":waferNum",waferNum);
    buscess =  sql_query.exec();
    if(!buscess)
    {
        qDebug()<<" add_PK_Dialog::initSelect(),select CPtest_num error"<<endl;
        return;
    }
    QStringList CPTestList;
    while(sql_query.next())
    {
        QString tmpStr = sql_query.value(0).toString();
        CPTestList.append(tmpStr);
    }
    ui->cpTestNum_comboBox->clear();
    ui->cpTestNum_comboBox->addItems(CPTestList);
}

//!
//! \brief add_PK_Dialog::on_ok_pushButton_clicked
//!  增加一行
void add_PK_Dialog::on_ok_pushButton_clicked()
{
    QString waferNum = ui->waferNum_comboBox->currentText();
    QString cpTestNum = ui->cpTestNum_comboBox->currentText();
    QString PK_num = ui->package_lineEdit->text();
    QString pkPackageType = ui->packageType_lineEdit->text();
    QString packageSpecification = ui->packageSpecification_lineEdit->text();
    QString packageInvestion = ui->packageInvestment_lineEdit->text();
    QString processDemand =  ui->process_demand_lineEdit->text();
    QString packageOutput = ui->package_output_lineEdit->text();
    QString note = ui->note_lineEdit->text();

    PK_waferNumItem[currentItemIndex].setText(waferNum);
    PK_cpTestItem[currentItemIndex].setText(cpTestNum);
    PK_numItem[currentItemIndex].setText(PK_num);
    PK_packageTypeItem[currentItemIndex].setText(pkPackageType);
    PK_package_specificationItem[currentItemIndex].setText(packageSpecification);
    PK_investmentItem[currentItemIndex].setText(packageInvestion);
    PK_process_demandItem[currentItemIndex].setText(processDemand);
    PK_outputItem[currentItemIndex].setText(packageOutput);
    PK_noteItem[currentItemIndex].setText(note);

    currentItemIndex++;


    ui->package_lineEdit->clear();
    ui->packageType_lineEdit->clear();
    ui->packageSpecification_lineEdit->clear();
    ui->packageInvestment_lineEdit->clear();
    ui->process_demand_lineEdit->clear();
    ui->package_output_lineEdit->clear();
    ui->note_lineEdit->clear();

}

//!
//! \brief add_PK_Dialog::on_addPK_pushButton_clicked
//!确定添加到数据库
//!
void add_PK_Dialog::on_addPK_pushButton_clicked()
{
    bool buscess;

    PK_waferNumItem[50];
    PK_cpTestItem[50];
    PK_numItem[50];
    PK_packageTypeItem[50];
    PK_package_specificationItem[50];
    PK_investmentItem[50];
    PK_process_demandItem[50];
    PK_outputItem[50];
    PK_noteItem[50];

    for(int i=0; i<currentItemIndex; i++)
    {

        QString PK_waferNum = PK_waferNumItem[i].text();
        QString PK_cpTest = PK_cpTestItem[i].text();
        QString PK_num = PK_numItem[i].text();
        QString PK_packageType = PK_packageTypeItem[i].text();
        QString PK_package_specification = PK_package_specificationItem[i].text();
        QString PK_investment = PK_investmentItem[i].text();
        QString PK_process_demand = PK_process_demandItem[i].text();
        QString PK_output = PK_outputItem[i].text();
        QString PK_yield;
        if(PK_investment.toFloat()>0 && PK_output.toFloat()>0)
        {
            float in_pk = PK_investment.toFloat();
            float out_pk = PK_output.toFloat();
            float yield_pk = out_pk/in_pk;
            PK_yield = QString::number(yield_pk);
        }



        QString PK_note = PK_noteItem[i].text();
        currentDateTime = QDateTime::currentDateTime();
        QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");



//        qDebug()<<userType<<"  "<<materialName<<"  "<<materialModel<<" "<<factoryName<<"  "<<priceStr<<endl;

        sql_query.prepare("INSERT INTO PK_TABLE(waferNum,CPtest_num,PK_num,packageType,package_specification,package_investment,process_demand,package_output,package_yield,operator,updateTime,note)"
                          " VALUES(:waferNum,:CPtest_num,:PK_num,:packageType,:package_specification,:package_investment,:process_demand,:package_output,:package_yield,:operator,:updateTime,:note);");
        sql_query.bindValue(":waferNum",PK_waferNum);
        sql_query.bindValue(":CPtest_num",PK_cpTest);
        sql_query.bindValue(":PK_num",PK_num);
        sql_query.bindValue(":packageType",PK_packageType);
        sql_query.bindValue(":package_specification",PK_package_specification);
        sql_query.bindValue(":package_investment",PK_investment);
        sql_query.bindValue(":process_demand",PK_process_demand);
        sql_query.bindValue(":package_output",PK_output);
        sql_query.bindValue(":package_yield",PK_yield);
        sql_query.bindValue(":operator",userName);
        sql_query.bindValue(":updateTime",current_time);
        sql_query.bindValue(":note",PK_note);

        buscess = sql_query.exec();
        if (!buscess)
        {
            qDebug("insert CP_TABLE error");
        }

    }

    this->hide();

    for(int i=0; i<currentItemIndex; i++)
    {
        PK_waferNumItem[i].setText("");
        PK_cpTestItem[i].setText("");
        PK_numItem[i].setText("");
        PK_packageTypeItem[i].setText("");
        PK_package_specificationItem[i].setText("");
        PK_investmentItem[i].setText("");
        PK_process_demandItem[i].setText("");
        PK_outputItem[i].setText("");
        PK_noteItem[i].setText("");
    }

    currentItemIndex = 0;
}


add_PK_Dialog::~add_PK_Dialog()
{
    delete ui;
}










