#pragma once
#include "ICE.h"
#include "Environment.h"

//�������� �������������� ������
class test_machine
{
public:
	//������������ ����
	static float discrete_rate;
	//����� ������������ �� ��������
	static float overheat_test(ICE&);
	//����� ������������ �� ������������ ��������
	static std::pair<float, float> max_power(ICE&);
};