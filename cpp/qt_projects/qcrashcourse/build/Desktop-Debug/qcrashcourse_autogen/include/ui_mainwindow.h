/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lable_firstnum;
    QLabel *label_secondnum;
    QLineEdit *lineEdit_firstnum;
    QLineEdit *lineEdit_secondnum;
    QPushButton *plus_Button;
    QPushButton *minus_Button;
    QPushButton *multi_Button;
    QPushButton *divide_Button;
    QLabel *label_result;
    QLineEdit *lineEdit_result;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(651, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lable_firstnum = new QLabel(centralwidget);
        lable_firstnum->setObjectName("lable_firstnum");
        lable_firstnum->setGeometry(QRect(170, 150, 161, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font.setPointSize(12);
        lable_firstnum->setFont(font);
        label_secondnum = new QLabel(centralwidget);
        label_secondnum->setObjectName("label_secondnum");
        label_secondnum->setGeometry(QRect(170, 190, 131, 31));
        label_secondnum->setFont(font);
        lineEdit_firstnum = new QLineEdit(centralwidget);
        lineEdit_firstnum->setObjectName("lineEdit_firstnum");
        lineEdit_firstnum->setGeometry(QRect(340, 150, 113, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font1.setPointSize(16);
        lineEdit_firstnum->setFont(font1);
        lineEdit_secondnum = new QLineEdit(centralwidget);
        lineEdit_secondnum->setObjectName("lineEdit_secondnum");
        lineEdit_secondnum->setGeometry(QRect(340, 190, 113, 24));
        lineEdit_secondnum->setFont(font1);
        plus_Button = new QPushButton(centralwidget);
        plus_Button->setObjectName("plus_Button");
        plus_Button->setGeometry(QRect(170, 240, 80, 24));
        plus_Button->setFont(font1);
        minus_Button = new QPushButton(centralwidget);
        minus_Button->setObjectName("minus_Button");
        minus_Button->setGeometry(QRect(170, 280, 80, 24));
        minus_Button->setFont(font1);
        multi_Button = new QPushButton(centralwidget);
        multi_Button->setObjectName("multi_Button");
        multi_Button->setGeometry(QRect(340, 240, 80, 24));
        multi_Button->setFont(font1);
        divide_Button = new QPushButton(centralwidget);
        divide_Button->setObjectName("divide_Button");
        divide_Button->setGeometry(QRect(340, 280, 80, 24));
        divide_Button->setFont(font1);
        label_result = new QLabel(centralwidget);
        label_result->setObjectName("label_result");
        label_result->setGeometry(QRect(170, 330, 91, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font2.setPointSize(14);
        label_result->setFont(font2);
        lineEdit_result = new QLineEdit(centralwidget);
        lineEdit_result->setObjectName("lineEdit_result");
        lineEdit_result->setGeometry(QRect(340, 330, 113, 24));
        lineEdit_result->setFont(font1);
        lineEdit_result->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lable_firstnum->setText(QCoreApplication::translate("MainWindow", "First number", nullptr));
        label_secondnum->setText(QCoreApplication::translate("MainWindow", "Second number", nullptr));
        plus_Button->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minus_Button->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multi_Button->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divide_Button->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label_result->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        lineEdit_result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
