#include "Engine.h"

float Engine::m_acceleration()
{
	return m_currentM() / m_I;
}

float Engine::m_currentM()
{
	float currentM = 0;
	for (std::map<float, float>::iterator element1{ m_MV_function.begin() }, element2{ m_MV_function.begin() }; element2 != m_MV_function.end(); element1++)
	{
		element2++;
		if (m_velocity >= element1->first && m_velocity <= element2->first)
		{
			currentM = element1->second + (m_velocity - element1->first) * ((element2->second - element1->second) / (element2->first - element1->first));
			break;
		}
	}
	return currentM;
}

float Engine::m_heating_speed()
{
	return m_currentM() * m_H_M + m_velocity * m_velocity * m_H_V;
}

float Engine::m_cooling_speed()
{
	return m_C * (m_engine_temperature - m_environment.m_temperature);
}

float Engine::get_power_kW()
{
	return m_currentM() * m_velocity / 1000; //нужны к¬т, поэтому делим на 1000
}



Engine::Engine(Engine_init& engine_init):
	m_I(engine_init.I),
	m_T_overheat(engine_init.T_overheat),
	m_H_M(engine_init.H_M),
	m_H_V(engine_init.H_V),
	m_C(engine_init.C),
	m_MV_function(engine_init.MV_function),
	m_velocity(0.0f),
	m_engine_temperature(engine_init.environment.m_temperature),
	m_environment(engine_init.environment)

{
}

Engine::~Engine()
{
}

float Engine::get_temp()
{
	return m_engine_temperature;
}

float Engine::get_T_overheat()
{
	return m_T_overheat;
}

void Engine::run(float time)
{
	m_engine_temperature += (m_heating_speed() - m_cooling_speed()) * time;
	m_velocity += m_acceleration() * time;
	if (m_velocity > 300.0f) m_velocity = 300.0f;
}

bool Engine::is_running()
{
	return m_velocity == 0 ? false : true;
}

bool Engine::is_stopped()
{
	return m_velocity == 0 ? true : false;
}

void Engine::start()
{
	std::cout << "Engine started\n";
}

void Engine::stop()
{
	m_velocity = 0;
	m_engine_temperature = m_environment.m_temperature;
	std::cout << "Engine stopped\n";
}

float Engine::get_velocity()
{
	return m_velocity;
}
