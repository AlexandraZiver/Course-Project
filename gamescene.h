#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>

namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    void generation();
           void buttonBackToPause();
           void gameButtonPress();
           void gameButtonLease();
           void saveData();
           void animation();
           void recieveData();
    ~GameScene();

private:
    Ui::GameScene *ui;
};

#endif // GAMESCENE_H
