#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include "sound.h"

namespace Ui {
class about;
}

class about : public QDialog, public sound
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private slots:
    void on_back_clicked();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
