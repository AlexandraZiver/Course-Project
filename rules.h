#ifndef RULES_H
#define RULES_H

#include <QDialog>
#include "sound.h"

namespace Ui {
class rules;
}

class rules : public QDialog, public sound
{
    Q_OBJECT

public:
    explicit rules(QWidget *parent = nullptr);
    ~rules();

private slots:


    void on_play_game_clicked();

private:
    Ui::rules *ui;
};

#endif // RULES_H
