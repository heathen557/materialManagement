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

    onePageNotesNum = 50;

    currentClickIndex = 0;
    currentUserClickIndex = 0;

    //界面上添加分页控件
    pageWidget = new PageWidget();
    lable1 = new QLabel();
    lable1->setText("总记录数：0");


    //物资管理页
    QLabel *allLabel = new QLabel();
    QLabel *lable2 = new QLabel();
    QLabel *currentPageLabel = new QLabel();
    QLabel *tempLabel = new QLabel();
    QLabel *tempLabel_1 = new QLabel();
    QHBoxLayout *hLayout = new QHBoxLayout(ui->widget);
    hLayout->addWidget(lable1,2);
    hLayout->addWidget(allLabel,1);
    hLayout->addWidget(lable2,2);
    hLayout->addWidget(tempLabel,1);
    hLayout->addWidget(currentPageLabel,10);
    hLayout->addWidget(pageWidget,8);

    //入库查询页
    inBound_PageWidget = new PageWidget();
    inBound_label = new QLabel();
    inBound_label->setText("总记录数：0");
    QHBoxLayout *inBoundLayout = new QHBoxLayout(ui->inBound_pagewidget);
    inBoundLayout->addWidget(inBound_label,2);
    inBoundLayout->addWidget(tempLabel,8);
    inBoundLayout->addWidget(inBound_PageWidget,8);

    //出库查询页
    outBound_PageWidget = new PageWidget();
    outBound_label = new QLabel();
    outBound_label->setText("总记录数：0");
    QHBoxLayout *outBoundLayout = new QHBoxLayout(ui->outBound_pagewidget);
    outBoundLayout->addWidget(outBound_label,2);
    outBoundLayout->addWidget(tempLabel_1,8);
    outBoundLayout->addWidget(outBound_PageWidget,8);


//    initSql();
    initConnect();
    initTableWidget();

    emit setMaxPage_signal(1);
    emit setInBoundPage_signal(1);
    emit setOutBoundPage_signal(1);



}

//初始化TableWidget界面
void UIDemo01::initTableWidget()
{
    //物资管理界面
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(onePageNotesNum);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}"); //设置表头背景色
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(50,50,50)}");


    for(int i=0;i<onePageNotesNum;i++)
    {
        ui->tableWidget->setItem(i,0,&userTypeItem[i]);
        ui->tableWidget->setItem(i,1,&materialNameItem[i]);
        ui->tableWidget->setItem(i,2,&materialModelItem[i]);
        ui->tableWidget->setItem(i,3,&factoryItem[i]);
        ui->tableWidget->setItem(i,4,&numberItem[i]);
        ui->tableWidget->setItem(i,5,&singlePriceItem[i]);
        ui->tableWidget->setItem(i,6,&allPriceItem[i]);
        ui->tableWidget->setItem(i,7,&noteItem[i]);


        userTypeItem[i].setTextAlignment(Qt::AlignCenter);
        materialNameItem[i].setTextAlignment(Qt::AlignCenter);
        materialModelItem[i].setTextAlignment(Qt::AlignCenter);
        factoryItem[i].setTextAlignment(Qt::AlignCenter);
        numberItem[i].setTextAlignment(Qt::AlignCenter);
        singlePriceItem[i].setTextAlignment(Qt::AlignCenter);
        allPriceItem[i].setTextAlignment(Qt::AlignCenter);
        noteItem[i].setTextAlignment(Qt::AlignCenter);
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

void UIDemo01::clearTableWidgetItem()
{
    currentClickIndex = 0;
    for(int i = 0 ; i<50; i++)
    {
        userTypeItem[i].setText("");
        materialNameItem[i].setText("");
        materialModelItem[i].setText("");
        factoryItem[i].setText("");
        numberItem[i].setText("");
        singlePriceItem[i].setText("");
        allPriceItem[i].setText("");
        noteItem[i].setText("");

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

    connect(pageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(showSpecifiedPage(int)));     //插件页数变换的时候，发出信号，然后更新

    connect(this,SIGNAL(setMaxPage_signal(int)),pageWidget,SLOT(setMaxPage(int)));

    connect(&alterMaterial_dia,SIGNAL(alterMaterial_signal(QString,QString,QString,QString,QString,float,float)),this,SLOT(alterMaterial_slot(QString,QString,QString,QString,QString,float,float)));  //修改物料信息后 同步到主界面的显示界面

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

    if (name == "物料管理") {
        ui->stackedWidget->setCurrentIndex(0);
        clearTableWidgetItem();
    } else if (name == "入库查询") {
        ui->stackedWidget->setCurrentIndex(1);
        clearTableWidgetItem();
    } else if (name == "出库查询") {
        ui->stackedWidget->setCurrentIndex(2);
        clearTableWidgetItem();
    } else if (name == "用户管理") {
        if(UserAuthority != "管理员")
        {
            QMessageBox::information(NULL,"提示","您没有权限");
            return;
        }


        ui->stackedWidget->setCurrentIndex(3);
        clearTableWidgetItem();
        initUserTableWidget();
    } else if (name == "用户退出") {
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
void UIDemo01::on_addMaterial_pushButton_clicked()
{
    addMaterial_dia.show();
}

//物料管理的查询按钮
void UIDemo01::on_managerQuery_pushButton_clicked()
{
    //先初始化 查询相关的控件上的数据
    managmentQuery_dia.initSelect();

    managmentQuery_dia.show();
}

//物料查询结果接收的槽函数
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
            for(int k=1 ;k<9; k++)
            {
                allDataList.append(sql_query.value(k).toString());
            }

        }
    }

    qDebug()<<" allDataList=" <<allDataList.length()/8<<endl;    //总的记录数为=length/8;
    int allNotes = allDataList.length()/8;

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
    pageWidget->setLineEdit(pageNum);

    //先清空tableWidget上的显示
    for(int i=0; i<onePageNotesNum; i++)
    {
        userTypeItem[i].setText("");
        materialNameItem[i].setText("");
        materialModelItem[i].setText("");
        factoryItem[i].setText("");
        numberItem[i].setText("");
        singlePriceItem[i].setText("");
        allPriceItem[i].setText("");
        noteItem[i].setText("");
    }

    //第一条的记录序号为  (page-1)*onePageNotesNum;
    //最后一条的记录序号为 page*onePageNotesNum - 1;  要对比和总条数的大小，选最小的那个
    int beginNum = (pageNum-1) * onePageNotesNum;

    int last =  pageNum*onePageNotesNum -1;
    int allNoteNum = allDataList.length()/8;
    int lastNum = last<allNoteNum ? last+1:allNoteNum;   //选取最小的

    qDebug()<<"beginNum="<<beginNum<<"  lastNum="<<lastNum<<endl;

    int index = 0;
    for(int i=beginNum; i<lastNum; i++)     //i为记录的序号
    {
        userTypeItem[index].setText( allDataList[i*8+0]);
        materialNameItem[index].setText( allDataList[i*8+1]);
        materialModelItem[index].setText( allDataList[i*8+2]);
        factoryItem[index].setText(allDataList[i*8+3]);
        numberItem[index].setText(allDataList[i*8+4]);
        singlePriceItem[index].setText(allDataList[i*8+5]);
        allPriceItem[index].setText(allDataList[i*8+6]);
        noteItem[index].setText(allDataList[i*8+7]);
        index++;
    }
}


//返回总库
void UIDemo01::on_returnALL_pushButton_clicked()
{
    QString str = "SELECT * FROM inventory_table; ";
    QStringList strList ;
    strList.append(str);
    selectResult_slot(strList);

}


//单击QModelIndex的槽响应函数
void UIDemo01::on_tableWidget_clicked(const QModelIndex &index)
{
    qDebug()<<" clicked ="<< index.row()<<endl;
    currentClickIndex = index.row();
}


//修改物料 按钮
void UIDemo01::on_alterMaterial_pushButton_clicked()
{
    QString userType = userTypeItem[currentClickIndex].text();
    QString materialName = materialNameItem[currentClickIndex].text();
    QString materialModel = materialModelItem[currentClickIndex].text();
    QString factoryStr = factoryItem[currentClickIndex].text();
    QString singlePrice = singlePriceItem[currentClickIndex].text();
    int materialNumber = numberItem[currentClickIndex].text().toInt();

    if(materialName.isEmpty())
    {
        QMessageBox::information(NULL,"提示","请先选中要操作的数据");
        return;
    }

    alterMaterial_dia.initMaterialInfo(materialName,userType,materialModel,factoryStr,singlePrice,materialNumber);
    alterMaterial_dia.show();
}


//接收修改界面后的信息的槽函数
 //emit alterMaterial_signal(userType,materialName,materialModel,factoryName,noteStr,singlePrice,allPrice);
void UIDemo01::alterMaterial_slot(QString userType,QString materialName,QString materialModel,QString factoryName,QString noteStr,float singlePrice,float allPrice)
{
    userTypeItem[currentClickIndex].setText(userType);
    materialNameItem[currentClickIndex].setText(materialName);
    materialModelItem[currentClickIndex].setText(materialModel);
    factoryItem[currentClickIndex].setText(factoryName);
    singlePriceItem[currentClickIndex].setText(QString::number(singlePrice));
    allPriceItem[currentClickIndex].setText(QString::number(allPrice));
    noteItem[currentClickIndex].setText(noteStr);

}





//入库 按钮
void UIDemo01::on_inBound_pushButton_clicked()
{
    QString userType = userTypeItem[currentClickIndex].text();
    QString materialName = materialNameItem[currentClickIndex].text();
    QString materialModel = materialModelItem[currentClickIndex].text();
    QString factoryStr = factoryItem[currentClickIndex].text();
    float singlePrice = singlePriceItem[currentClickIndex].text().toFloat();
    int materialNumber = numberItem[currentClickIndex].text().toInt();

    if(materialName.isEmpty())
    {
        QMessageBox::information(NULL,"提示","请先选中要入库的物资");
        return;
    }

    //initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);
    inBound_dia.initMaterialInfo( userType,materialName,materialModel,factoryStr,singlePrice,materialNumber,UserName);
    inBound_dia.show();
}


void UIDemo01::inBoundNum_Slot(int resNum,float all_price)
{
    numberItem[currentClickIndex].setText(QString::number(resNum));
    allPriceItem[currentClickIndex].setText(QString::number(all_price));
}



//出库  按钮
void UIDemo01::on_outBound_pushButton_clicked()
{
    QString userType = userTypeItem[currentClickIndex].text();
    QString materialName = materialNameItem[currentClickIndex].text();
    QString materialModel = materialModelItem[currentClickIndex].text();
    QString factoryStr = factoryItem[currentClickIndex].text();
    float singlePrice = singlePriceItem[currentClickIndex].text().toFloat();
    int materialNumber = numberItem[currentClickIndex].text().toInt();

    if(materialName.isEmpty())
    {
        QMessageBox::information(NULL,"提示","请先选中要出库的物资");
        return;
    }

    //initMaterialInfo(QString user_Type,QString material_Name,QString material_Model,QString manu_Factory, float Price,int currentNum);
    outBound_dia.initMaterialInfo( userType,materialName,materialModel,factoryStr,singlePrice,materialNumber,UserName);

    outBound_dia.show();
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
    //先清空tableWidget上的显示
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
    //先清空tableWidget上的显示
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


//在TableWidget 上添加一行数据
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
}



//物资管理界面的文件导出
void UIDemo01::on_managerOutExcel_pushBotton_clicked()
{

}


//入库记录导出
void UIDemo01::on_inBoundOutExecel_pushButton_clicked()
{

}

//出库记录导出
void UIDemo01::on_outBoundOutExcel_pushButton_clicked()
{

}
