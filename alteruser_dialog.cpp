#include "alteruser_dialog.h"
#include "ui_alteruser_dialog.h"


extern QSqlQuery sql_query;
alteruser_Dialog::alteruser_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alteruser_Dialog)
{
    ui->setupUi(this);
}


void alteruser_Dialog::initUserInfo(QString userName,QString passWord,QString authority,QString noteStr)
{
//    ui->userName_lineEdit->setText(userName);
    ui->userName_label->setText(userName);
    ui->passWord_lineEdit->setText(passWord);
    ui->passWord2lineEdit->setText(passWord);
    ui->authority_comboBox->setCurrentText(authority);
    ui->note_lineEdit->setText(noteStr);
}

alteruser_Dialog::~alteruser_Dialog()
{
    delete ui;
}

void alteruser_Dialog::on_ok_pushButton_clicked()
{
    bool buscess;
    QString userName = ui->userName_label->text();
    QString passWord = ui->passWord_lineEdit->text();
    QString passWord2 = ui->passWord2lineEdit->text();
    QString authority = ui->authority_comboBox->currentText();
    QString noteStr = ui->note_lineEdit->text();

    //检测两次的密码是否一致
    if(passWord != passWord2)
    {
        qDebug()<<QStringLiteral("两次输入密码不一致，请重新输入");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("两次输入密码不一致，请重新输入"));
        ui->passWord2lineEdit->clear();
        ui->passWord_lineEdit->clear();
        return;
    }

    sql_query.prepare("UPDATE USER_TABLE SET USER_NAME = :USER_NAME,PASSWORD=:PASSWORD,PERMISSION=:PERMISSION,NOTE=:NOTE WHERE USER_NAME=:USER_NAME;");
    sql_query.bindValue(":USER_NAME",userName);
    sql_query.bindValue(":PASSWORD",passWord);
    sql_query.bindValue(":PERMISSION",authority);
    sql_query.bindValue(":NOTE",noteStr);
    buscess = sql_query.exec();
    if(!buscess)
    {
        qDebug()<<QStringLiteral("修改用户失败!");
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("修改用户失败!"));
        return;
    }

    ui->userName_label->clear();
    ui->passWord_lineEdit->clear();
    ui->passWord2lineEdit->clear();
    ui->note_lineEdit->clear();

    emit alterUserOneNoteSignal(userName,passWord,authority,noteStr);
    this->hide();
}

void alteruser_Dialog::on_cancel_pushButton_clicked()
{
    ui->userName_label->clear();
    ui->passWord_lineEdit->clear();
    ui->passWord2lineEdit->clear();
    ui->note_lineEdit->clear();

    this->hide();
}
