#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

MainWindow::~MainWindow()
{
    delete ui;
}
