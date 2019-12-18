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


void addMaterial_Dialog::setUserName(QString name)
{
    userName = name;
}

void addMaterial_Dialog::initTableWidget()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");




    for(int i=0;i<50;i++)
    {
        ui->tableWidget->setItem(i,0,&waferNumItem[i]);
        ui->tableWidget->setItem(i,1,&productModelItem[i]);
        ui->tableWidget->setItem(i,2,&CPtest_numItem[i]);
        ui->tableWidget->setItem(i,3,&chipNumItem[i]);
        ui->tableWidget->setItem(i,4,&CP_test_specificationItem[i]);
        ui->tableWidget->setItem(i,5,&CP_investmentItem[i]);
        ui->tableWidget->setItem(i,6,&process_demandItem[i]);
        ui->tableWidget->setItem(i,7,&CP_outputItem[i]);
        ui->tableWidget->setItem(i,8,&isChipedItem[i]);
        ui->tableWidget->setItem(i,9,&isBatchedItem[i]);
        ui->tableWidget->setItem(i,10,&noteItem[i]);

        waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        productModelItem[i].setTextAlignment(Qt::AlignCenter);
        CPtest_numItem[i].setTextAlignment(Qt::AlignCenter);
        chipNumItem[i].setTextAlignment(Qt::AlignCenter);
        CP_test_specificationItem[i].setTextAlignment(Qt::AlignCenter);
        CP_investmentItem[i].setTextAlignment(Qt::AlignCenter);
        process_demandItem[i].setTextAlignment(Qt::AlignCenter);
        CP_outputItem[i].setTextAlignment(Qt::AlignCenter);
        isChipedItem[i].setTextAlignment(Qt::AlignCenter);
        isBatchedItem[i].setTextAlignment(Qt::AlignCenter);
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

    QString waterNum = ui->waferNum_lineEdit->text();
    QString productModel = ui->productModel_lineEdit->text();
    QString CPtestNum = ui->CPtest_num_lineEdit->text();
    QString chipNum = ui->chipNum_lineEdit->text();
    QString CP_test_specification = ui->CP_test_specification_lineEdit->text();
    QString CP_investment = ui->CP_investment_lineEdit->text();
    QString process_demand = ui->process_demand_lineEdit->text();
    QString CP_output = ui->CP_output_lineEdit->text();
    QString isChiped = ui->isChiped_comboBox->currentText();
    QString isBatched = ui->isBatched_comboBox->currentText();
    QString note = ui->note_lineEdit->text();

    waferNumItem[currentItemIndex].setText(waterNum);
    productModelItem[currentItemIndex].setText(productModel);
    CPtest_numItem[currentItemIndex].setText(CPtestNum);
    chipNumItem[currentItemIndex].setText(chipNum);
    CP_test_specificationItem[currentItemIndex].setText(CP_test_specification);
    CP_investmentItem[currentItemIndex].setText(CP_investment);
    process_demandItem[currentItemIndex].setText(process_demand);
    CP_outputItem[currentItemIndex].setText(CP_output);
    isChipedItem[currentItemIndex].setText(isChiped);
    isBatchedItem[currentItemIndex].setText(isBatched);
    noteItem[currentItemIndex].setText(note);

    currentItemIndex++;   //当前序号增加1


    ui->waferNum_lineEdit->clear();
    ui->productModel_lineEdit->clear();
    ui->CPtest_num_lineEdit->clear();
    ui->chipNum_lineEdit->clear();
    ui->CP_test_specification_lineEdit->clear();
    ui->CP_investment_lineEdit->clear();
    ui->process_demand_lineEdit->clear();
    ui->CP_output_lineEdit->clear();
    ui->isChiped_comboBox->setCurrentIndex(0);
    ui->isBatched_comboBox->setCurrentIndex(0);
    ui->note_lineEdit->clear();

}




//确定后 添加到数据库
//!
//! \brief addMaterial_Dialog::on_add_pushButton_clicked
//!  1、把界面上的数据填入到数据表中；
//!  2、预留还没做的功能  若结批、结片后  统计数据 良品率 直接写入到数据库中
void addMaterial_Dialog::on_add_pushButton_clicked()
{
    bool buscess;
    for(int i=0; i<currentItemIndex; i++)
    {

        QString waterNum = waferNumItem[i].text();
        QString productModel = productModelItem[i].text();
        QString CPtestNum = CPtest_numItem[i].text();
        QString chipNum = chipNumItem[i].text();
        QString CP_test_specification = CP_test_specificationItem[i].text();
        QString CP_investment = CP_investmentItem[i].text();
        QString process_demand = process_demandItem[i].text();
        QString CP_output = CP_outputItem[i].text();
        QString isChiped = isChipedItem[i].text();
        QString isBatched = isBatchedItem[i].text();
        QString note = noteItem[i].text();

        currentDateTime = QDateTime::currentDateTime();
        QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

//        qDebug()<<userType<<"  "<<materialName<<"  "<<materialModel<<" "<<factoryName<<"  "<<priceStr<<endl;

        sql_query.prepare("INSERT INTO CP_TABLE(waferNum,productModel,CPtest_num,chipNum,CP_test_specification,CP_investment,process_demand,CP_output,isChiped,isBatched,operator,updateTime,note) VALUES(:WATERNUM,:PRODUCTMODEL,:CPTESTNUM,:CHIPNUM,:CPTESTSPECIFICATION,:CPINVESTMENT,:PROCESSDEMAND,:CPOUTPUT,:ISCHIPED,:ISBATCHED,:OPERATOR,:UPDATETIME,:NOTE);");
        sql_query.bindValue(":WATERNUM",waterNum);
        sql_query.bindValue(":PRODUCTMODEL",productModel);
        sql_query.bindValue(":CPTESTNUM",CPtestNum);
        sql_query.bindValue(":CHIPNUM",chipNum);
        sql_query.bindValue(":CPTESTSPECIFICATION",CP_test_specification);
        sql_query.bindValue(":CPINVESTMENT",CP_investment);
        sql_query.bindValue(":PROCESSDEMAND",process_demand);
        sql_query.bindValue(":CPOUTPUT",CP_output);
        sql_query.bindValue(":ISCHIPED",isChiped);
        sql_query.bindValue(":ISBATCHED",isBatched);
        sql_query.bindValue(":OPERATOR",userName);
        sql_query.bindValue(":UPDATETIME",current_time);
        sql_query.bindValue(":NOTE",note);

        buscess = sql_query.exec();
        if (!buscess)
        {
            qDebug("insert CP_TABLE error");
        }

    }

    this->hide();

    for(int i=0; i<currentItemIndex; i++)
    {
        waferNumItem[i].setText("");
        productModelItem[i].setText("");
        CPtest_numItem[i].setText("");
        chipNumItem[i].setText("");
        CP_test_specificationItem[i].setText("");
        CP_investmentItem[i].setText("");
        process_demandItem[i].setText("");
        CP_outputItem[i].setText("");
        isChipedItem[i].setText("");
        isBatchedItem[i].setText("");
        noteItem[i].setText("");
    }

    currentItemIndex = 0;
}
