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

    //界面上添加分页控件
    pageWidget = new PageWidget();
    QWidget *tmpwidget = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(ui->widget);
    hLayout->addWidget(tmpwidget,3);
    hLayout->addWidget(pageWidget, 1);

    initSql();
    initConnect();


}


void UIDemo01::initConnect()
{
    connect(&managmentQuery_dia,SIGNAL(selectResult_signal(QStringList)),this,SLOT(selectResult_slot(QStringList)));
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

    if (name == "主界面") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "系统设置") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "警情查询") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "调试帮助") {
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
    qDebug()<<" the sql = "<<sqlList<<endl;
}
