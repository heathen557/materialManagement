﻿#pragma execution_character_set("utf-8")

#include "uidemo01.h"
#include "ui_uidemo01.h"
#include "iconhelper.h"
#include<QHBoxLayout>

UIDemo01::UIDemo01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo01)
{
    ui->setupUi(this);
    this->initForm();

    pageWidget = new PageWidget();

    QWidget *tmpwidget = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(ui->widget);
    hLayout->addWidget(tmpwidget,3);
    hLayout->addWidget(pageWidget, 1);






    QSqlDatabase db;
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
        qDebug() << "\t " << driver;
    qDebug() << "End";

//     db = QSqlDatabase::addDatabase("QMYSQL");


    if (QSqlDatabase::contains("test"))
      {

      }
      else
      {
          db = QSqlDatabase::addDatabase("QMYSQL");   //, "localhost@3306"
          db.setHostName("localhost");    //数据库主机名
          db.setDatabaseName("test");    //数据库名
          db.setUserName("root");        //数据库用户名
          db.setPassword("");        //数据库密码
      }

      bool bisOpenn = db.open();          //打开数据库连接
      qDebug()<<"bisOpenn="<<bisOpenn;

      if (db.open())
      {
          QMessageBox::warning(NULL, QStringLiteral("提示"), "open ok", QMessageBox::Yes);
      }
      else
      {
          QMessageBox::warning(NULL, QStringLiteral("提示"), "open failed", QMessageBox::Yes);
      }
      QSqlQuery sql_query(db);
//      bool buscess = sql_query.exec("create table person (ID int primary key, USE_TYPE varchar(20),NAME varchar(20), MODEL varchar(20),NUMBER int, MANUFACTOR varchar(100),PRICE float)");
//      sql_query.exec("insert into person values(01, 'A4', 'de'，'SR-400',5,'wer'，15.63)");
//      sql_query.exec("insert into person values(02, 'A3', 'pix'，'R-400',3,'sdf'，4.63)");


      bool buscess = sql_query.exec("create table person (ID int primary key, USE_TYPE varchar(20), NAME varchar(20),MODEL varchar(20),NUMBER int,MANUFACTOR varchar(100),PRICE float)");
      sql_query.exec("insert into person values(1, 'Danny', 'Young','Danny', 5,'Danny', 3.142)");
      sql_query.exec("insert into person values(2, 'A3333', 'pixng','R-400',3,'sdf',4.63)");
      sql_query.exec("insert into person values(3, 'Danny', 'Young','Danny', 5,'Danny', 3.142)");
      sql_query.exec("insert into person values(4, 'A3333', 'pixng','R-400',3,'sdf',4.63)");
      sql_query.exec("insert into person values(5, 'Danny', 'Young','Danny', 5,'Danny', 3.142)");
      sql_query.exec("insert into person values(6, 'A3333', 'pixng','R-400',3,'sdf',4.63)");


      if (!buscess)
      {

          qDebug("table is error");
      }
      else
      {
          qDebug("table is sucess");
      }

      QSqlQuery query;
      query.exec("select * from person");
      while (query.next())
      {
          qDebug() << query.value(0).toInt() << query.value(1).toString() << query.value(2).toString();
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

void UIDemo01::on_btnMenu_Min_clicked()
{
    showMinimized();
}

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

void UIDemo01::on_btnMenu_Close_clicked()
{
    close();
}
