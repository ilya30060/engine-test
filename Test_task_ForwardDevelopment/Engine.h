#pragma once
#include <map>
#include <iostream>
#include "Environment.h"

//структура для инициализации двигателя
struct Engine_init
{
	float I;
	std::map<float, float> MV_function;
	float T_overheat;
	float H_M;
	float H_V;
	float C;
	Environment& environment;
};

//класс двигателя
class Engine
{
protected:
	//технические характеристики как в условии задачи

	const float m_I;
	std::map<float, float> m_MV_function;
	const float m_T_overheat;
	const float m_H_M;
	const float m_H_V;
	const float m_C;


	//динамические параметры

	//скорость вращения коленвала, рад/с
	float m_velocity;
	//температура двигателя
	float m_engine_temperature;
	//ускорение коленвала, рад/с^2
	float m_acceleration();
	//крутящий момент
	float m_currentM();
	//скорость нагрева
	float m_heating_speed();
	//скорость остывания
	float m_cooling_speed();
	

	//конструктор по умолчанию не предусмотрен
	Engine(Engine_init&);
	~Engine();
	//окружающая среда двигателя
	Environment m_environment;

public:
	//минимальный интерфейс для работы

	//получение текущей температуры двигателя
	float get_temp();
	//получение температуры перегрева
	float get_T_overheat();
	//функция для имитации работы в течение некоторого времени
	void run(float);
	//проверка на включенность
	bool is_running();
	//проверка на выключенность
	bool is_stopped();
	//запуск (символический, но при необходимости можно реализовать свою логику запуска
	void start();
	//остановка двигателя
	void stop();
	//получение текущей скорости
	float get_velocity();
	//получение текущей мощности
	float get_power_kW();
};

