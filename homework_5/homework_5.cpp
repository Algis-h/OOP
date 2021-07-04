#include <iostream>
#include <string>
#include "homework_5.h"
#include "blackjack.h"

// Task 3
/*
Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. 
Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
*/

template <class T4>
class StringValuePair : public Pair<std::string, T4>
{

public:
	StringValuePair(std::string a, T4 b)
	:Pair<std::string, T4>(a, b)
	{

	}

	
};

int main(int argc, char const *argv[])
{
	// Task 1

	std::cout << "Задание №1" << std::endl;

	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	std::cout << "---------------------------------------------" << std::endl;
	
	

	// Task 2

	std::cout << "\nЗадание №2" << std::endl;

	Pair<int, double> p3(6, 7.8);
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(3.4, 5);
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	std::cout << "---------------------------------------------" << std::endl;

	// Task 3

	std::cout << "\nЗадание №3" << std::endl;

	StringValuePair<int> svp("Amazing", 7);

    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	std::cout << "---------------------------------------------" << std::endl;

	return 0;
}