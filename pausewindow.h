#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QWidget>

namespace Ui {
class PauseWindow;
}

class PauseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PauseWindow(QWidget *parent = nullptr);
    ~PauseWindow();

private:
    Ui::PauseWindow *ui;
};

#endif // PAUSEWINDOW_H
