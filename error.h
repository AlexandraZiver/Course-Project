#ifndef ERROR_H
#define ERROR_H
#include <QString>
#include <QMessageBox>
#include "registration.h"
#include "authorization.h"

class Error
{
public:

    Error();
    void whatError(int errorCode);
    int getErrorCode(int codeError);


private:
    int errorCode;
};

#endif // ERROR_H
