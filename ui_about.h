/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QGraphicsView *graphicsView;
    QPushButton *back;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName("about");
        about->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        about->setWindowIcon(icon);
        graphicsView = new QGraphicsView(about);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/dev.png);\n"
"background-repeat: no-repeat;\n"
"\n"
""));
        back = new QPushButton(about);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 50, 71, 61));
        back->setStyleSheet(QString::fromUtf8("background-image: url(:/images/arrow-right.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;\n"
""));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "About", nullptr));
        back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
