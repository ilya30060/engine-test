#pragma once
#include "ICE.h"
#include "Environment.h"

//сущность тестировочного стенда
class test_machine
{
public:
	//длительность шага
	static float discrete_rate;
	//стенд тестирования на перегрев
	static float overheat_test(ICE&);
	//стенд тестирования на максимальную мощность
	static std::pair<float, float> max_power(ICE&);
};