/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
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

    void setupUi(QDialog *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName("record");
        record->resize(800, 600);
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
        show_json->setGeometry(QRect(385, 175, 41, 24));
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
        textEdit->setGeometry(QRect(360, 200, 104, 231));

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QDialog *record)
    {
        record->setWindowTitle(QCoreApplication::translate("record", "Dialog", nullptr));
        show_sql->setText(QCoreApplication::translate("record", "  SQL", nullptr));
        show_json->setText(QCoreApplication::translate("record", "  JSON", nullptr));
        back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
