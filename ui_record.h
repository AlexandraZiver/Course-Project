/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QGraphicsView *graphicsView;
    QPushButton *show_sql;
    QPushButton *show_json;
    QPushButton *back;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName("record");
        record->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        record->setWindowIcon(icon);
        graphicsView = new QGraphicsView(record);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/records.png);\n"
"background-repeat: no-repeat;"));
        show_sql = new QPushButton(record);
        show_sql->setObjectName("show_sql");
        show_sql->setGeometry(QRect(255, 175, 41, 24));
        show_sql->setStyleSheet(QString::fromUtf8("background-repeat: no-repeat;\n"
"border: 0;\n"
"font: 700 10pt \"Segoe UI\";"));
        show_json = new QPushButton(record);
        show_json->setObjectName("show_json");
        show_json->setGeometry(QRect(388, 175, 41, 24));
        show_json->setStyleSheet(QString::fromUtf8("background-repeat: no-repeat;\n"
"border: 0;\n"
"font: 700 10pt \"Segoe UI\";"));
        back = new QPushButton(record);
        back->setObjectName("back");
        back->setGeometry(QRect(30, 50, 71, 61));
        back->setStyleSheet(QString::fromUtf8("background-image: url(:/images/arrow-right.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;\n"
""));
        textEdit = new QTextEdit(record);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(230, 230, 81, 141));
        textEdit_2 = new QTextEdit(record);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(330, 230, 151, 141));
        pushButton = new QPushButton(record);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(518, 178, 41, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-repeat: no-repeat;\n"
"border: 0;\n"
"font: 700 10pt \"Segoe UI\";"));
        textEdit_3 = new QTextEdit(record);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(500, 230, 81, 141));

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QDialog *record)
    {
        record->setWindowTitle(QCoreApplication::translate("record", "Records", nullptr));
        show_sql->setText(QCoreApplication::translate("record", "  JSON", nullptr));
        show_json->setText(QCoreApplication::translate("record", "XML", nullptr));
        back->setText(QString());
        pushButton->setText(QCoreApplication::translate("record", "  JSON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
