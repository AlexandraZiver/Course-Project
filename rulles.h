#ifndef RULLES_H
#define RULLES_H

#include <QDialog>

namespace Ui {
class rulles;
}

class rulles : public QDialog
{
    Q_OBJECT

public:
    explicit rulles(QWidget *parent = nullptr);
    ~rulles();

private slots:


    void on_play_game_clicked();

private:
    Ui::rulles *ui;
};

#endif // RULES_H
