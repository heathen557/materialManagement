#include "pk_alterdialog.h"
#include "ui_pk_alterdialog.h"

extern QSqlQuery sql_query;
PK_alterDialog::PK_alterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PK_alterDialog)
{
    ui->setupUi(this);
    ui->PK_num_lineEdit->setEnabled(false);
}

void PK_alterDialog::setUserName(QString name)
{
    userName = name;
}


PK_alterDialog::~PK_alterDialog()
{
    delete ui;
}

//!
//! \brief PK_alterDialog::initPK_info
//! \param pkNum
//! \param pkType
//! \param pkSpec
//! \param pkInvestion
//! \param processDemand
//! \param pkOutput
//! \param note
//!初始化信息
void PK_alterDialog::initPK_info(QString pkNum,QString pkType,QString pkSpec,QString pkInvestion,QString processDemand,QString pkOutput,QString note)
{
    ui->PK_num_lineEdit->setText(pkNum);
    ui->packageType_lineEdit->setText(pkType);
    ui->package_specification_lineEdit->setText(pkSpec);
    ui->package_investment_lineEdit->setText(pkInvestion);
    ui->process_demand_lineEdit_2->setText(processDemand);
    ui->package_output_lineEdit->setText(pkOutput);
    ui->note_lineEdit->setText(note);

}


//!
//! \brief PK_alterDialog::on_alter_pushButton_clicked
//! //确认修改
void PK_alterDialog::on_alter_pushButton_clicked()
{
    bool buscess;
    QString pkNum = ui->PK_num_lineEdit->text();
    QString pkType = ui->packageType_lineEdit->text();
    QString pkSpec = ui->package_specification_lineEdit->text();
    QString pkInvestion = ui->package_investment_lineEdit->text();
    QString processDemand = ui->process_demand_lineEdit_2->text();
    QString pkOutput = ui->package_output_lineEdit->text();
    QString package_yield;
    if(pkInvestion.toFloat()>0 && pkOutput.toFloat()>0)  //计算CP 的良率
    {
        float out_1 = pkOutput.toFloat();
        float in_1 = pkInvestion.toFloat();
        float cp_num = out_1/in_1;
        package_yield = QString::number(cp_num);
    }
    currentDateTime = QDateTime::currentDateTime();
    QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString note = ui->note_lineEdit->text();




    //数据库部分的修改,根据商品的名称
    sql_query.prepare("UPDATE PK_TABLE SET packageType =:packageType,package_specification=:package_specification,"
                      "package_investment=:package_investment,process_demand=:process_demand,package_output=:package_output,package_yield=:package_yield,"
                      "operator=:operator,updateTime=:updateTime,note=:note WHERE PK_num=:PK_num;");
    sql_query.bindValue(":packageType",pkType);
    sql_query.bindValue(":package_specification",pkSpec);
    sql_query.bindValue(":package_investment",pkInvestion);
    sql_query.bindValue(":process_demand",processDemand);
    sql_query.bindValue(":package_output",pkOutput);
    sql_query.bindValue(":package_yield",package_yield);
    sql_query.bindValue(":operator",userName);
    sql_query.bindValue(":updateTime",current_time);
    sql_query.bindValue(":note",note);
    sql_query.bindValue(":PK_num",pkNum);

    buscess = sql_query.exec();
    if (!buscess)
    {
        qDebug("alterMaterial_Dialog::on_alter_pushButton_clicked  update PC_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("修改失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit PK_alterSignal(pkNum,pkType,pkSpec,pkInvestion,processDemand,pkOutput,package_yield,userName,current_time,note);

    this->hide();

}


//!
//! \brief PK_alterDialog::on_delete_pushButton_clicked
//!删除订单
void PK_alterDialog::on_delete_pushButton_clicked()
{

}
