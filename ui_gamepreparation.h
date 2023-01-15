/********************************************************************************
** Form generated from reading UI file 'gamepreparation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPREPARATION_H
#define UI_GAMEPREPARATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gamepreparation
{
public:
    QGraphicsView *graphicsView;
    QPushButton *start_game;
    QPushButton *back;
    QPushButton *plr1_rchange;
    QLabel *player1;
    QPushButton *plr1_lchange;
    QLabel *player2;
    QPushButton *plr2_lchange;
    QPushButton *plr2_rchange;
    QLineEdit *Gamer1;
    QLineEdit *Gamer2;
    QLabel *ball;
    QPushButton *ball_rchange;
    QPushButton *ball_lchange;
    QLineEdit *lineGetWeight;
    QLineEdit *location;
    QPushButton *placeChangeL;
    QPushButton *placeChangeR;
    QLabel *place;

    void setupUi(QDialog *gamepreparation)
    {
        if (gamepreparation->objectName().isEmpty())
            gamepreparation->setObjectName("gamepreparation");
        gamepreparation->resize(800, 600);
        gamepreparation->setMinimumSize(QSize(800, 600));
        gamepreparation->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        gamepreparation->setWindowIcon(icon);
        graphicsView = new QGraphicsView(gamepreparation);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 800, 600));
        graphicsView->setMinimumSize(QSize(800, 600));
        graphicsView->setMaximumSize(QSize(800, 600));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image:  url(:/images/gamefon.png);\n"
"background-repeat: no-repeat;\n"
"text-transform: uppercase; \n"
""));
        start_game = new QPushButton(gamepreparation);
        start_game->setObjectName("start_game");
        start_game->setGeometry(QRect(400, 20, 181, 251));
        start_game->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 0;"));
        back = new QPushButton(gamepreparation);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 20, 71, 61));
        back->setStyleSheet(QString::fromUtf8("background-image: url(:/images/arrow-right.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;\n"
""));
        plr1_rchange = new QPushButton(gamepreparation);
        plr1_rchange->setObjectName("plr1_rchange");
        plr1_rchange->setGeometry(QRect(160, 420, 30, 50));
        plr1_rchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image: url(:/images/arrow-r.png);background-repeat: no-repeat;"));
        player1 = new QLabel(gamepreparation);
        player1->setObjectName("player1");
        player1->setGeometry(QRect(70, 370, 71, 141));
        player1->setStyleSheet(QString::fromUtf8(""));
        player1->setPixmap(QPixmap(QString::fromUtf8("images/player3.png")));
        plr1_lchange = new QPushButton(gamepreparation);
        plr1_lchange->setObjectName("plr1_lchange");
        plr1_lchange->setGeometry(QRect(30, 420, 30, 50));
        plr1_lchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image:url(:/images/arrow-l.png);background-repeat: no-repeat;"));
        player2 = new QLabel(gamepreparation);
        player2->setObjectName("player2");
        player2->setGeometry(QRect(640, 370, 71, 151));
        player2->setPixmap(QPixmap(QString::fromUtf8("images/player4.png")));
        plr2_lchange = new QPushButton(gamepreparation);
        plr2_lchange->setObjectName("plr2_lchange");
        plr2_lchange->setGeometry(QRect(580, 410, 30, 50));
        plr2_lchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image:url(:/images/arrow-l.png);background-repeat: no-repeat;"));
        plr2_rchange = new QPushButton(gamepreparation);
        plr2_rchange->setObjectName("plr2_rchange");
        plr2_rchange->setGeometry(QRect(730, 410, 30, 50));
        plr2_rchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image: url(:/images/arrow-r.png);background-repeat: no-repeat;"));
        Gamer1 = new QLineEdit(gamepreparation);
        Gamer1->setObjectName("Gamer1");
        Gamer1->setEnabled(false);
        Gamer1->setGeometry(QRect(50, 520, 113, 22));
        Gamer1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"\n"
"border: 2px solid #fff; \n"
"color: #1e272e;\n"
"background-color: rgb(255, 176, 167);\n"
"\n"
"padding-left: 30px;\n"
"\n"
"border-radius:10%;\n"
""));
        Gamer2 = new QLineEdit(gamepreparation);
        Gamer2->setObjectName("Gamer2");
        Gamer2->setEnabled(false);
        Gamer2->setGeometry(QRect(620, 520, 113, 22));
        Gamer2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(253, 177, 167);\n"
"border: 2px solid #fff; \n"
"color: #1e272e;\n"
"background-color: rgb(255, 176, 167);\n"
"padding-left: 30px;\n"
"border-radius:10%;"));
        ball = new QLabel(gamepreparation);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(400, 270, 81, 101));
        ball->setStyleSheet(QString::fromUtf8(""));
        ball->setPixmap(QPixmap(QString::fromUtf8(":/images/ball.png")));
        ball_rchange = new QPushButton(gamepreparation);
        ball_rchange->setObjectName("ball_rchange");
        ball_rchange->setGeometry(QRect(480, 300, 30, 50));
        ball_rchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image: url(:/images/arrow-r.png);background-repeat: no-repeat;"));
        ball_lchange = new QPushButton(gamepreparation);
        ball_lchange->setObjectName("ball_lchange");
        ball_lchange->setGeometry(QRect(350, 300, 30, 50));
        ball_lchange->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image:url(:/images/arrow-l.png);background-repeat: no-repeat;"));
        lineGetWeight = new QLineEdit(gamepreparation);
        lineGetWeight->setObjectName("lineGetWeight");
        lineGetWeight->setGeometry(QRect(380, 360, 101, 24));
        lineGetWeight->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(233, 160, 157); \n"
"\n"
"background-color: #fff;\n"
"\n"
"\n"
"  opacity: 0.4;\n"
"border-radius:10%;"));
        location = new QLineEdit(gamepreparation);
        location->setObjectName("location");
        location->setEnabled(false);
        location->setGeometry(QRect(380, 550, 113, 22));
        location->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(253, 177, 167);\n"
"border: 2px solid #fff; \n"
"color: #1e272e;\n"
"background-color: rgb(255, 176, 167);\n"
"padding-left: 30px;\n"
"border-radius:10%;"));
        placeChangeL = new QPushButton(gamepreparation);
        placeChangeL->setObjectName("placeChangeL");
        placeChangeL->setGeometry(QRect(340, 460, 41, 61));
        placeChangeL->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image:url(:/images/arrow-l.png);\n"
"background-repeat: no-repeat;"));
        placeChangeR = new QPushButton(gamepreparation);
        placeChangeR->setObjectName("placeChangeR");
        placeChangeR->setGeometry(QRect(510, 460, 41, 51));
        placeChangeR->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-image:url(:/images/arrow-r.png);\n"
"background-repeat: no-repeat;"));
        place = new QLabel(gamepreparation);
        place->setObjectName("place");
        place->setGeometry(QRect(380, 440, 111, 101));
        place->setPixmap(QPixmap(QString::fromUtf8(":/images/ship33.png")));

        retranslateUi(gamepreparation);

        QMetaObject::connectSlotsByName(gamepreparation);
    } // setupUi

    void retranslateUi(QDialog *gamepreparation)
    {
        gamepreparation->setWindowTitle(QCoreApplication::translate("gamepreparation", "Start game", nullptr));
        start_game->setText(QString());
        back->setText(QString());
        plr1_rchange->setText(QString());
        player1->setText(QString());
        plr1_lchange->setText(QString());
        player2->setText(QString());
        plr2_lchange->setText(QString());
        plr2_rchange->setText(QString());
        Gamer1->setText(QCoreApplication::translate("gamepreparation", "\320\223\321\200\320\260\320\262\320\265\321\206\321\214 1", nullptr));
        Gamer2->setText(QCoreApplication::translate("gamepreparation", "\320\223\321\200\320\260\320\262\320\265\321\206\321\214 2", nullptr));
        ball->setText(QString());
        ball_rchange->setText(QString());
        ball_lchange->setText(QString());
        location->setText(QCoreApplication::translate("gamepreparation", "\320\233\320\276\320\272\320\260\321\206\321\226\321\217", nullptr));
        placeChangeL->setText(QString());
        placeChangeR->setText(QString());
        place->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gamepreparation: public Ui_gamepreparation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPREPARATION_H
