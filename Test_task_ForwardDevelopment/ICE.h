#pragma once
#include "Engine.h"
//internal combustion engine
//двигатель внутреннего сгорания
class ICE :
    public Engine
{
public:
    ICE(Engine_init&);
    ~ICE();
};

