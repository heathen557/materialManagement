/********************************************************************************
** Form generated from reading UI file 'uidemo01.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIDEMO01_H
#define UI_UIDEMO01_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIDemo01
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnMain;
    QToolButton *btnConfig;
    QToolButton *btnData;
    QToolButton *btnHelp;
    QToolButton *btnExit;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton;
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lab2;
    QWidget *page3;
    QVBoxLayout *verticalLayout_5;
    QLabel *lab3;
    QWidget *page4;
    QVBoxLayout *verticalLayout_4;
    QLabel *lab4;

    void setupUi(QDialog *UIDemo01)
    {
        if (UIDemo01->objectName().isEmpty())
            UIDemo01->setObjectName(QStringLiteral("UIDemo01"));
        UIDemo01->resize(1068, 700);
        UIDemo01->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(UIDemo01);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(UIDemo01);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnMain = new QToolButton(widgetTop);
        btnMain->setObjectName(QStringLiteral("btnMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMain->sizePolicy().hasHeightForWidth());
        btnMain->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMain->setIcon(icon);
        btnMain->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnMain);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QStringLiteral("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon1);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);

        btnData = new QToolButton(widgetTop);
        btnData->setObjectName(QStringLiteral("btnData"));
        sizePolicy1.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/main_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon2);
        btnData->setChecked(false);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnData);

        btnHelp = new QToolButton(widgetTop);
        btnHelp->setObjectName(QStringLiteral("btnHelp"));
        sizePolicy1.setHeightForWidth(btnHelp->sizePolicy().hasHeightForWidth());
        btnHelp->setSizePolicy(sizePolicy1);
        btnHelp->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/main_person.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon3);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnHelp);

        btnExit = new QToolButton(widgetTop);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        sizePolicy1.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy1);
        btnExit->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/main_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon4);
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExit);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        stackedWidget = new QStackedWidget(UIDemo01);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        gridLayout = new QGridLayout(page1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(918, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        toolButton = new QToolButton(page1);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(page1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        widget = new QWidget(page1);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(page1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(page1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_4->setStretch(0, 6);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 6);

        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 14);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        verticalLayout_3 = new QVBoxLayout(page2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lab2 = new QLabel(page2);
        lab2->setObjectName(QStringLiteral("lab2"));
        lab2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lab2);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        verticalLayout_5 = new QVBoxLayout(page3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lab3 = new QLabel(page3);
        lab3->setObjectName(QStringLiteral("lab3"));
        lab3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lab3);

        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QStringLiteral("page4"));
        verticalLayout_4 = new QVBoxLayout(page4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lab4 = new QLabel(page4);
        lab4->setObjectName(QStringLiteral("lab4"));
        lab4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lab4);

        stackedWidget->addWidget(page4);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(UIDemo01);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UIDemo01);
    } // setupUi

    void retranslateUi(QDialog *UIDemo01)
    {
        UIDemo01->setWindowTitle(QApplication::translate("UIDemo01", "Form", Q_NULLPTR));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnMain->setText(QApplication::translate("UIDemo01", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        btnConfig->setText(QApplication::translate("UIDemo01", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        btnData->setText(QApplication::translate("UIDemo01", "\347\211\251\346\226\231\346\237\245\350\257\242", Q_NULLPTR));
        btnHelp->setText(QApplication::translate("UIDemo01", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        btnExit->setText(QApplication::translate("UIDemo01", "\347\224\250\346\210\267\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("UIDemo01", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("UIDemo01", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        btnMenu_Max->setText(QString());
        toolButton->setText(QApplication::translate("UIDemo01", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UIDemo01", "\345\205\245\345\272\223", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UIDemo01", "\345\207\272\345\272\223", Q_NULLPTR));
        lab2->setText(QApplication::translate("UIDemo01", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        lab3->setText(QApplication::translate("UIDemo01", "\350\255\246\346\203\205\346\237\245\350\257\242", Q_NULLPTR));
        lab4->setText(QApplication::translate("UIDemo01", "\350\260\203\350\257\225\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIDemo01: public Ui_UIDemo01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIDEMO01_H
