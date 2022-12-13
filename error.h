#ifndef ERROR_H
#define ERROR_H
#include <QString>
#include <QMessageBox>
#include "registration.h"
#include "authentication.h"

class Error
{
public:
    Error(int code);
    void whatError();
    int getErrorCode();

private:
    int errorCode;
};

#endif // ERROR_H
