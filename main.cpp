#include "uidemo01.h"
#include "appinit.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include<frmlogin.h>

QSqlQuery sql_query;
void initSQL()
{
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
          QMessageBox::information(NULL,"warn","can't link MySQSL dataBase");
          return;
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

//    //加载样式表
//    QFile file(":/qss/psblack.css");
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();
//    }







    //加载样式表
    QFile file(":/qss/psblack.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qDebug()<<paletteColor<<endl;
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
    a.setFont(QFont("Microsoft Yahei", 9));
    AppInit::Instance()->start();




    initSQL();

    frmLogin frmLogin11;
    frmLogin11.show();


    return a.exec();


//    UIDemo01 w;
//    w.show();
//    return a.exec();
}
