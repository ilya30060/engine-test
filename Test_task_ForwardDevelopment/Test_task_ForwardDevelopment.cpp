/*
Добро пожаловать, сейчас вы находитесь в точке входа приложения.
Коротко о структуре:
Все классы имеют исходный файл и заголовочный файл.
В заголовочных файлах - объявления, в исходниках - определения.
Engine - родительский класс для двигателей.
    Поскольку по заданию требовалось моделирование двигателя внутреннего сгорания,
    то всё, для текущего удобства, было расположено именно здесь, а не в дочернем классе.
    Перенос некоторого содержимого возможен, при необходимости.
    (Например, для реактивного двигателя не нужна скорость вращения коленвала, поэтому она отправиться в ДВС.
ICE - двигатель внутреннего сгорания, дочерний от Engine.
    Чисто схематичный, полезной нагрузки в данной сборке не несёт - как и было сказано, весь функционал описан в Engine.
Environment - класс-прототип для окружающей среды.
    В данном задании из окружающей среды у нас лишь температура,
    но можно и прописать зависимость от влажности, нагрева от солнца и т.п.
test_machine - класс, содержащий в себе тестовые стенды (функции)
Текущий файл - точка входа, ввод-вывод, задание начальных значений.
    Реализован контроль погрешности - ввод периода дискретизации.
    Эксперимент можно повторять, не завершая программу.
*/




#include <iostream>
#include "ICE.h"
#include "test_machine.h"

int main()
{
    try
    {
        char answer;
        do {
            system("cls");
            //переменная для искомого двигателя
            ICE* My_engine;
            //код выделен в блоки, чтобы переменные уничтожались. Закос под оптимизацию...
            {
                //температура окружающей среды
                float env_temp;
                std::cout << "Enter the environment temperature\n";
                std::cin >> env_temp;
                Environment* classic_env = new Environment(env_temp);

                //исходные данные для двигателя, переменная инициализации
                Engine_init* startup = new Engine_init
                {
                    10.0f,
                    std::map<float, float>
                    {
                        std::pair<float,float>{0.0f,20.0f},
                        std::pair<float,float>{75.0f,75.0f},
                        std::pair<float,float>{150.0f,100.0f},
                        std::pair<float,float>{200.0f,105.0f},
                        std::pair<float,float>{250.0f,75.0f},
                        std::pair<float,float>{300.0f,0.0f},
                    },
                    110.0f,
                    0.01f,
                    0.0001f,
                    0.1f,
                    *classic_env
                };

                //период дискретизации в секундах
                float timing = 1.0f;
                std::cout << "Do you wanna change calculating timestep? Now: each 1s. " <<
                    "Now you can enter your own (or enter 1 if won't)\n";//чтобы ничего не менять нужно ввести 1
                std::cin >> timing;//можно ввести более точный просчёт, например, не раз за секунду, а каждую милисекунду
                test_machine::discrete_rate = timing;

                My_engine = new ICE(*startup);//инициализация двигателя

                delete classic_env, startup;//очищение выделенной памяти - впереди новые итерации
            }
            //начало первого теста
            std::cout << "First test...\n";
            {
                float time = test_machine::overheat_test(*My_engine);
                std::cout << "It was " << time << " second(s) to reach over-temp\n";
            }
            //начало второго теста
            std::cout << "Second test...\n";
            {
                std::pair<float, float> temp = test_machine::max_power(*My_engine);
                std::cout << "It was " << temp.first <<
                    " radians per sec while engine had reach its maximum power = "
                    << temp.second << " kW\n";
            }

            //очищение памяти после тестов
            delete My_engine;

            //возможность повторить кружок
            std::cout << "Thanks\n\nWanna repeat - enter 1\nWanna quit - press anything else\n";
            std::cin >> answer;
        } while (answer == '1');
    }
    //ради отладки. не понадобилось
    catch (...)
    {
        std::cerr << "Emm...\n";
    }
}
