/********************************************************************************
** Form generated from reading UI file 'rules.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULES_H
#define UI_RULES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_rules
{
public:
    QGraphicsView *graphicsView;
    QPushButton *play_game;

    void setupUi(QDialog *rules)
    {
        if (rules->objectName().isEmpty())
            rules->setObjectName("rules");
        rules->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        rules->setWindowIcon(icon);
        graphicsView = new QGraphicsView(rules);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/rules.png);\n"
"background-repeat: no-repeat;"));
        play_game = new QPushButton(rules);
        play_game->setObjectName("play_game");
        play_game->setGeometry(QRect(340, 390, 111, 51));
        play_game->setStyleSheet(QString::fromUtf8("background-clip: padding-box;\n"
"border: 0;"));

        retranslateUi(rules);

        QMetaObject::connectSlotsByName(rules);
    } // setupUi

    void retranslateUi(QDialog *rules)
    {
        rules->setWindowTitle(QCoreApplication::translate("rules", "Rules", nullptr));
        play_game->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rules: public Ui_rules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULES_H
