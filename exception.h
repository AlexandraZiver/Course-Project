#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "qlineedit.h"
#include <QString>
#include "error.h"


class exception
{
public:
    exception();
    void checkWeight (int weight, QLineEdit *lineEdit_3);

};

int ExceptionOn_reg_clicked(QString playerName, QString password, QString passwordCheck);
int ExeptionOn_done_clicked(QString playerName, QString password);


#endif // EXCEPTION_H
