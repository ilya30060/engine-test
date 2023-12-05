#pragma once
#include <map>
#include <iostream>
#include "Environment.h"

//��������� ��� ������������� ���������
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

//����� ���������
class Engine
{
protected:
	//����������� �������������� ��� � ������� ������

	const float m_I;
	std::map<float, float> m_MV_function;
	const float m_T_overheat;
	const float m_H_M;
	const float m_H_V;
	const float m_C;


	//������������ ���������

	//�������� �������� ���������, ���/�
	float m_velocity;
	//����������� ���������
	float m_engine_temperature;
	//��������� ���������, ���/�^2
	float m_acceleration();
	//�������� ������
	float m_currentM();
	//�������� �������
	float m_heating_speed();
	//�������� ���������
	float m_cooling_speed();
	

	//����������� �� ��������� �� ������������
	Engine(Engine_init&);
	~Engine();
	//���������� ����� ���������
	Environment m_environment;

public:
	//����������� ��������� ��� ������

	//��������� ������� ����������� ���������
	float get_temp();
	//��������� ����������� ���������
	float get_T_overheat();
	//������� ��� �������� ������ � ������� ���������� �������
	void run(float);
	//�������� �� ������������
	bool is_running();
	//�������� �� �������������
	bool is_stopped();
	//������ (�������������, �� ��� ������������� ����� ����������� ���� ������ �������
	void start();
	//��������� ���������
	void stop();
	//��������� ������� ��������
	float get_velocity();
	//��������� ������� ��������
	float get_power_kW();
};

