/********************************************************************************
** Form generated from reading UI file 'gamescene.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENE_H
#define UI_GAMESCENE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScene
{
public:
    QGraphicsView *graphicsView;
    QPushButton *startNewGame;
    QPushButton *pauseGame;
    QLabel *scorePlayer2;
    QLabel *scorePlayer1;
    QLabel *winLabel;

    void setupUi(QWidget *GameScene)
    {
        if (GameScene->objectName().isEmpty())
            GameScene->setObjectName("GameScene");
        GameScene->resize(1020, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GameScene->setWindowIcon(icon);
        graphicsView = new QGraphicsView(GameScene);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 1020, 650));
        graphicsView->setAcceptDrops(true);
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/ship1020.png);"));
        startNewGame = new QPushButton(GameScene);
        startNewGame->setObjectName("startNewGame");
        startNewGame->setGeometry(QRect(420, 80, 171, 41));
        startNewGame->setAcceptDrops(false);
        pauseGame = new QPushButton(GameScene);
        pauseGame->setObjectName("pauseGame");
        pauseGame->setGeometry(QRect(470, 0, 81, 81));
        QFont font;
        font.setPointSize(12);
        pauseGame->setFont(font);
        pauseGame->setAcceptDrops(false);
        pauseGame->setStyleSheet(QString::fromUtf8("background-image: url(:/images/pauseimage.png);\n"
"background-repeat: no-repeat;\n"
"border: 0;"));
        scorePlayer2 = new QLabel(GameScene);
        scorePlayer2->setObjectName("scorePlayer2");
        scorePlayer2->setGeometry(QRect(700, 40, 466, 89));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setItalic(true);
        scorePlayer2->setFont(font1);
        scorePlayer1 = new QLabel(GameScene);
        scorePlayer1->setObjectName("scorePlayer1");
        scorePlayer1->setGeometry(QRect(220, 40, 467, 89));
        scorePlayer1->setFont(font1);
        winLabel = new QLabel(GameScene);
        winLabel->setObjectName("winLabel");
        winLabel->setGeometry(QRect(190, 160, 601, 61));
        QFont font2;
        font2.setPointSize(28);
        winLabel->setFont(font2);
        winLabel->setLayoutDirection(Qt::LeftToRight);
        winLabel->setAlignment(Qt::AlignCenter);
        graphicsView->raise();
        scorePlayer2->raise();
        winLabel->raise();
        scorePlayer1->raise();
        pauseGame->raise();
        startNewGame->raise();

        retranslateUi(GameScene);

        QMetaObject::connectSlotsByName(GameScene);
    } // setupUi

    void retranslateUi(QWidget *GameScene)
    {
        GameScene->setWindowTitle(QCoreApplication::translate("GameScene", "VolleyBall", nullptr));
        startNewGame->setText(QCoreApplication::translate("GameScene", "Start new Game", nullptr));
        pauseGame->setText(QString());
        scorePlayer2->setText(QCoreApplication::translate("GameScene", "0", nullptr));
        scorePlayer1->setText(QCoreApplication::translate("GameScene", "0", nullptr));
        winLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameScene: public Ui_GameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENE_H
