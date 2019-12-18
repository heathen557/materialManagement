#include "altermaterial_dialog.h"
#include "ui_altermaterial_dialog.h"


extern QSqlQuery sql_query;
alterMaterial_Dialog::alterMaterial_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterMaterial_Dialog)
{
    ui->setupUi(this);
}

alterMaterial_Dialog::~alterMaterial_Dialog()
{
    delete ui;
}

void alterMaterial_Dialog::setUserName(QString name)
{
    userName = name;
}


//waferNum,  productModel, CPtest_num, chipNum, CP_test_specification,CP_investment, process_demand, CP_output, isChiped, isBatched,  note
//!
//! \brief alterMaterial_Dialog::initMaterialInfo
//! \param waferNum_     不能编辑
//! \param productModel_ 不能编辑
//! \param CPtest_num_   不能编辑
//! \param chipNum_      不能编辑
//! \param CP_test_specification_
//! \param CP_investment_
//! \param process_demand_
//! \param CP_output_
//! \param isChiped_
//! \param isBatched_
//! \param note_
//!
void alterMaterial_Dialog::initMaterialInfo(QString waferNum_,QString productModel_,QString CPtest_num_,QString chipNum_,QString CP_test_specification_,QString CP_investment_,QString process_demand_,QString CP_output_,QString isChiped_,QString isBatched_,QString note_ )
{

    ui->waferNum_lineEdit->setText(waferNum_);
    ui->productModel_lineEdit->setText(productModel_);
    ui->CPtest_num_lineEdit->setText(CPtest_num_);
    ui->chipNum_lineEdit->setText(chipNum_);
    ui->CP_test_specification_lineEdit->setText(CP_test_specification_);
    ui->CP_investment_lineEdit->setText(CP_investment_);
    ui->process_demand_lineEdit->setText(process_demand_);
    ui->CP_output_lineEdit->setText(CP_output_);
    ui->isChiped_comboBox->setCurrentText(isChiped_);
    ui->isBatched_comboBox->setCurrentText(isBatched_);
    ui->note_lineEdit->setText(note_);

    ui->waferNum_lineEdit->setEnabled(false);
    ui->productModel_lineEdit->setEnabled(false);
    ui->CPtest_num_lineEdit->setEnabled(false);
     ui->chipNum_lineEdit->setEnabled(false);

}

//确认修改的槽函数
//!
//! \brief alterMaterial_Dialog::on_alter_pushButton_clicked
//!根据测试单号 作为对比筛选 来对整条数据进行操作
//! 1、同步更新 良率信息 存入到数据库中；
//! 2、同步到主界面进行 更新显示
void alterMaterial_Dialog::on_alter_pushButton_clicked()
{
    bool buscess;

    QString cpTestNum = ui->CPtest_num_lineEdit->text();
    QString cpTestSpecification = ui->CP_test_specification_lineEdit->text();
    QString cpInvestment = ui->CP_investment_lineEdit->text();
    QString processDemand = ui->process_demand_lineEdit->text();
    QString cpOutput = ui->CP_output_lineEdit->text();
    QString CP_yield;
    if(cpOutput.toInt()>0 && cpInvestment.toInt()>0)  //计算CP 的良率
    {
        float out_1 = cpOutput.toFloat();
        float in_1 = cpInvestment.toFloat();
        float cp_num = out_1/in_1;
        CP_yield = QString::number(cp_num);
    }
    QString cpIsChiped = ui->isChiped_comboBox->currentText();
    QString cpIsBatched =ui->isBatched_comboBox->currentText();
    currentDateTime = QDateTime::currentDateTime();
    QString current_time = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    QString note = ui->note_lineEdit->text();

    //判断结片  结批，计算结片率 结批率
    //////////////////////
    QString chip_yield;
    QString batch_yield;
    //////////////////////


    //数据库部分的修改,根据商品的名称
    sql_query.prepare("UPDATE CP_TABLE SET CP_test_specification =:CPTESTSPECIFICATION,CP_investment=:CP_investment,"
                      "process_demand=:process_demand,CP_output=:CP_output,CP_yield=:CP_yield,isChiped=:isChiped,"
                      "chip_yield=:chip_yield,isBatched=:isBatched,batch_yield=:batch_yield,"
                      "operator=:operator,updateTime=:updateTime,note=:note WHERE CPtest_num=:CPtest_num;");
    sql_query.bindValue(":CPTESTSPECIFICATION",cpTestSpecification);
    sql_query.bindValue(":CP_investment",cpInvestment);
    sql_query.bindValue(":process_demand",processDemand);
    sql_query.bindValue(":CP_output",cpOutput);
    sql_query.bindValue(":CP_yield",CP_yield);
    sql_query.bindValue(":isChiped",cpIsChiped);
    sql_query.bindValue(":chip_yield",chip_yield);
    sql_query.bindValue(":isBatched",cpIsBatched);
    sql_query.bindValue(":batch_yield",batch_yield);
    sql_query.bindValue(":operator",userName);
    sql_query.bindValue(":updateTime",current_time);
    sql_query.bindValue(":note",note);
    sql_query.bindValue(":CPtest_num",cpTestNum);
    buscess = sql_query.exec();
    if (!buscess)
    {
        qDebug("alterMaterial_Dialog::on_alter_pushButton_clicked  update PC_TABLE error");
        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("修改失败"));
        return;
    }

    //主界面上同步进行信息的修改
    emit alterMaterial_signal(cpTestNum,cpTestSpecification,cpInvestment,processDemand,cpOutput,CP_yield,
                              cpIsChiped,chip_yield,cpIsBatched,batch_yield,userName,current_time,note);

    this->hide();

    ui->waferNum_lineEdit->clear();
    ui->productModel_lineEdit->clear();
    ui->CPtest_num_lineEdit->clear();
    ui->chipNum_lineEdit->clear();
    ui->CP_test_specification_lineEdit->clear();
    ui->CP_investment_lineEdit->clear();
    ui->process_demand_lineEdit->clear();
    ui->CP_output_lineEdit->clear();
    ui->isChiped_comboBox->setCurrentIndex(0);
    ui->isBatched_comboBox->setCurrentIndex(0);
    ui->note_lineEdit->clear();

}


//删除槽函数
//!删除CP订单信息
//! 1、根据CPtestNum 字段进行删除
//! 2、删除前要判断 其他表中是否存在CP订单相关的信息
void alterMaterial_Dialog::on_delete_pushButton_clicked()
{
//    if(0 != materialNum)
//    {
//        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("存在库存,请出库后再执行删除"));
//        return;
//    }

//    bool buscess;
//    QString materialName = ui->materialName_label->text();

//    //数据库部分的修改，根据商品名称删除信息
//    sql_query.prepare("DELETE  FROM INVENTORY_TABLE WHERE MATERIAL_NAME=:MATERIAL_NAME;");
//    sql_query.bindValue(":MATERIAL_NAME",materialName);
//    buscess = sql_query.exec();

//    if (!buscess)
//    {
//        qDebug("on_delete_pushButton_clicked  update INVENTORY_TABLE error");
//        QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("修改失败"));
//        return;
//    }

//    //主界面上同步进行信息的修改
////    emit alterMaterial_signal("-","-","-","-","-",0,0);

//    this->hide();

//    ui->materialName_label->clear();
//    ui->userType_lineEdit->clear();
//    ui->materialModel_lineEdit->clear();
//    ui->factory_lineEdit->clear();
//    ui->note_lineEdit->clear();
//    ui->singlePrice_lineEdit->clear();

      QString cpTestNum = ui->CPtest_num_lineEdit->text();

      /*******判断其他表中时候存在改订单信息，若存在则不能删除*********/

      /****************/
      bool buscess;

      //数据库部分的修改，根据商品名称删除信息
      sql_query.prepare("DELETE  FROM CP_TABLE WHERE CPtest_num=:CPtest_num;");
      sql_query.bindValue(":CPtest_num",cpTestNum);
      buscess = sql_query.exec();

      if (!buscess)
      {
          qDebug("alterMaterial_Dialog::on_delete_pushButton_clicked()  del CP_TABLE error");
          QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("删除失败"));
          return;
      }

      //主界面上同步进行信息的修改
      emit delMaterial_signal();
      this->hide();


}
