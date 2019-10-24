#include "frmlogin.h"
#include "ui_frmlogin.h"

extern QSqlQuery sql_query;
frmLogin::frmLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmLogin)
{
    ui->setupUi(this);
    initForm();
    w = new UIDemo01;

    connect(this,SIGNAL(loginUserName_signal(QString,QString)),w,SLOT(loginUserName_slot(QString,QString)));
}


void frmLogin::initForm()
{
//    //加载用户信息链表到内存,当用户选择用户名和输入密码时,从内存中比较密码,速度极快.
    QString sqlStr = "SELECT * FROM USER_TABLE;";
    bool buscess =  sql_query.exec(sqlStr);
    while (sql_query.next())
    {
        ui->txtUserName->addItem(sql_query.value(1).toString());
        TempUserPwd<<sql_query.value(2).toString();
        TempUserType<<sql_query.value(3).toString();
    }

//    //对应显示软件标题和工程商信息.
//    ui->labTitle->setText(myApp::SoftTitle);
//    ui->labCompany->setText(QString(QTextCodec::codecForName("GB18030")->toUnicode("技术支持:%1")).arg(myApp::CompanyName));
//    ui->txtUserName->setCurrentIndex(ui->txtUserName->findText(myApp::LastLoginer));

    //2014-3-29增加软键盘处理
    ui->gboxSoftKey->setGeometry(30,76,261,61);
    ui->gboxSoftKey->setVisible(false);

    QList<QPushButton *> btn=ui->gboxSoftKey->findChildren<QPushButton *>();
    foreach (QPushButton *b, btn){
        connect(b,SIGNAL(clicked()),this,SLOT(buttonClick()));
    }
}

void frmLogin::buttonClick()
{
    QPushButton *btn=(QPushButton *)sender();
    QString objectName=btn->objectName();
    QString text=ui->txtUserPwd->text();

    if (objectName=="btnDelete"){
        if (text.length()>0){
            ui->txtUserPwd->setText(text.mid(0,text.length()-1));
        }
    }else if (objectName=="btnQ"){
        ui->txtUserPwd->setText(text+"Q");
    }else if (objectName=="btnW"){
        ui->txtUserPwd->setText(text+"W");
    }else if (objectName=="btnE"){
        ui->txtUserPwd->setText(text+"E");
    }else if (objectName=="btnR"){
        ui->txtUserPwd->setText(text+"R");
    }else if (objectName=="btnT"){
        ui->txtUserPwd->setText(text+"T");
    }else if (objectName=="btnY"){
        ui->txtUserPwd->setText(text+"Y");
    }else if (objectName=="btnU"){
        ui->txtUserPwd->setText(text+"U");
    }else if (objectName=="btnI"){
        ui->txtUserPwd->setText(text+"I");
    }else if (objectName=="btnO"){
        ui->txtUserPwd->setText(text+"O");
    }else if (objectName=="btnP"){
        ui->txtUserPwd->setText(text+"P");
    }else if (objectName=="btnA"){
        ui->txtUserPwd->setText(text+"A");
    }else if (objectName=="btnS"){
        ui->txtUserPwd->setText(text+"S");
    }else if (objectName=="btnD"){
        ui->txtUserPwd->setText(text+"D");
    }else if (objectName=="btnF"){
        ui->txtUserPwd->setText(text+"F");
    }else if (objectName=="btnG"){
        ui->txtUserPwd->setText(text+"G");
    }else if (objectName=="btnH"){
        ui->txtUserPwd->setText(text+"H");
    }else if (objectName=="btnJ"){
        ui->txtUserPwd->setText(text+"J");
    }else if (objectName=="btnK"){
        ui->txtUserPwd->setText(text+"K");
    }else if (objectName=="btnL"){
        ui->txtUserPwd->setText(text+"L");
    }else if (objectName=="btnZ"){
        ui->txtUserPwd->setText(text+"Z");
    }else if (objectName=="btnX"){
        ui->txtUserPwd->setText(text+"X");
    }else if (objectName=="btnC"){
        ui->txtUserPwd->setText(text+"C");
    }else if (objectName=="btnV"){
        ui->txtUserPwd->setText(text+"V");
    }else if (objectName=="btnB"){
        ui->txtUserPwd->setText(text+"B");
    }else if (objectName=="btnN"){
        ui->txtUserPwd->setText(text+"N");
    }else if (objectName=="btnM"){
        ui->txtUserPwd->setText(text+"M");
    }else if (objectName=="btn0"){
        ui->txtUserPwd->setText(text+"0");
    }else if (objectName=="btn1"){
        ui->txtUserPwd->setText(text+"1");
    }else if (objectName=="btn2"){
        ui->txtUserPwd->setText(text+"2");
    }else if (objectName=="btn3"){
        ui->txtUserPwd->setText(text+"3");
    }else if (objectName=="btn4"){
        ui->txtUserPwd->setText(text+"4");
    }else if (objectName=="btn5"){
        ui->txtUserPwd->setText(text+"5");
    }else if (objectName=="btn6"){
        ui->txtUserPwd->setText(text+"6");
    }else if (objectName=="btn7"){
        ui->txtUserPwd->setText(text+"7");
    }else if (objectName=="btn8"){
        ui->txtUserPwd->setText(text+"8");
    }else if (objectName=="btn9"){
        ui->txtUserPwd->setText(text+"9");
    }
}
void frmLogin::on_btnLogin_clicked() //用户按下登录按钮
{
    QString UserPwd=ui->txtUserPwd->text();
    if (UserPwd==""){
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("密码不能为空,请重新输入!"));
        ui->txtUserPwd->setFocus();
        return;
    }

    int index=ui->txtUserName->currentIndex();
    if (UserPwd.toUpper()== TempUserPwd[index].toUpper()){

        w->show();

        QString authority = TempUserType[index];
        emit loginUserName_signal(ui->txtUserName->currentText(),authority);

        accept();
//
    }else{
        QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("密码错误,请重新输入!"));
        ui->txtUserPwd->setFocus();
    }
}
void frmLogin::on_btnClose_clicked() //关闭界面
{
    this->close();
}

void frmLogin::on_btnKey_clicked()
{
    ui->gboxSoftKey->setVisible(!ui->gboxSoftKey->isVisible());
}

frmLogin::~frmLogin()
{
    delete ui;
}
