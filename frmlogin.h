#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QDialog>
#include <QSqlQuery>
#include<uidemo01.h>

namespace Ui {
class frmLogin;
}

class frmLogin : public QDialog
{
    Q_OBJECT

public:
    explicit frmLogin(QWidget *parent = 0);
    ~frmLogin();

private slots:
    void buttonClick();
    void on_btnLogin_clicked(); //用户按下登录按钮
    void on_btnClose_clicked(); //关闭界面

    void on_btnKey_clicked();

private:
    Ui::frmLogin *ui;

    UIDemo01 *w;
    QStringList TempUserPwd;    //密码链表
    QStringList TempUserType;   //类型链表

    void initForm();

signals:
    void loginUserName_signal(QString,QString);
};

#endif // FRMLOGIN_H
