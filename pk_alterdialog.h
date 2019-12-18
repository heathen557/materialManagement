#ifndef PK_ALTERDIALOG_H
#define PK_ALTERDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include<QDebug>
#include<QDateTime>
#include<QMessageBox>

namespace Ui {
class PK_alterDialog;
}

class PK_alterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PK_alterDialog(QWidget *parent = 0);
    ~PK_alterDialog();

    QString userName;

    void setUserName(QString);

    void initPK_info(QString,QString,QString,QString,QString,QString,QString);

    QDateTime currentDateTime;

private slots:
    void on_alter_pushButton_clicked();

    void on_delete_pushButton_clicked();

private:
    Ui::PK_alterDialog *ui;

signals:
    void PK_alterSignal(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);


};

#endif // PK_ALTERDIALOG_H
