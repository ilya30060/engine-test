#pragma once
#include "Engine.h"
//internal combustion engine
//��������� ����������� ��������
class ICE :
    public Engine
{
public:
    ICE(Engine_init&);
    ~ICE();
};

