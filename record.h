#ifndef RECORD_H
#define RECORD_H

#include <QDialog>
#include "sound.h"

namespace Ui {
class record;
}

class record : public QDialog, public sound
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = nullptr);
    ~record();

private slots:
    void on_back_clicked();

private:
    Ui::record *ui;
};

#endif // RECORD_H
