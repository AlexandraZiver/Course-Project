/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_authorization
{
public:
    QPushButton *back;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *done;
    QLineEdit *lineEdit_2;
    QPushButton *reg;
    QPushButton *not_reg;

    void setupUi(QDialog *authorization)
    {
        if (authorization->objectName().isEmpty())
            authorization->setObjectName("authorization");
        authorization->resize(539, 695);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        authorization->setWindowIcon(icon);
        authorization->setStyleSheet(QString::fromUtf8(" background: rgba( 0,0,0,.0);"));
        back = new QPushButton(authorization);
        back->setObjectName("back");
        back->setGeometry(QRect(10, 10, 71, 61));
        back->setStyleSheet(QString::fromUtf8("background-image: url(:/images/arrow-right.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;\n"
""));
        label_2 = new QLabel(authorization);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1411, 1191));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/zyro1-image.png);\n"
"background-size: contain;\n"
"background-repeat: no-repeat;"));
        lineEdit = new QLineEdit(authorization);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 230, 281, 35));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        done = new QPushButton(authorization);
        done->setObjectName("done");
        done->setGeometry(QRect(190, 460, 171, 51));
        done->setStyleSheet(QString::fromUtf8(" background-color: rgba( 225,225,225,.0);\n"
"border:none;\n"
"\n"
"\n"
""));
        lineEdit_2 = new QLineEdit(authorization);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 320, 291, 35));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;\n"
"border:none;"));
        reg = new QPushButton(authorization);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(110, 400, 111, 31));
        reg->setStyleSheet(QString::fromUtf8(" background-color: rgba( 225,225,225,.0);\n"
"border:none;\n"
""));
        not_reg = new QPushButton(authorization);
        not_reg->setObjectName("not_reg");
        not_reg->setGeometry(QRect(240, 400, 181, 31));
        not_reg->setStyleSheet(QString::fromUtf8(" background-color: rgba( 225,225,225,.0);\n"
"border:none;\n"
""));
        label_2->raise();
        back->raise();
        done->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        reg->raise();
        not_reg->raise();

        retranslateUi(authorization);

        QMetaObject::connectSlotsByName(authorization);
    } // setupUi

    void retranslateUi(QDialog *authorization)
    {
        authorization->setWindowTitle(QCoreApplication::translate("authorization", "Register", nullptr));
        back->setText(QString());
        label_2->setText(QString());
        done->setText(QString());
        reg->setText(QString());
        not_reg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class authorization: public Ui_authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
