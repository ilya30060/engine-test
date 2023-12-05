#include "test_machine.h"
//инициализация статического поля
float test_machine::discrete_rate = 1.0f;

float test_machine::overheat_test(ICE& engine)
{
	float test_time = 0.0f;
	float engine_T_overheat = engine.get_T_overheat();
	if (engine.is_stopped()) engine.start();
	else std::cout << "Engine is already running\n";
	while (engine.get_temp() < engine_T_overheat)
	{
		engine.run(discrete_rate);
		test_time += discrete_rate;
	}
	engine.stop();
	return test_time;
}

//returned value = <max_velocity, max_power_kW>
std::pair<float, float> test_machine::max_power(ICE& engine)
{
	float max_power = -0.1f;
	float max_velocity = -0.1f;
	if (engine.is_stopped()) engine.start();
	else std::cout << "Engine is already running\n";
	while (engine.get_velocity() < 300.0f)
	{
		engine.run(discrete_rate);
		if (max_power < engine.get_power_kW())
		{
			max_power = engine.get_power_kW();
			max_velocity = engine.get_velocity();
		}
		else break;
	}
	engine.stop();
	return std::pair<float, float>(max_velocity, max_power);
}
