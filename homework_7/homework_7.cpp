#include <iostream>
#include <memory>
#include <utility>
#include "homework_7.h"




int main(int argc, char const *argv[])
{
	// Task 1

	std::cout << "Задание №1." << std::endl;

	auto today = std::make_shared<Date>(11, 7, 2021);
	auto date = std::make_shared<Date>();

	
	date = today; //Как перемещать и следующие задания не понял.

	std::cout << "День: " << (*today).getDay() << " Месяц: " << (*today).getMonth() << " Год: " << (*today).getYear() << std::endl;
	std::cout << "День: " << (*date).getDay() << " Месяц: " << (*date).getMonth() << " Год: " << (*date).getYear() << std::endl;

	std::cout << "Дата: " << *date << std::endl;
	std::cout << "Дата: " << *today << std::endl;

	std::cout << "-----------------------------------------" << std::endl;

	// Task 2

	std::cout << "Задание №2." << std::endl;

	auto date1 = std::make_shared<Date>(11, 7, 2021);
	auto date2 = std::make_shared<Date>(12, 7, 2021);

	std::cout << "Более поздняя дата: " << *compare(date1, date2) << std::endl;

	std::cout << "Дата 1: " << *date1 << std::endl;
	std::cout << "Дата 2: " << *date2 << std::endl;

	swap(date1, date2);

	std::cout << "Дата 1: " << *date1 << std::endl;
	std::cout << "Дата 2: " << *date2 << std::endl;

	std::cout << "-----------------------------------------" << std::endl;


	return 0;
}