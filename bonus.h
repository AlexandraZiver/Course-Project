#ifndef BONUS_H
#define BONUS_H

#include "Box2D/Box2D.h"
#include <QGraphicsItem>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>

#include <QGraphicsPixmapItem>
#include "sound.h"

class Bonus : public QGraphicsPixmapItem, public sound {
public:
    Bonus(int xspread);
    void advance(int phase) override;
    int yspeed =  2;
private:
    QString bonus_type_;
    QColor bonus_color_;

};

#endif // BONUS_H
