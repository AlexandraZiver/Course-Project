#ifndef WALL_H
#define WALL_H

#include <QWidget>

namespace Ui {
class Wall;
}

class Wall : public QWidget
{
    Q_OBJECT

public:
    explicit Wall(QWidget *parent = nullptr);
    ~Wall();

private:
    Ui::Wall *ui;
};

#endif // WALL_H
