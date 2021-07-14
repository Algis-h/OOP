#include <iostream>
#include <string>
#include "homework_8.h"


int main(int argc, char const *argv[])
{
	// Task 1

	std::cout << "Задание №1." << std::endl;
	
	float a = 10;
	int b = 0;

	try
	{
	auto result = div(a, b);
	std::cout << result << std::endl;
	}
	catch(const char *a)
	{
		std::cout << a << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	
	// Task 2

	std::cout << "Задание №2." << std::endl;
	
	double test;
	Bar bar;
	while(true)
	{
		try
		{
			std::cout << "Введите число: " << std::endl;
			std::cin >> test;
			if(test == 0) break;
			bar.set(test);
		}
		catch (Ex &err)
		{
			std::cout << "Исключение: " << err.getErr() << std::endl;
			break;
		}
	}

	std::cout << "--------------------------" << std::endl;

	
	// Task 3

	std::cout << "Задание №3." << std::endl;

	Robot rob;
	char command;
	while (command != 'q')
	{
		std::cout << "Координаты робота: " << rob << std::endl;
		std::cout << "Введите команду: (l - влево, r - вправо, u - вверх, d - вниз, q - выход)" << std::endl;
		std::cin >> command;
		try
		{
			rob.move(command);
		}
		catch (IllegalCommand &errCommand)
		{
			std::cout << errCommand.getErr() << std::endl;
			break;
		}

		catch (OffTheField &errField)
		{
			std::cout << errField.getErr() << std::endl;
			break;
		}
	}
	return 0;
}