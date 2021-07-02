/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    QListWidget *listWidget_2;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_SaveData;
    QPushButton *pushButton_loadData;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_addTool;
    QPushButton *pushButton_runFlow;
    QPushButton *pushButton_minusTool;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_OpenImageMat;
    QPushButton *pushButton_saveImageXml;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(932, 498);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(MainWindow);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(MainWindow);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        centralWidget = new QWidget(splitter);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(160, 100));
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        splitter->addWidget(centralWidget);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        listWidget_2 = new QListWidget(splitter_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setMinimumSize(QSize(30, 30));
        listWidget_2->setMaximumSize(QSize(9955, 16777215));
        listWidget_2->setStyleSheet(QString::fromUtf8(""));
        splitter_2->addWidget(listWidget_2);
        groupBox_4 = new QGroupBox(splitter_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(60, 60));
        pushButton_SaveData = new QPushButton(groupBox_4);
        pushButton_SaveData->setObjectName(QString::fromUtf8("pushButton_SaveData"));
        pushButton_SaveData->setGeometry(QRect(110, 70, 80, 20));
        pushButton_SaveData->setStyleSheet(QString::fromUtf8(""));
        pushButton_loadData = new QPushButton(groupBox_4);
        pushButton_loadData->setObjectName(QString::fromUtf8("pushButton_loadData"));
        pushButton_loadData->setGeometry(QRect(20, 70, 80, 20));
        splitter_2->addWidget(groupBox_4);

        verticalLayout_2->addWidget(splitter_2);

        splitter->addWidget(groupBox_2);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 311, 281));
        listWidget->setMinimumSize(QSize(20, 30));
        listWidget->setMaximumSize(QSize(600, 16777215));
        listWidget->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 300, 221, 121));
        pushButton_addTool = new QPushButton(groupBox_3);
        pushButton_addTool->setObjectName(QString::fromUtf8("pushButton_addTool"));
        pushButton_addTool->setGeometry(QRect(10, 30, 41, 25));
        pushButton_runFlow = new QPushButton(groupBox_3);
        pushButton_runFlow->setObjectName(QString::fromUtf8("pushButton_runFlow"));
        pushButton_runFlow->setGeometry(QRect(120, 30, 80, 25));
        pushButton_minusTool = new QPushButton(groupBox_3);
        pushButton_minusTool->setObjectName(QString::fromUtf8("pushButton_minusTool"));
        pushButton_minusTool->setGeometry(QRect(60, 30, 41, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 211, 221));
        pushButton_OpenImageMat = new QPushButton(groupBox);
        pushButton_OpenImageMat->setObjectName(QString::fromUtf8("pushButton_OpenImageMat"));
        pushButton_OpenImageMat->setGeometry(QRect(30, 30, 131, 20));
        pushButton_saveImageXml = new QPushButton(groupBox);
        pushButton_saveImageXml->setObjectName(QString::fromUtf8("pushButton_saveImageXml"));
        pushButton_saveImageXml->setGeometry(QRect(40, 90, 141, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textBrowser = new QTextBrowser(tab_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(textBrowser);

        tabWidget->addTab(tab_3, QString());
        splitter->addWidget(tabWidget);

        horizontalLayout->addWidget(splitter);


        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "noName", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_SaveData->setText(QApplication::translate("MainWindow", "SaveData", nullptr));
        pushButton_loadData->setText(QApplication::translate("MainWindow", "loadData", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_addTool->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_runFlow->setText(QApplication::translate("MainWindow", "run", nullptr));
        pushButton_minusTool->setText(QApplication::translate("MainWindow", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_OpenImageMat->setText(QApplication::translate("MainWindow", "OpenImageMat", nullptr));
        pushButton_saveImageXml->setText(QApplication::translate("MainWindow", "saveImageXml", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
