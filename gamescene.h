#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>
#include <QMainWindow>
#include "Box2D/Box2D.h"

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>    // walls

#include <QGraphicsPixmapItem>  // players

#include <QKeyEvent>
#include <QTimer>
#include <QString>

#define SCALE 100;
#define PlayerSpeed 5;
#define PlayerHeightJump 7;


class Scene : public QGraphicsScene {
    Q_OBJECT;
public:
    Scene(qreal x, qreal y, qreal width, qreal height, b2World *world);
public slots:
    void advance();
private:
    b2World* world;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    ~GameScene();

public slots:
    void score();
    void ballSleep();
    void endGame();
    void startGame();

private slots:
    void on_startNewGame_clicked();
    void on_pauseGame_clicked();

    void on_back_clicked();

private:
    Ui::GameScene *ui;
    Scene* scene;
    QTimer* frameTimer;
    QTimer* scoreTimer;
    b2World* world;
};



class Wall : public QGraphicsRectItem {   // Статический елемент
public:
    Wall(b2World *world, QSizeF size, QPointF initPos, qreal angle);
    ~Wall();
private:
    b2Body* body;
};



class Ball : public QGraphicsEllipseItem {
public:
    Ball(b2World* world, qreal Radius, QPointF initPos);
    ~Ball();
    //sleep?
    void advance(int phase);
private:

};



class Player_1 : public QGraphicsRectItem {
public:
    Player_1(b2World* world, QSizeF size, QPointF initPos, qreal angel);
    ~Player_1();
    void advance(int phase);
};

class Player_2 : public QGraphicsRectItem {
public:
    Player_2(b2World* world, QSizeF size, QPointF initPos, qreal angle);
    ~Player_2();
    void advance(int phase);

};

#endif // GAMESCENE_H
