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



class Circle : public QGraphicsEllipseItem {
public:
     Circle(b2World *world, qreal radius, QPointF initPos);
    ~Circle();
private:
    b2Body* body;
public:
    virtual void advance(int phase);
};



class GroundRect : public QGraphicsRectItem {   // Статический елемент
public:
    GroundRect(b2World *world, QSizeF size, QPointF initPos, qreal angle);
    ~GroundRect();
private:
    b2Body* body;
};



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
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

// Ball
class Ball : public QGraphicsEllipseItem {
public:
    Ball(b2World* world, qreal Radius, QPointF initPos);
    ~Ball();
    //sleep?
    void advance(int phase);
private:

};




namespace Ui { class gameScene; }

class gameScene : public QWidget
{
    Q_OBJECT

public:
    explicit gameScene(QWidget *parent = nullptr);
    ~gameScene();

public slots:
    void score();
    void ballSleep();
    void endGame();
    void startGame();

private slots:
    void on_startNewGame_clicked();

    void on_pauseGame_clicked();

    void on_unPauseGame_2_clicked();

private:
    Ui::gameScene *ui;
    Scene* scene;
    QTimer* frameTimer;
    QTimer* scoreTimer;
    b2World* world;
    Circle* ball1;
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
