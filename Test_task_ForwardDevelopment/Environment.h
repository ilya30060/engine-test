#pragma once
//класс окружающей среды
class Environment
{
private:
	float m_temperature;
public:
	Environment(float&);
	~Environment();
	friend class Engine;
};

