#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <windows.h>

class MainWindow : virtual public windows
{
public:
    MainWindow();
    void volume();
            void buttonRecord();
            void buttonStartGame();
};

#endif // MAINWINDOW_H
