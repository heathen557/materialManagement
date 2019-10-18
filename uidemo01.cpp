#pragma execution_character_set("utf-8")

#include "uidemo01.h"
#include "ui_uidemo01.h"
#include "iconhelper.h"
#include<QHBoxLayout>

QSqlQuery sql_query;

UIDemo01::UIDemo01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo01)
{
    ui->setupUi(this);
    this->initForm();

    onePageNotesNum = 50;

    currentClickIndex = 0;

    //界面上添加分页控件
    pageWidget = new PageWidget();
    lable1 = new QLabel();
    lable1->setText("总记录数：0");


    QLabel *allLabel = new QLabel();
//    allLabel->setText("10");
//    allLabel->setAlignment(Qt::AlignLeft);

    QLabel *lable2 = new QLabel();
//    lable2->setText("当前页：5");

    QLabel *currentPageLabel = new QLabel();
//    currentPageLabel->setText("5");

    QLabel *tempLabel = new QLabel();

    QHBoxLayout *hLayout = new QHBoxLayout(ui->widget);
    hLayout->addWidget(lable1,2);
    hLayout->addWidget(allLabel,1);
    hLayout->addWidget(lable2,2);
    hLayout->addWidget(tempLabel,1);
    hLayout->addWidget(currentPageLabel,10);



    hLayout->addWidget(pageWidget,8);

    initSql();
    initConnect();
    initTableWidget();

    emit setMaxPage_signal(1);


}

//初始化TableWidget界面
void UIDemo01::initTableWidget()
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
}



void UIDemo01::initConnect()
{
    connect(&managmentQuery_dia,SIGNAL(selectResult_signal(QStringList)),this,SLOT(selectResult_slot(QStringList)));

    connect(pageWidget,SIGNAL(currentPageChanged(int)),this,SLOT(showSpecifiedPage(int)));     //插件页数变换的时候，发出信号，然后更新

    connect(this,SIGNAL(setMaxPage_signal(int)),pageWidget,SLOT(setMaxPage(int)));
}

//数据库初始化函数
void UIDemo01::initSql()
{
    //数据库连接部分
    QSqlDatabase db;
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
        qDebug() << "\t " << driver;
    qDebug() << "End";

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
      sqlStr = "create table USER_TABLE(ID int primary key AUTO_INCREMENT, USER_NAME varchar(20), PASSWORD varchar(20), PERMISSION int)  ";
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
      sqlStr = "create table INBOUND_TABLE(ID int primary key AUTO_INCREMENT, USE_TYPE varchar(20), MATERIAL_NAME varchar(20),MATERIAL_MODEL varchar(20),MANUFACTOR varchar(100),NUMBER int,SINGLE_PRICE float,ALL_PRICE float,OPERATION_USER varchar(20),OPERATION_TIME datetime ,NOTE varchar(300))";
      buscess = sqlQuery.exec(sqlStr);
      if (!buscess)
      {
          qDebug("create INBOUND_TABLE  error");
      }

      //3 存储物料的入库记录  OUTBOUND_TABLE；  字段：ID、用途、名称、型号、厂家、数量、单价、总价、操作人，操作日期、备注
      sqlStr = "create table OUTBOUND_TABLE(ID int primary key AUTO_INCREMENT, USE_TYPE varchar(20), MATERIAL_NAME varchar(20),MATERIAL_MODEL varchar(20),MANUFACTOR varchar(100),NUMBER int,SINGLE_PRICE float,ALL_PRICE float,OPERATION_USER varchar(20),OPERATION_TIME datetime ,NOTE varchar(300))";
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
    } else if (name == "入库查询") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "出库查询") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "用户管理") {
        ui->stackedWidget->setCurrentIndex(3);
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

    if(materialName.isEmpty())
    {
        QMessageBox::information(NULL,"提示","请先选中要操作的数据");
        return;
    }


    alterMaterial_dia.show();
}

//入库 按钮
void UIDemo01::on_inBound_pushButton_clicked()
{
    inBound_dia.show();
}

//出库  按钮
void UIDemo01::on_outBound_pushButton_clicked()
{
    outBound_dia.show();
}
