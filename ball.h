#ifndef BALL_H
#define BALL_H

#include <QWidget>

namespace Ui {
class Ball;
}

class Ball : public QWidget
{
    Q_OBJECT

public:
    explicit Ball(QWidget *parent = nullptr);
    ~Ball();

private:
    Ui::Ball *ui;
};

#endif // BALL_H
