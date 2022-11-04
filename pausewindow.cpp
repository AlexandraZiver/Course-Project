#include "pausewindow.h"
#include "ui_pausewindow.h"

PauseWindow::PauseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PauseWindow)
{
    ui->setupUi(this);
}

PauseWindow::~PauseWindow()
{
    delete ui;
}
