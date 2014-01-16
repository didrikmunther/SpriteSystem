#include "CBody.h"

#include <iostream>

CBody::CBody() :
X(0), Y(0), VelX(0), VelY(0)
{
}

CBody::~CBody()
{
    std::cout << "CBody dtor\n";
}
