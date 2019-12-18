#pragma execution_character_set("utf-8")

#include "uidemo01.h"
#include "ui_uidemo01.h"
#include "iconhelper.h"
#include<QHBoxLayout>

extern QSqlQuery sql_query;

UIDemo01::UIDemo01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo01)
{
    ui->setupUi(this);
    this->initForm();

    onePageNotesNum = 10;

    currentClickIndex = 0;
    currentUserClickIndex = 0;

    //界面上添加分页控件
    PC_pageWidget = new PageWidget();
    lable1 = new QLabel();
    lable1->setText("总记录数：0");

    //CP物资管理页
    QLabel *PCTMP1 = new QLabel();
    QLabel *PCTMP2 = new QLabel();
    QLabel *PCTMP3 = new QLabel();
    QLabel *PCTMP4 = new QLabel();

    QHBoxLayout *hLayout = new QHBoxLayout(ui->CP_widget);
    hLayout->addWidget(lable1,2);
    hLayout->addWidget(PCTMP1,1);
    hLayout->addWidget(PCTMP2,2);
    hLayout->addWidget(PCTMP3,1);
    hLayout->addWidget(PCTMP4,10);
    hLayout->addWidget(PC_pageWidget,4);

    //PK封装查询页
    QLabel *PKTMP1 = new QLabel();
    QLabel *PKTMP2 = new QLabel();
    QLabel *PKTMP3 = new QLabel();
    QLabel *PKTMP4 = new QLabel();
    PK_pageWidget = new PageWidget();
    PK_label = new QLabel();
    PK_label->setText("总记录数：0");
    QHBoxLayout *PK_BoundLayout = new QHBoxLayout(ui->PK_widget);
    PK_BoundLayout->addWidget(PK_label,2);
    PK_BoundLayout->addWidget(PKTMP1,1);
    PK_BoundLayout->addWidget(PKTMP2,2);
    PK_BoundLayout->addWidget(PKTMP3,1);
    PK_BoundLayout->addWidget(PKTMP4,10);
    PK_BoundLayout->addWidget(PK_pageWidget,4);


    //FT封装查询页
    QLabel *FTTMP1 = new QLabel();
    QLabel *FTTMP2 = new QLabel();
    QLabel *FTTMP3 = new QLabel();
    QLabel *FTTMP4 = new QLabel();
    FT_pageWidget = new PageWidget();
    FT_label = new QLabel();
    FT_label->setText("总记录数：0");
    QHBoxLayout *FT_BoundLayout = new QHBoxLayout(ui->FT_widget);
    FT_BoundLayout->addWidget(FT_label,2);
    FT_BoundLayout->addWidget(FTTMP1,1);
    FT_BoundLayout->addWidget(FTTMP2,2);
    FT_BoundLayout->addWidget(FTTMP3,1);
    FT_BoundLayout->addWidget(FTTMP4,10);
    FT_BoundLayout->addWidget(FT_pageWidget,4);



    //入库查询页
    QLabel *tempLabel = new QLabel();
    inBound_PageWidget = new PageWidget();
    inBound_label = new QLabel();
    inBound_label->setText("总记录数：0");
    QHBoxLayout *inBoundLayout = new QHBoxLayout(ui->inBound_pagewidget);
    inBoundLayout->addWidget(inBound_label,2);
    inBoundLayout->addWidget(tempLabel,8);
    inBoundLayout->addWidget(inBound_PageWidget,8);

    //出库查询页
    QLabel *tempLabel2 = new QLabel();
    outBound_PageWidget = new PageWidget();
    outBound_label = new QLabel();
    outBound_label->setText("总记录数：0");
    QHBoxLayout *outBoundLayout = new QHBoxLayout(ui->outBound_pagewidget);
    outBoundLayout->addWidget(outBound_label,2);
    outBoundLayout->addWidget(tempLabel2,8);
    outBoundLayout->addWidget(outBound_PageWidget,8);


    //    initSql();
    initConnect();
    init_tableWidget();

    emit setMaxPage_signal(1);
    emit PK_setMaxPage_signal(1);
    emit setInBoundPage_signal(1);
    emit setOutBoundPage_signal(1);



//    ui->CP_addMaterial_pushButton->setEnabled(false);
//    ui->CP_alterMaterial_pushButton->setEnabled(false);

}

//初始化CP_tableWidget界面
void UIDemo01::init_tableWidget()
{
    //物资管理界面  CP订单管理界面
    ui->CP_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->CP_tableWidget->setRowCount(onePageNotesNum);
    ui->CP_tableWidget->setColumnCount(16);
    ui->CP_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->CP_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->CP_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->CP_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");

    for(int i=0;i<onePageNotesNum;i++)
    {

        ui->CP_tableWidget->setItem(i,0,&CP_waferNumItem[i]);
        ui->CP_tableWidget->setItem(i,1,&CP_productModelItem[i]);
        ui->CP_tableWidget->setItem(i,2,&CP_test_numItem[i]);
        ui->CP_tableWidget->setItem(i,3,&CP_chipNumItem[i]);
        ui->CP_tableWidget->setItem(i,4,&CP_test_specificationItem[i]);
        ui->CP_tableWidget->setItem(i,5,&CP_investmentItem[i]);
        ui->CP_tableWidget->setItem(i,6,&CP_process_demandItem[i]);
        ui->CP_tableWidget->setItem(i,7,&CP_outputItem[i]);
        ui->CP_tableWidget->setItem(i,8,&CP_yieldItem[i]);
        ui->CP_tableWidget->setItem(i,9,&CP_isChipedItem[i]);
        ui->CP_tableWidget->setItem(i,10,&CP_chip_yieldItem[i]);
        ui->CP_tableWidget->setItem(i,11,&CP_isBatchedItem[i]);
        ui->CP_tableWidget->setItem(i,12,&CP_batch_yieldItem[i]);
        ui->CP_tableWidget->setItem(i,13,&CP_operatorItem[i]);
        ui->CP_tableWidget->setItem(i,14,&CP_updateTimeItem[i]);
        ui->CP_tableWidget->setItem(i,15,&CP_noteItem[i]);

        CP_waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        CP_productModelItem[i].setTextAlignment(Qt::AlignCenter);
        CP_test_numItem[i].setTextAlignment(Qt::AlignCenter);
        CP_chipNumItem[i].setTextAlignment(Qt::AlignCenter);
        CP_test_specificationItem[i].setTextAlignment(Qt::AlignCenter);
        CP_investmentItem[i].setTextAlignment(Qt::AlignCenter);
        CP_process_demandItem[i].setTextAlignment(Qt::AlignCenter);
        CP_outputItem[i].setTextAlignment(Qt::AlignCenter);
        CP_yieldItem[i].setTextAlignment(Qt::AlignCenter);
        CP_isChipedItem[i].setTextAlignment(Qt::AlignCenter);
        CP_chip_yieldItem[i].setTextAlignment(Qt::AlignCenter);
        CP_isBatchedItem[i].setTextAlignment(Qt::AlignCenter);
        CP_batch_yieldItem[i].setTextAlignment(Qt::AlignCenter);
        CP_operatorItem[i].setTextAlignment(Qt::AlignCenter);
        CP_updateTimeItem[i].setTextAlignment(Qt::AlignCenter);
        CP_noteItem[i].setTextAlignment(Qt::AlignCenter);
    }

    //PK 封装订单界面
    ui->PK_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->PK_tableWidget->setRowCount(onePageNotesNum);
    ui->PK_tableWidget->setColumnCount(12);
    ui->PK_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->PK_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->PK_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->PK_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");

    for(int i=0;i<onePageNotesNum;i++)
    {

        ui->PK_tableWidget->setItem(i,0,&PK_waferNumItem[i]);
        ui->PK_tableWidget->setItem(i,1,&PK_cpTestItem[i]);
        ui->PK_tableWidget->setItem(i,2,&PK_numItem[i]);
        ui->PK_tableWidget->setItem(i,3,&PK_packageTypeItem[i]);
        ui->PK_tableWidget->setItem(i,4,&PK_package_specificationItem[i]);
        ui->PK_tableWidget->setItem(i,5,&PK_investmentItem[i]);
        ui->PK_tableWidget->setItem(i,6,&PK_process_demandItem[i]);
        ui->PK_tableWidget->setItem(i,7,&PK_outputItem[i]);
        ui->PK_tableWidget->setItem(i,8,&PK_yieldItem[i]);
        ui->PK_tableWidget->setItem(i,9,&PK_operatorItem[i]);
        ui->PK_tableWidget->setItem(i,10,&PK_updateTimeItem[i]);
        ui->PK_tableWidget->setItem(i,11,&PK_noteItem[i]);

        PK_waferNumItem[i].setTextAlignment(Qt::AlignCenter);
        PK_cpTestItem[i].setTextAlignment(Qt::AlignCenter);
        PK_numItem[i].setTextAlignment(Qt::AlignCenter);
        PK_packageTypeItem[i].setTextAlignment(Qt::AlignCenter);
        PK_package_specificationItem[i].setTextAlignment(Qt::AlignCenter);
        PK_investmentItem[i].setTextAlignment(Qt::AlignCenter);
        PK_process_demandItem[i].setTextAlignment(Qt::AlignCenter);
        PK_outputItem[i].setTextAlignment(Qt::AlignCenter);
        PK_yieldItem[i].setTextAlignment(Qt::AlignCenter);
        PK_operatorItem[i].setTextAlignment(Qt::AlignCenter);
        PK_updateTimeItem[i].setTextAlignment(Qt::AlignCenter);
        PK_noteItem[i].setTextAlignment(Qt::AlignCenter);

    }


    //FT 封装订单界面
    ui->FT_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->FT_tableWidget->setRowCount(onePageNotesNum);
    ui->FT_tableWidget->setColumnCount(14);
    ui->FT_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->FT_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->FT_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->FT_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");

    for(int i=0;i<onePageNotesNum;i++)
    {
//        ui->FT_tableWidget->setItem(i,0,&userTypeItem[i]);
//        ui->FT_tableWidget->setItem(i,1,&materialNameItem[i]);
//        ui->FT_tableWidget->setItem(i,2,&materialModelItem[i]);
//        ui->FT_tableWidget->setItem(i,3,&factoryItem[i]);
//        ui->FT_tableWidget->setItem(i,4,&numberItem[i]);
//        ui->FT_tableWidget->setItem(i,5,&singlePriceItem[i]);
//        ui->FT_tableWidget->setItem(i,6,&allPriceItem[i]);
//        ui->FT_tableWidget->setItem(i,7,&noteItem[i]);


//        userTypeItem[i].setTextAlignment(Qt::AlignCenter);
//        materialNameItem[i].setTextAlignment(Qt::AlignCenter);
//        materialModelItem[i].setTextAlignment(Qt::AlignCenter);
//        factoryItem[i].setTextAlignment(Qt::AlignCenter);
//        numberItem[i].setTextAlignment(Qt::AlignCenter);
//        singlePriceItem[i].setTextAlignment(Qt::AlignCenter);
//        allPriceItem[i].setTextAlignment(Qt::AlignCenter);
//        noteItem[i].setTextAlignment(Qt::AlignCenter);
    }



    //入库查询界面相关

    ui->inBound_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->inBound_tableWidget->setRowCount(onePageNotesNum);
    ui->inBound_tableWidget->setColumnCount(10);
    ui->inBound_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->inBound_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->inBound_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->inBound_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");
    ui->inBound_tableWidget->setColumnWidth(8,130);


    for(int i=0;i<onePageNotesNum;i++)
    {
        ui->inBound_tableWidget->setItem(i,0,&inBound_userTypeItem[i]);
        ui->inBound_tableWidget->setItem(i,1,&inBound_materialNameItem[i]);
        ui->inBound_tableWidget->setItem(i,2,&inBound_materialModelItem[i]);
        ui->inBound_tableWidget->setItem(i,3,&inBound_factoryItem[i]);
        ui->inBound_tableWidget->setItem(i,4,&inBound_numberItem[i]);
        ui->inBound_tableWidget->setItem(i,5,&inBound_singlePriceItem[i]);
        ui->inBound_tableWidget->setItem(i,6,&inBound_allPriceItem[i]);
        ui->inBound_tableWidget->setItem(i,7,&inBound_operatiorItem[i]);
        ui->inBound_tableWidget->setItem(i,8,&inBound_operaTimeItem[i]);
        ui->inBound_tableWidget->setItem(i,9,&inBound_noteItem[i]);

        inBound_userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_factoryItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_numberItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_singlePriceItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_allPriceItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_operatiorItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_operaTimeItem[i].setTextAlignment(Qt::AlignCenter);
        inBound_noteItem[i].setTextAlignment(Qt::AlignCenter);
    }


    //出库查询界面相关
    ui->outBound_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->outBound_tableWidget->setRowCount(onePageNotesNum);
    ui->outBound_tableWidget->setColumnCount(11);
    ui->outBound_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->outBound_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->outBound_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->outBound_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");
    ui->outBound_tableWidget->setColumnWidth(9,130);


    for(int i=0;i<onePageNotesNum;i++)
    {
        ui->outBound_tableWidget->setItem(i,0,&outBound_userTypeItem[i]);
        ui->outBound_tableWidget->setItem(i,1,&outBound_materialNameItem[i]);
        ui->outBound_tableWidget->setItem(i,2,&outBound_materialModelItem[i]);
        ui->outBound_tableWidget->setItem(i,3,&outBound_factoryItem[i]);
        ui->outBound_tableWidget->setItem(i,4,&outBound_numberItem[i]);
        ui->outBound_tableWidget->setItem(i,5,&outBound_singlePriceItem[i]);
        ui->outBound_tableWidget->setItem(i,6,&outBound_allPriceItem[i]);
        ui->outBound_tableWidget->setItem(i,7,&outBound_operatiorItem[i]);
        ui->outBound_tableWidget->setItem(i,8,&outBound_RecipientItem[i]);
        ui->outBound_tableWidget->setItem(i,9,&outBound_operaTimeItem[i]);
        ui->outBound_tableWidget->setItem(i,10,&outBound_noteItem[i]);

        outBound_userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_factoryItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_numberItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_singlePriceItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_allPriceItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_operatiorItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_RecipientItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_operaTimeItem[i].setTextAlignment(Qt::AlignCenter);
        outBound_noteItem[i].setTextAlignment(Qt::AlignCenter);
    }


    //用户管理界面相关
    ui->user_tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->user_tableWidget->setRowCount(onePageNotesNum);
    ui->user_tableWidget->setColumnCount(4);
    ui->user_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->user_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->user_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->user_tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");
    ui->user_tableWidget->setColumnWidth(3,180);



    for(int i=0;i<onePageNotesNum;i++)
    {
        ui->user_tableWidget->setItem(i,0,&userNameItem[i]);
        ui->user_tableWidget->setCellWidget(i,1,&userPassWord_lineEdit[i]);
        ui->user_tableWidget->setItem(i,2,&authorityItem[i]);
        ui->user_tableWidget->setItem(i,3,&userNoteItem[i]);

        //        lineText[i].setText(QString::number(i));
        userPassWord_lineEdit[i].setEchoMode(QLineEdit::Password);   //不显示密码
        userPassWord_lineEdit[i].setReadOnly(true);
        userPassWord_lineEdit[i].setAlignment(Qt::AlignCenter);
        userNameItem[i].setTextAlignment(Qt::AlignCenter);
        authorityItem[i].setTextAlignment(Qt::AlignCenter);
        userNoteItem[i].setTextAlignment(Qt::AlignCenter);
    }

}

void UIDemo01::clear_tableWidgetItem()
{
    currentClickIndex = 0;
    for(int i = 0 ; i<50; i++)
    {
        CP_waferNumItem[i].setText("");
        CP_productModelItem[i].setText("");
        CP_test_numItem[i].setText("");
        CP_chipNumItem[i].setText("");
        CP_test_specificationItem[i].setText("");
        CP_investmentItem[i].setText("");
        CP_process_demandItem[i].setText("");
        CP_outputItem[i].setText("");
        CP_yieldItem[i].setText("");
        CP_isChipedItem[i].setText("");
        CP_chip_yieldItem[i].setText("");
        CP_isBatchedItem[i].setText("");
        CP_batch_yieldItem[i].setText("");
        CP_operatorItem[i].setText("");
        CP_updateTimeItem[i].setText("");
        CP_noteItem[i].setText("");

        PK_waferNumItem[i].setText("");
        PK_cpTestItem[i].setText("");
        PK_numItem[i].setText("");
        PK_packageTypeItem[i].setText("");
        PK_package_specificationItem[i].setText("");
        PK_investmentItem[i].setText("");
        PK_process_demandItem[i].setText("");
        PK_outputItem[i].setText("");
        PK_yieldItem[i].setText("");
        PK_operatorItem[i].setText("");
        PK_updateTimeItem[i].setText("");
        PK_noteItem[i].setText("");


        inBound_userTypeItem[i].setText("");
        inBound_materialNameItem[i].setText("");
        inBound_materialModelItem[i].setText("");
        inBound_factoryItem[i].setText("");
        inBound_numberItem[i].setText("");
        inBound_singlePriceItem[i].setText("");
        inBound_allPriceItem[i].setText("");
        inBound_operatiorItem[i].setText("");
        inBound_operaTimeItem[i].setText("");
        inBound_noteItem[i].setText("");

        outBound_userTypeItem[i].setText("");
        outBound_materialNameItem[i].setText("");
        outBound_materialModelItem[i].setText("");
        outBound_factoryItem[i].setText("");
        outBound_numberItem[i].setText("");
        outBound_singlePriceItem[i].setText("");
        outBound_allPriceItem[i].setText("");
        outBound_operatiorItem[i].setText("");
        outBound_RecipientItem[i].setText("");
        outBound_operaTimeItem[i].setText("");
        outBound_noteItem[i].setText("");

        userNameItem[i].setText("");
        authorityItem[i].setText("");
        userNoteItem[i].setText("");
    }
}



void UIDemo01::initConnect()
{
    connect(&managmentQuery_dia,SIGNAL(selectResult_signal(QStringList)),this,SLOT(selectResult_slot(QStringList)));

    connect(PC_pageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(showSpecifiedPage(int)));     //插件页数变换的时候，发出信号，然后更新

    connect(this,SIGNAL(setMaxPage_signal(int)),PC_pageWidget,SLOT(setMaxPage(int)));



    connect(&alterMaterial_dia,SIGNAL(alterMaterial_signal(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)),this,SLOT(alterMaterial_slot(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString)));  //修改物料信息后 同步到主界面的显示界面

    connect(&alterMaterial_dia,SIGNAL(delMaterial_signal()),this,SLOT(delMaterial_slot()));  //修改物料信息后 同步到主界面的显示界面

    connect(&inBound_dia,SIGNAL(inBoundNum_Signal(int,float)),this,SLOT(inBoundNum_Slot(int,float)));

    connect(&outBound_dia,SIGNAL(outBoundNum_Signal(int,float)),this,SLOT(inBoundNum_Slot(int,float)));

    connect(&inBoundQuery_dia,SIGNAL(inBoundSQLResult_signal(QStringList)),this,SLOT(inBoundSQLResult_slot(QStringList)));

    connect(inBound_PageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(showinBound_SpecifiedPage(int)));

    connect(this,SIGNAL(setInBoundPage_signal(int)),inBound_PageWidget,SLOT(setMaxPage(int)));


    connect(&outBoundQuery_dia,SIGNAL(outBoundSQLResult_signal(QStringList)),this,SLOT(outBoundSQLResult_slot(QStringList)));

    connect(this,SIGNAL(setOutBoundPage_signal(int)),outBound_PageWidget,SLOT(setMaxPage(int)));

    //用户管理
    connect(&addUserDia,SIGNAL(addUserOneNoteSignal(QString,QString,QString,QString)),this,SLOT(addUserOneNoteSlot(QString,QString,QString,QString)));

    connect(&alterUserDia,SIGNAL(alterUserOneNoteSignal(QString,QString,QString,QString)),this,SLOT(alterUserOneNoteSlot(QString,QString,QString,QString)));


    //PK
    connect(this,SIGNAL(PK_setMaxPage_signal(int)),PK_pageWidget,SLOT(setMaxPage(int)));
    connect(PK_pageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(PK_showSpecifiedPage(int)));     //插件页数变换的时候，发出信号，然后更新
    connect(&pK_query_dia,SIGNAL(PK_selectResult_signal(QStringList)),this,SLOT(PK_selectResult_slot(QStringList)));
}

//数据库初始化函数
void UIDemo01::initSql()
{
    //数据库连接部分
    QSqlDatabase db;
    QStringList drivers = QSqlDatabase::drivers();
    //    foreach(QString driver, drivers)
    //        qDebug() << "\t " << driver;
    //    qDebug() << "End";

    if (!QSqlDatabase::contains("test"))
    {
        db = QSqlDatabase::addDatabase("QMYSQL");   //, "localhost@3306"
        db.setHostName("localhost");    //数据库主机名
        db.setDatabaseName("test");    //数据库名
        db.setUserName("root");        //数据库用户名
        db.setPassword("");        //数据库密码
    }

    bool bisOpenn = db.open();          //打开数据库连接
    qDebug()<<"bisOpenn="<<bisOpenn;

    if (!db.open())
    {
        QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("数据库连接失败"));
    }
    db.exec("SET NAMES 'UTF-8'"); ///设置utf-8编码


    //创建数据表
    QSqlQuery sqlQuery(db);
    sql_query = sqlQuery;   //赋值给全局变量
    QString sqlStr;
    bool buscess;
    // 1 创建用户表
    sqlStr = "create table USER_TABLE(ID int primary key AUTO_INCREMENT, USER_NAME varchar(20), PASSWORD varchar(20), PERMISSION varchar(20),NOTE varchar(300)) charset=utf8;";
    buscess = sqlQuery.exec(sqlStr);
    if (!buscess)
    {
        qDebug("create USER_TABLE  error");
    }

    //2 创建当前的库存信息表  ID 、用途、名称、型号、厂家、数量、单价、总价、备注
    sqlStr = "create table INVENTORY_TABLE(ID int primary key AUTO_INCREMENT, USE_TYPE varchar(20), MATERIAL_NAME varchar(20),MATERIAL_MODEL varchar(20),MANUFACTOR varchar(100),NUMBER int,SINGLE_PRICE float,ALL_PRICE float,NOTE varchar(300)) charset=utf8;";
    buscess = sqlQuery.exec(sqlStr);
    if (!buscess)
    {
        qDebug("create INVENTORY_TABLE error");
    }

    //3 存储物料的入库记录  INBOUND_TABLE；  字段：ID、用途、名称、型号、厂家、数量、单价、总价、操作人，操作日期、备注
    sqlStr = "create table INBOUND_TABLE(ID int primary key AUTO_INCREMENT, USE_TYPE varchar(20), MATERIAL_NAME varchar(20),MATERIAL_MODEL varchar(20),MANUFACTOR varchar(100),NUMBER int,SINGLE_PRICE float,ALL_PRICE float,OPERATION_USER varchar(20),OPERATION_TIME datetime ,NOTE varchar(300)) charset=utf8;";
    buscess = sqlQuery.exec(sqlStr);
    if (!buscess)
    {
        qDebug("create INBOUND_TABLE  error");
    }

    //3 存储物料的出库记录  OUTBOUND_TABLE；  字段：ID、用途、名称、型号、厂家、数量、单价、总价、操作人，领用人、操作日期、备注
    sqlStr = "create table OUTBOUND_TABLE(ID int primary key AUTO_INCREMENT, USE_TYPE varchar(20), MATERIAL_NAME varchar(20),MATERIAL_MODEL varchar(20),MANUFACTOR varchar(100),NUMBER int,SINGLE_PRICE float,ALL_PRICE float,OPERATION_USER varchar(20),RECIPIENT varchar(20), OPERATION_TIME datetime ,NOTE varchar(300)) charset=utf8;";
    buscess = sqlQuery.exec(sqlStr);
    if (!buscess)
    {
        qDebug("create OUTBOUND_TABLE  error");
    }

}




UIDemo01::~UIDemo01()
{
    delete ui;
}

bool UIDemo01::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        if (watched == ui->widgetTitle) {
            on_btnMenu_Max_clicked();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}

//界面的初始化
void UIDemo01::initForm()
{
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf099), 30);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    //ui->widgetMenu->setVisible(false);
    ui->widgetTitle->installEventFilter(this);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->labTitle->setText("芯视界物资管理平台");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
    this->setWindowTitle(ui->labTitle->text());

    ui->stackedWidget->setStyleSheet("QLabel{font:60pt;}");

    //单独设置指示器大小
    int addWidth = 20;
    int addHeight = 10;
    int rbtnWidth = 15;
    int ckWidth = 13;
    int scrWidth = 12;
    int borderWidth = 3;

    QStringList qss;
    qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{width:%1px;}").arg(addWidth));
    qss.append(QString("QComboBox::down-arrow,QDateEdit[calendarPopup=\"true\"]::down-arrow,QTimeEdit[calendarPopup=\"true\"]::down-arrow,"
                       "QDateTimeEdit[calendarPopup=\"true\"]::down-arrow{width:%1px;height:%1px;right:2px;}").arg(addHeight));
    qss.append(QString("QRadioButton::indicator{width:%1px;height:%1px;}").arg(rbtnWidth));
    qss.append(QString("QCheckBox::indicator,QGroupBox::indicator,QTreeWidget::indicator,QListWidget::indicator{width:%1px;height:%1px;}").arg(ckWidth));
    qss.append(QString("QScrollBar:horizontal{min-height:%1px;border-radius:%2px;}QScrollBar::handle:horizontal{border-radius:%2px;}"
                       "QScrollBar:vertical{min-width:%1px;border-radius:%2px;}QScrollBar::handle:vertical{border-radius:%2px;}").arg(scrWidth).arg(scrWidth / 2));
    qss.append(QString("QWidget#widget_top>QToolButton:pressed,QWidget#widget_top>QToolButton:hover,"
                       "QWidget#widget_top>QToolButton:checked,QWidget#widget_top>QLabel:hover{"
                       "border-width:0px 0px %1px 0px;}").arg(borderWidth));
    qss.append(QString("QWidget#widgetleft>QPushButton:checked,QWidget#widgetleft>QToolButton:checked,"
                       "QWidget#widgetleft>QPushButton:pressed,QWidget#widgetleft>QToolButton:pressed{"
                       "border-width:0px 0px 0px %1px;}").arg(borderWidth));
    this->setStyleSheet(qss.join(""));


    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnMain->click();
}

//选中上方的控件
void UIDemo01::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        if (btn == b) {
            btn->setChecked(true);
        } else {
            btn->setChecked(false);
        }
    }

    if (name == "订单管理") {
        ui->stackedWidget->setCurrentIndex(0);
        clear_tableWidgetItem();
    } else if (name == "入库查询") {
        ui->stackedWidget->setCurrentIndex(1);
        clear_tableWidgetItem();
    } else if (name == "出库查询") {
        ui->stackedWidget->setCurrentIndex(2);
        clear_tableWidgetItem();
    } else if (name == "用户管理") {
        if(UserAuthority != "管理员")
        {
            QMessageBox::information(NULL,"提示","您没有权限");
            return;
        }


        ui->stackedWidget->setCurrentIndex(3);
        clear_tableWidgetItem();
        initUserTableWidget();
    } else if (name == "系统退出") {
        exit(0);
    }
}

//最小化操作
void UIDemo01::on_btnMenu_Min_clicked()
{
    showMinimized();
}


//最大化操作
void UIDemo01::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}


//用户退出槽函数
void UIDemo01::on_btnMenu_Close_clicked()
{
    close();
}


//新增物料的按钮
void UIDemo01::on_CP_addMaterial_pushButton_clicked()
{
    addMaterial_dia.show();
}

//物料管理的查询按钮
void UIDemo01::on_CP_managerQuery_pushButton_clicked()
{
    //先初始化 查询相关的控件上的数据
    managmentQuery_dia.setModal(true);

    managmentQuery_dia.initSelect();

    managmentQuery_dia.show();
}


//物料查询结果接收的槽函数
//!
//! \brief UIDemo01::selectResult_slot
//! \param sqlList
//!   1、将语句进行查询，然后把所有数据存储在 allDataList当中  ，它的长度应该为是 16的倍数
//!   2、计算记录的条数
//!   3、最大的页数
//!   4、然后显示第一页
void UIDemo01::selectResult_slot(QStringList sqlList)
{
    allDataList.clear();  //每次查询都清空已有的数据
    qDebug()<<" the sql = "<<sqlList<<endl;
    QString sqlStr;

    for(int i=0; i<sqlList.length(); i++)
    {
        sqlStr = sqlList[i];
        bool buscess =  sql_query.exec(sqlStr);
        if(!buscess)
        {
            qDebug()<<" selectResult_slot()  select error !!"<<endl;
            return;
        }
        while(sql_query.next())
        {
            for(int k=1 ;k<17; k++)
            {
                allDataList.append(sql_query.value(k).toString());
            }

        }
    }

    int allNotes = allDataList.length()/16;
    QString str = "总记录数：" + QString::number(allNotes);    //显示记录数
    lable1->setText(str);


    int maxPage ;
    maxPage = allNotes/onePageNotesNum ;
    if(0 != allNotes%onePageNotesNum )
    {
        maxPage = maxPage + 1;
    }


    emit setMaxPage_signal(maxPage);
    showSpecifiedPage(1);
}

//一页显示的条目数量  初始化为50
void UIDemo01::showSpecifiedPage(int pageNum)
{
    PC_pageWidget->setLineEdit(pageNum);

    //先清空CP_tableWidget上的显示
    clear_tableWidgetItem();

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = allDataList.length()/16;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {

        CP_waferNumItem[index].setText( allDataList[i*16+0]);
        CP_productModelItem[index].setText( allDataList[i*16+1]);
        CP_test_numItem[index].setText( allDataList[i*16+2]);
        CP_chipNumItem[index].setText( allDataList[i*16+3]);
        CP_test_specificationItem[index].setText( allDataList[i*16+4]);
        CP_investmentItem[index].setText( allDataList[i*16+5]);
        CP_process_demandItem[index].setText( allDataList[i*16+6]);
        CP_outputItem[index].setText( allDataList[i*16+7]);
        CP_yieldItem[index].setText( allDataList[i*16+8]);
        CP_isChipedItem[index].setText( allDataList[i*16+9]);
        CP_chip_yieldItem[index].setText( allDataList[i*16+10]);
        CP_isBatchedItem[index].setText( allDataList[i*16+11]);
        CP_batch_yieldItem[index].setText( allDataList[i*16+12]);
        CP_operatorItem[index].setText( allDataList[i*16+13]);
        QString updateTimeStr = allDataList[i*16+14];
        updateTimeStr = updateTimeStr.replace("T"," ");
        CP_updateTimeItem[index].setText(updateTimeStr);
        CP_noteItem[index].setText( allDataList[i*16+15]);
        index++;
    }
}


//返回总库
void UIDemo01::on_CP_returnALL_pushButton_clicked()
{
    QString str = "SELECT * FROM CP_TABLE; ";
    QStringList strList ;
    strList.append(str);
    selectResult_slot(strList);

}


//单击QModelIndex的槽响应函数
void UIDemo01::on_CP_tableWidget_clicked(const QModelIndex &index)
{
    qDebug()<<" clicked ="<< index.row()<<endl;
    currentClickIndex = index.row();
}


//修改物料 按钮
void UIDemo01::on_CP_alterMaterial_pushButton_clicked()
{
   QString waferNum =  CP_waferNumItem[currentClickIndex].text();
   QString productModel = CP_productModelItem[currentClickIndex].text();
   QString CPtest_num =  CP_test_numItem[currentClickIndex].text();
   QString chipNum = CP_chipNumItem[currentClickIndex].text();
   QString CP_test_specification = CP_test_specificationItem[currentClickIndex].text();
   QString CP_investment = CP_investmentItem[currentClickIndex].text();
   QString process_demand =  CP_process_demandItem[currentClickIndex].text();
   QString CP_output = CP_outputItem[currentClickIndex].text();
   QString isChiped = CP_isChipedItem[currentClickIndex].text();
   QString isBatched = CP_isBatchedItem[currentClickIndex].text();
   QString note = CP_noteItem[currentClickIndex].text();


    if(waferNum.isEmpty())
    {
        QMessageBox::information(NULL,"提示","请先选中要操作的数据");
        return;
    }
    alterMaterial_dia.setUserName(UserName);
    alterMaterial_dia.initMaterialInfo(waferNum,productModel,CPtest_num,chipNum,CP_test_specification,CP_investment,process_demand,CP_output,isChiped,isBatched,note);
    alterMaterial_dia.show();
}


//接收修改界面后的信息的槽函数
//emit alterMaterial_signal(userType,materialName,materialModel,factoryName,noteStr,singlePrice,allPrice);
//   cpTestNum,  cpTestSpecification,  cpInvestment,   processDemand,       cpOutput,      CP_yield,       cpIsChiped,     chip_yield,         cpIsBatched,      batch_yield,     userName,    current_time,  note
void UIDemo01::alterMaterial_slot(QString cpTestNum,QString cpTestSpecification,QString cpInvestment,QString processDemand,QString cpOutput,QString CP_yield,QString cpIsChiped,QString chip_yield,QString cpIsBatched,QString batch_yield,QString userName,QString current_time,QString note)
{

    CP_test_numItem[currentClickIndex].setText(cpTestNum);
    CP_test_specificationItem[currentClickIndex].setText(cpTestSpecification);
    CP_investmentItem[currentClickIndex].setText(cpInvestment);
    CP_process_demandItem[currentClickIndex].setText(processDemand);
    CP_outputItem[currentClickIndex].setText(cpOutput);
    CP_yieldItem[currentClickIndex].setText(CP_yield);
    CP_isChipedItem[currentClickIndex].setText(cpIsChiped);
    CP_chip_yieldItem[currentClickIndex].setText(chip_yield);
    CP_isBatchedItem[currentClickIndex].setText(cpIsBatched);
    CP_batch_yieldItem[currentClickIndex].setText(batch_yield);
    CP_operatorItem[currentClickIndex].setText(userName);
    CP_updateTimeItem[currentClickIndex].setText(current_time);
    CP_noteItem[currentClickIndex].setText(note);

}


//!
//! \brief UIDemo01::delMaterial_slot
//!
void UIDemo01::delMaterial_slot()
{
    CP_waferNumItem[currentClickIndex].setText("-");
    CP_productModelItem[currentClickIndex].setText("-");
    CP_test_numItem[currentClickIndex].setText("-");
    CP_chipNumItem[currentClickIndex].setText("-");
    CP_test_specificationItem[currentClickIndex].setText("-");
    CP_investmentItem[currentClickIndex].setText("-");
    CP_process_demandItem[currentClickIndex].setText("-");
    CP_outputItem[currentClickIndex].setText("-");
    CP_yieldItem[currentClickIndex].setText("-");
    CP_isChipedItem[currentClickIndex].setText("-");
    CP_chip_yieldItem[currentClickIndex].setText("-");
    CP_isBatchedItem[currentClickIndex].setText("-");
    CP_batch_yieldItem[currentClickIndex].setText("-");
    CP_operatorItem[currentClickIndex].setText("-");
    CP_updateTimeItem[currentClickIndex].setText("-");
    CP_noteItem[currentClickIndex].setText("-");
}




//入库 按钮
void UIDemo01::on_inBound_pushButton_clicked()
{
//    QString userType = userTypeItem[currentClickIndex].text();
//    QString materialName = materialNameItem[currentClickIndex].text();
//    QString materialModel = materialModelItem[currentClickIndex].text();
//    QString factoryStr = factoryItem[currentClickIndex].text();
//    float singlePrice = singlePriceItem[currentClickIndex].text().toFloat();
//    int materialNumber = numberItem[currentClickIndex].text().toInt();

//    if(materialName.isEmpty())
//    {
//        QMessageBox::information(NULL,"提示","请先选中要入库的物资");
//        return;
//    }

//    //initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);
//    inBound_dia.initMaterialInfo( userType,materialName,materialModel,factoryStr,singlePrice,materialNumber,UserName);
//    inBound_dia.show();
}


void UIDemo01::inBoundNum_Slot(int resNum,float all_price)
{
//    numberItem[currentClickIndex].setText(QString::number(resNum));
//    allPriceItem[currentClickIndex].setText(QString::number(all_price));
}



//出库  按钮
void UIDemo01::on_outBound_pushButton_clicked()
{
//    QString userType = userTypeItem[currentClickIndex].text();
//    QString materialName = materialNameItem[currentClickIndex].text();
//    QString materialModel = materialModelItem[currentClickIndex].text();
//    QString factoryStr = factoryItem[currentClickIndex].text();
//    float singlePrice = singlePriceItem[currentClickIndex].text().toFloat();
//    int materialNumber = numberItem[currentClickIndex].text().toInt();

//    if(materialName.isEmpty())
//    {
//        QMessageBox::information(NULL,"提示","请先选中要出库的物资");
//        return;
//    }

//    //initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);
//    outBound_dia.initMaterialInfo( userType,materialName,materialModel,factoryStr,singlePrice,materialNumber,UserName);

//    outBound_dia.show();
}


/**************************入库查询相关的槽函数**********************************************************/

void UIDemo01::on_inBoundQuery_pushButton_clicked()
{
    inBoundQuery_dia.initSelect();
    inBoundQuery_dia.show();
}


//接收入库查询后的 SQL 语句
void UIDemo01::inBoundSQLResult_slot(QStringList sqlList)
{
    //    qDebug()<<" sqlList = "<<sqlList<<endl;

    inBound_DataList.clear();  //每次查询都清空已有的数据
    QString sqlStr;

    for(int i=0; i<sqlList.length(); i++)
    {
        sqlStr = sqlList[i];
        bool buscess =  sql_query.exec(sqlStr);
        if(!buscess)
        {
            qDebug()<<" select  UIDemo01::inBoundSQLResult_slot(QStringList sqlList) error !!"<<endl;
            return;
        }
        while(sql_query.next())
        {
            for(int k=1 ;k<11; k++)
            {
                inBound_DataList.append(sql_query.value(k).toString());
            }

        }
    }

    qDebug()<<" allDataList=" <<inBound_DataList.length()/10<<endl;    //总的记录数为=length/8;
    int allNotes = inBound_DataList.length()/10;

    QString str = "总记录数：" + QString::number(allNotes);    //显示记录数
    inBound_label->setText(str);


    int maxPage ;
    maxPage = allNotes/onePageNotesNum ;
    if(0 != allNotes%onePageNotesNum )
    {
        maxPage = maxPage + 1;
    }

    //    emit setMaxPage_signal(maxPage);
    emit setInBoundPage_signal(maxPage);
    showinBound_SpecifiedPage(1);


}


//一页显示的条目数量  初始化为50
void UIDemo01::showinBound_SpecifiedPage(int pageNum)
{
    inBound_PageWidget->setLineEdit(pageNum);
    //先清空CP_tableWidget上的显示
    for(int i=0; i<onePageNotesNum; i++)
    {
        inBound_userTypeItem[i].setText("");
        inBound_materialNameItem[i].setText("");
        inBound_materialModelItem[i].setText("");
        inBound_factoryItem[i].setText("");
        inBound_numberItem[i].setText("");
        inBound_singlePriceItem[i].setText("");
        inBound_allPriceItem[i].setText("");
        inBound_operatiorItem[i].setText("");
        inBound_operaTimeItem[i].setText("");
        inBound_noteItem[i].setText("");
    }

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = inBound_DataList.length()/10;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"here beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {
        inBound_userTypeItem[index].setText(inBound_DataList[i*10+0]);
        inBound_materialNameItem[index].setText(inBound_DataList[i*10+1]);
        inBound_materialModelItem[index].setText(inBound_DataList[i*10+2]);
        inBound_factoryItem[index].setText(inBound_DataList[i*10+3]);
        inBound_numberItem[index].setText(inBound_DataList[i*10+4]);
        inBound_singlePriceItem[index].setText(inBound_DataList[i*10+5]);
        inBound_allPriceItem[index].setText(inBound_DataList[i*10+6]);
        inBound_operatiorItem[index].setText(inBound_DataList[i*10+7]);
        QString strTime = inBound_DataList[i*10+8];
        strTime.replace("T"," ");
        inBound_operaTimeItem[index].setText(strTime);
        inBound_noteItem[index].setText(inBound_DataList[i*10+9]);
        index++;
    }
}



/**************************出库查询相关的槽函数**********************************************************/

//弹出出库查询函数的窗口
void UIDemo01::on_outBoundQuery_pushButton_clicked()
{
    outBoundQuery_dia.initSelect();
    outBoundQuery_dia.show();
}

//接收入库查询后的 SQL 语句
void UIDemo01::outBoundSQLResult_slot(QStringList sqlList)
{
    qDebug()<<" sql = "<<sqlList<<endl;

    outBound_DataList.clear();  //每次查询都清空已有的数据
    QString sqlStr;

    for(int i=0; i<sqlList.length(); i++)
    {
        sqlStr = sqlList[i];
        bool buscess =  sql_query.exec(sqlStr);
        if(!buscess)
        {
            qDebug()<<" select UIDemo01::outBoundSQLResult_slot(QStringList sqlList) error !!"<<endl;
            return;
        }
        while(sql_query.next())
        {
            for(int k=1 ;k<12; k++)
            {
                outBound_DataList.append(sql_query.value(k).toString());
            }

        }
    }

    qDebug()<<" allDataList=" <<outBound_DataList.length()/11<<endl;    //总的记录数为=length/8;
    int allNotes = outBound_DataList.length()/11;

    QString str = "总记录数：" + QString::number(allNotes);    //显示记录数
    outBound_label->setText(str);


    int maxPage ;
    maxPage = allNotes/onePageNotesNum ;
    if(0 != allNotes%onePageNotesNum )
    {
        maxPage = maxPage + 1;
    }

    //    emit setMaxPage_signal(maxPage);
    emit setOutBoundPage_signal(maxPage);
    showoutBound_SpecifiedPage(1);

}


void UIDemo01::showoutBound_SpecifiedPage(int pageNum)
{
    outBound_PageWidget->setLineEdit(pageNum);
    //先清空CP_tableWidget上的显示
    for(int i=0; i<onePageNotesNum; i++)
    {
        outBound_userTypeItem[i].setText("");
        outBound_materialNameItem[i].setText("");
        outBound_materialModelItem[i].setText("");
        outBound_factoryItem[i].setText("");
        outBound_numberItem[i].setText("");
        outBound_singlePriceItem[i].setText("");
        outBound_allPriceItem[i].setText("");
        outBound_operatiorItem[i].setText("");
        outBound_RecipientItem[i].setText("");
        outBound_operaTimeItem[i].setText("");
        outBound_noteItem[i].setText("");
    }

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = outBound_DataList.length()/11;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"here beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {
        qDebug()<<"i = "<<i<<endl;

        outBound_userTypeItem[index].setText(outBound_DataList[i*11+0]);
        outBound_materialNameItem[index].setText(outBound_DataList[i*11+1]);
        outBound_materialModelItem[index].setText(outBound_DataList[i*11+2]);
        outBound_factoryItem[index].setText(outBound_DataList[i*11+3]);
        outBound_numberItem[index].setText(outBound_DataList[i*11+4]);
        outBound_singlePriceItem[index].setText(outBound_DataList[i*11+5]);
        outBound_allPriceItem[index].setText(outBound_DataList[i*11+6]);
        outBound_operatiorItem[index].setText(outBound_DataList[i*11+7]);
        outBound_RecipientItem[index].setText(outBound_DataList[i*11+8]);
        QString strTime = outBound_DataList[i*11+9];
        strTime.replace("T"," ");
        outBound_operaTimeItem[index].setText(strTime);
        outBound_noteItem[index].setText(outBound_DataList[i*11+10]);
        index++;
    }
}



/****************用户管理相关的槽函数******************************************/
void UIDemo01::initUserTableWidget()
{
    QString sqlStr ="SELECT * FROM USER_TABLE ;";
    bool buscess =  sql_query.exec(sqlStr);
    currentIndex = 0;
    while(sql_query.next())
    {
        userNameItem[currentIndex].setText(sql_query.value(1).toString());
        userPassWord_lineEdit[currentIndex].setText(sql_query.value(2).toString());
        authorityItem[currentIndex].setText(sql_query.value(3).toString());
        userNoteItem[currentIndex].setText(sql_query.value(4).toString());
        currentIndex++;
    }
}

//新增用户 弹出界面
void UIDemo01::on_addUser_pushButton_clicked()
{
    addUserDia.show();
}


//修改用户 弹出界面
void UIDemo01::on_alterUser_pushButton_clicked()
{
    //首先获取选中的控件上的内容
    QString userName  = userNameItem[currentUserClickIndex].text();
    QString userPassWd = userPassWord_lineEdit[currentUserClickIndex].text();
    QString authorityStr = authorityItem[currentUserClickIndex].text();
    QString noteStr = userNoteItem[currentUserClickIndex].text();

    alterUserDia.initUserInfo(userName,userPassWd,authorityStr,noteStr);
    alterUserDia.show();

}

//删除用户
void UIDemo01::on_delUser_pushButton_clicked()
{
    QString userName = userNameItem[currentUserClickIndex].text();
    sql_query.prepare("DELETE FROM USER_TABLE WHERE USER_NAME=:USER_NAME;");
    sql_query.bindValue(":USER_NAME",userName);
    bool buscess = sql_query.exec();
    if(!buscess)
    {
        qDebug()<<QStringLiteral("删除用户失败");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("删除用户失败"));
        return;
    }

    userNameItem[currentUserClickIndex].setText("-");
    userPassWord_lineEdit[currentUserClickIndex].setText("");
    authorityItem[currentUserClickIndex].setText("-");
    userNoteItem[currentUserClickIndex].setText("-");

}


//在CP_tableWidget 上添加一行数据
void UIDemo01::addUserOneNoteSlot(QString userName,QString passWord,QString authority,QString note)
{
    userNameItem[currentIndex].setText(userName);
    userPassWord_lineEdit[currentIndex].setText(passWord);
    authorityItem[currentIndex].setText(authority);
    userNoteItem[currentIndex].setText(note);
    currentIndex++;
}

//选中某一行
void UIDemo01::on_user_tableWidget_clicked(const QModelIndex &index)
{
    currentUserClickIndex = index.row();
}

//修改后某一行 同步到主界面
void UIDemo01::alterUserOneNoteSlot(QString userName,QString userPassWd,QString authorityStr,QString noteStr)
{
    userNameItem[currentUserClickIndex].setText(userName);
    userPassWord_lineEdit[currentUserClickIndex].setText(userPassWd);
    authorityItem[currentUserClickIndex].setText(authorityStr);
    userNoteItem[currentUserClickIndex].setText(noteStr);
}



void UIDemo01::loginUserName_slot(QString userName,QString authority)
{
    QString strName= "当前用户：" + userName;
    this->UserName = userName;
    UserAuthority = authority;
    qDebug()<<strName<<"  权限："<<UserAuthority<<endl;
    ui->loginUser_label->setText(strName);


//    把登录用户 用户名 传递给 其他窗口
//      1、CP 添加窗口
    addMaterial_dia.setUserName(userName);
}



//物资管理界面的文件导出
void UIDemo01::on_CP_managerOutExcel_pushBotton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(ui->CP_tableWidget, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xlsx *.xls)");

    qDebug()<<" fileName = "<<fileName<<endl;

    if(fileName != "")
    {
        qDebug()<<"  excel has coming"<<endl;
        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application") )
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            int i,j;
            int colcount = ui->CP_tableWidget->columnCount();
            int rowcount = ui->CP_tableWidget->rowCount();

            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", "芯视界CP订单信息表");
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter

            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", ui->CP_tableWidget->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                //QCP_tableWidget 获取表格头部文字信息
                columnName=ui->CP_tableWidget->horizontalHeaderItem(i)->text();
                //QTableView 获取表格头部文字信息
                // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }


            //QCP_tableWidget 获取表格数据部分
            for(i=0;i<rowcount;i++){
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", ui->CP_tableWidget->item(i,j)?ui->CP_tableWidget->item(i,j)->text():"");
                }
            }

            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(ui->CP_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(ui->CP_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }

        }


    }else
    {
        QMessageBox::warning(NULL,"错误","未能创建 Excel 对象",QMessageBox::Apply);
    }

}



//!
//! \brief UIDemo01::on_PK_managerQuery_pushButton_2_clicked
//!PK 查询检索
void UIDemo01::on_PK_managerQuery_pushButton_2_clicked()
{
    pK_query_dia.setModal(true);
    pK_query_dia.isSelectFinished = false;
    pK_query_dia.initSelect();
    pK_query_dia.show();
}

//!
//! \brief UIDemo01::on_PK_addMaterial_pushButton_clicked
//! 添加PK的订单
void UIDemo01::on_PK_addMaterial_pushButton_clicked()
{
    addPk_dia.initSelect();
    addPk_dia.setModal(true);
    addPk_dia.setUserName(UserName);
    addPk_dia.show();
}

//!
//! \brief UIDemo01::on_PK_alterMaterial_pushButton_clicked
//!pK 修改
void UIDemo01::on_PK_alterMaterial_pushButton_clicked()
{

}

//!
//! \brief UIDemo01::on_PK_returnALL_pushButton_clicked
//! 返回总库
void UIDemo01::on_PK_returnALL_pushButton_clicked()
{

}

//!
//! \brief UIDemo01::on_PK_managerOutExcel_pushBotton_clicked
//!导出报表
void UIDemo01::on_PK_managerOutExcel_pushBotton_clicked()
{

}

//!
//! \brief UIDemo01::PK_selectResult_slot
//!查询 PK订单信息的槽函数
//! //!
//! \brief UIDemo01::selectResult_slot
//! \param sqlList
//!   1、将语句进行查询，然后把所有数据存储在 allDataList当中  ，它的长度应该为是 12的倍数,去除主键ID
//!   2、计算记录的条数
//!   3、最大的页数
//!   4、然后显示第一页
void UIDemo01::PK_selectResult_slot(QStringList sqlList)
{
    PK_allDataList.clear();  //每次查询都清空已有的数据
    qDebug()<<" the sql = "<<sqlList<<endl;
    QString sqlStr;

    for(int i=0; i<sqlList.length(); i++)
    {
        sqlStr = sqlList[i];
        bool buscess =  sql_query.exec(sqlStr);
        if(!buscess)
        {
            qDebug()<<" UIDemo01::PK_selectResult_slot(QStringList sqlList)  select error !!"<<endl;
            return;
        }
        while(sql_query.next())
        {
            for(int k=1 ;k<13; k++)
            {
                PK_allDataList.append(sql_query.value(k).toString());
            }
        }
    }


    int allNotes = PK_allDataList.length()/12;
    QString str = "总记录数：" + QString::number(allNotes);    //显示记录数
    PK_label->setText(str);


    int maxPage ;
    maxPage = allNotes/onePageNotesNum ;
    if(0 != allNotes%onePageNotesNum )
    {
        maxPage = maxPage + 1;
    }


    emit PK_setMaxPage_signal(maxPage);
    PK_showSpecifiedPage(1);
}


//!
//! \brief UIDemo01::PK_showSpecifiedPage
//! \param pageNum
//!分页相关，接收到控件传递来的指定页数，然后刷新显示
void UIDemo01::PK_showSpecifiedPage(int pageNum)
{
    PK_pageWidget->setLineEdit(pageNum);

    //先清空CP_tableWidget上的显示
    clear_tableWidgetItem();

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = PK_allDataList.length()/12;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {

        PK_waferNumItem[index].setText(PK_allDataList[i*12+0]);
        PK_cpTestItem[index].setText(PK_allDataList[i*12+1]);
        PK_numItem[index].setText(PK_allDataList[i*12+2]);
        PK_packageTypeItem[index].setText(PK_allDataList[i*12+3]);
        PK_package_specificationItem[index].setText(PK_allDataList[i*12+4]);
        PK_investmentItem[index].setText(PK_allDataList[i*12+5]);
        PK_process_demandItem[index].setText(PK_allDataList[i*12+6]);
        PK_outputItem[index].setText(PK_allDataList[i*12+7]);
        PK_yieldItem[index].setText(PK_allDataList[i*12+8]);
        PK_operatorItem[index].setText(PK_allDataList[i*12+9]);
        QString updateTimeStr = PK_allDataList[i*12+10];
        updateTimeStr = updateTimeStr.replace("T"," ");
        PK_updateTimeItem[index].setText(updateTimeStr);
        PK_noteItem[index].setText(PK_allDataList[i*12+11]);
        index++;
    }
}



//入库记录导出
void UIDemo01::on_inBoundOutExecel_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(ui->inBound_tableWidget, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xlsx *.xls)");

    qDebug()<<" fileName = "<<fileName<<endl;


    if(fileName != "")
    {
        qDebug()<<"  excel has coming"<<endl;
        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application") )
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            int i,j;
            int colcount = ui->inBound_tableWidget->columnCount();
            int rowcount = ui->inBound_tableWidget->rowCount();

            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", "芯视界物资入库记录表");
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter

            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", ui->inBound_tableWidget->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                //QCP_tableWidget 获取表格头部文字信息
                columnName = ui->inBound_tableWidget->horizontalHeaderItem(i)->text();
                //QTableView 获取表格头部文字信息
                // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }


            //QCP_tableWidget 获取表格数据部分
            for(i=0;i<rowcount;i++){
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", ui->inBound_tableWidget->item(i,j)?ui->inBound_tableWidget->item(i,j)->text():"");
                }
            }

            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(ui->inBound_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(ui->inBound_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }

        }


    }else
    {
        QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
    }
}

//出库记录导出
void UIDemo01::on_outBoundOutExcel_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(ui->outBound_tableWidget, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xlsx *.xls)");

    qDebug()<<" fileName = "<<fileName<<endl;

    if(fileName != "")
    {
        qDebug()<<"  excel has coming"<<endl;
        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application") )
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            int i,j;
            int colcount = ui->outBound_tableWidget->columnCount();
            int rowcount = ui->outBound_tableWidget->rowCount();

            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", "芯视界物资出库记录表");
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter

            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", ui->outBound_tableWidget->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                //QCP_tableWidget 获取表格头部文字信息
                columnName = ui->outBound_tableWidget->horizontalHeaderItem(i)->text();
                //QTableView 获取表格头部文字信息
                // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }


            //QCP_tableWidget 获取表格数据部分
            for(i=0;i<rowcount;i++){
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", ui->outBound_tableWidget->item(i,j)?ui->outBound_tableWidget->item(i,j)->text():"");
                }
            }

            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(ui->outBound_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(ui->outBound_tableWidget->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }

        }

    }else
    {
        QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
    }
}




