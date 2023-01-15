/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *Start_Game;
    QPushButton *Records;
    QPushButton *About;
    QPushButton *Exit;
    QPushButton *soundButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/gamemenu.png);\n"
"background-repeat: no-repeat;\n"
"\n"
""));
        Start_Game = new QPushButton(centralwidget);
        Start_Game->setObjectName("Start_Game");
        Start_Game->setGeometry(QRect(284, 103, 241, 91));
        Start_Game->setStyleSheet(QString::fromUtf8("background-clip: padding-box;\n"
"border: 0;"));
        Records = new QPushButton(centralwidget);
        Records->setObjectName("Records");
        Records->setGeometry(QRect(280, 210, 241, 91));
        Records->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0;\n"
"\n"
""));
        About = new QPushButton(centralwidget);
        About->setObjectName("About");
        About->setGeometry(QRect(280, 310, 241, 91));
        About->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0;"));
        Exit = new QPushButton(centralwidget);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(280, 410, 241, 91));
        Exit->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0;\n"
""));
        soundButton = new QPushButton(centralwidget);
        soundButton->setObjectName("soundButton");
        soundButton->setGeometry(QRect(600, 10, 81, 61));
        soundButton->setStyleSheet(QString::fromUtf8("background-image: url(:/images/volume.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Volleyball", nullptr));
        Start_Game->setText(QString());
        Records->setText(QString());
        About->setText(QString());
        Exit->setText(QString());
        soundButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
