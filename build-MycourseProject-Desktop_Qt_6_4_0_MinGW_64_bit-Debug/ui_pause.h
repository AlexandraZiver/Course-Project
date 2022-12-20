/********************************************************************************
** Form generated from reading UI file 'pause.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_H
#define UI_PAUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Pause
{
public:
    QPushButton *exitBtn;
    QPushButton *continueButton;
    QPushButton *menuBtn;

    void setupUi(QDialog *Pause)
    {
        if (Pause->objectName().isEmpty())
            Pause->setObjectName("Pause");
        Pause->resize(600, 779);
        Pause->setStyleSheet(QString::fromUtf8("background-image: url(:/images/pause1.png);\n"
";background-repeat: no-repeat;"));
        exitBtn = new QPushButton(Pause);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(220, 500, 161, 51));
        exitBtn->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        continueButton = new QPushButton(Pause);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(120, 260, 371, 51));
        continueButton->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));
        menuBtn = new QPushButton(Pause);
        menuBtn->setObjectName("menuBtn");
        menuBtn->setGeometry(QRect(119, 360, 371, 51));
        menuBtn->setStyleSheet(QString::fromUtf8("background: rgba( 0,0,0,.0);\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"font-size: 20px;\n"
"font-weiht:500;"));

        retranslateUi(Pause);

        QMetaObject::connectSlotsByName(Pause);
    } // setupUi

    void retranslateUi(QDialog *Pause)
    {
        Pause->setWindowTitle(QCoreApplication::translate("Pause", "Dialog", nullptr));
        exitBtn->setText(QString());
        continueButton->setText(QString());
        menuBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Pause: public Ui_Pause {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_H
