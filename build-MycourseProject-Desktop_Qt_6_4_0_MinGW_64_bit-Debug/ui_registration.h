/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLabel *label;
    QPushButton *reg;
    QLineEdit *lineEdit_PlayerName;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_passwordCheck;
    QLabel *label_2;
    QPushButton *back;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(617, 753);
        label = new QLabel(registration);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 731, 781));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/regg.png);\n"
"background-size:contain;\n"
"\n"
"background-repeat:no repeat;\n"
""));
        reg = new QPushButton(registration);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(240, 560, 151, 51));
        reg->setStyleSheet(QString::fromUtf8(" background-color: rgba( 225,225,225,.0);\n"
"border:none;\n"
"\n"
""));
        lineEdit_PlayerName = new QLineEdit(registration);
        lineEdit_PlayerName->setObjectName("lineEdit_PlayerName");
        lineEdit_PlayerName->setGeometry(QRect(130, 250, 361, 31));
        lineEdit_PlayerName->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        lineEdit_password = new QLineEdit(registration);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(130, 360, 361, 31));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        lineEdit_passwordCheck = new QLineEdit(registration);
        lineEdit_passwordCheck->setObjectName("lineEdit_passwordCheck");
        lineEdit_passwordCheck->setGeometry(QRect(130, 460, 371, 31));
        lineEdit_passwordCheck->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        label_2 = new QLabel(registration);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 61, 61));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/arrow-right.png);\n"
"background-repeat:no repeat;"));
        back = new QPushButton(registration);
        back->setObjectName("back");
        back->setGeometry(QRect(0, 20, 80, 61));
        back->setStyleSheet(QString::fromUtf8(" background-color: rgba( 225,225,225,.0);\n"
"border:none;\n"
"\n"
""));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Form", nullptr));
        label->setText(QString());
        reg->setText(QString());
        lineEdit_PlayerName->setText(QString());
        lineEdit_password->setText(QString());
        lineEdit_passwordCheck->setText(QString());
        label_2->setText(QString());
        back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
