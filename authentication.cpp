#include "authentication.h"

class AuthenticationData : public QSharedData
{
public:

};

Authentication::Authentication() : data(new AuthenticationData)
{

}

Authentication::Authentication(const Authentication &rhs)
    : data{rhs.data}
{

}

Authentication &Authentication::operator=(const Authentication &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Authentication::~Authentication()
{

}
