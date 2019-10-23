#include "adduser_dialog.h"
#include "ui_adduser_dialog.h"

extern QSqlQuery sql_query;
addUser_Dialog::addUser_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser_Dialog)
{
    ui->setupUi(this);
}

addUser_Dialog::~addUser_Dialog()
{
    delete ui;
}



//确定
void addUser_Dialog::on_ok_pushButton_clicked()
{
    QString userName = ui->userName_lineEdit->text();
    QString passWord = ui->passWord_lineEdit->text();
    QString passWord2 = ui->passWord2lineEdit->text();
    QString authority = ui->authority_comboBox->currentText();
    QString noteStr = ui->note_lineEdit->text();

    //首先判断用户名是否已经存在
    QString sqlStr = "SELECT COUNT(*) from USER_TABLE WHERE USER_NAME = '" + userName + "';";
    bool buscess = sql_query.exec(sqlStr);
    if(!buscess)
    {
        qDebug()<<"addUser_Dialog::on_ok_pushButton_clicked()   select error ";
        return;
    }
    sql_query.next();
    if(sql_query.value(0).toInt() > 0)//查到有数据的话 就说明存在相同的用户名
    {
        qDebug()<<QStringLiteral("用户名已经存在，请重新输入");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("用户名已经存在，请重新输入"));
        return;
    }



    //检测两次的密码是否一致
    if(passWord != passWord2)
    {
        qDebug()<<QStringLiteral("两次输入密码不一致，请重新输入");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("两次输入密码不一致，请重新输入"));
        ui->passWord2lineEdit->clear();
        ui->passWord_lineEdit->clear();
        return;
    }

    sql_query.prepare("INSERT INTO USER_TABLE(USER_NAME,PASSWORD,PERMISSION,NOTE) VALUES(:USER_NAME,:PASSWORD,:PERMISSION,:NOTE);");
    sql_query.bindValue(":USER_NAME",userName);
    sql_query.bindValue(":PASSWORD",passWord);
    sql_query.bindValue(":PERMISSION",authority);
    sql_query.bindValue(":NOTE",noteStr);
    buscess = sql_query.exec();
    if(!buscess)
    {
        qDebug()<<QStringLiteral("添加用户失败!");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("添加用户失败!"));
        return;
    }

    ui->userName_lineEdit->clear();
    ui->passWord_lineEdit->clear();
    ui->passWord2lineEdit->clear();
    ui->note_lineEdit->clear();

    emit addUserOneNoteSignal(userName,passWord,authority,noteStr);
    this->hide();

}

//取消
void addUser_Dialog::on_cancel_pushButton_clicked()
{

    ui->userName_lineEdit->clear();
    ui->passWord_lineEdit->clear();
    ui->passWord2lineEdit->clear();
    ui->note_lineEdit->clear();
    this->hide();
}
