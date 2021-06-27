#include <iostream>
#include <cmath>
#include <cstring>
#include "homework_3.h"
#include "blackjack.h"



int main(int argc, char const *argv[])
{

// Task 1
	std::cout << "Задание №1.\n" << std::endl;
	Parallelogram p(2, 5, 30);
	std::cout << "Площадь параллелограмма: " << p.getArea() << std::endl;

	Circle c(5);
	std::cout << "Площадь круга: " << c.getArea() << std::endl;

	Rectangle r(5, 6);
	std::cout << "Площадь прямоугольника: " << r.getArea() << std::endl;

	Square s(5);
	std::cout << "Площадь квадрата: " << s.getArea() << std::endl;

	Rombus romb(5, 30);
	std::cout << "Площадь ромба: " << romb.getArea() << std::endl;
	std::cout << "---------------------------------- \n" << std::endl;
	

// Task 2
	std::cout << "Задание №2.\n" << std::endl;

	Car gaz("ГАЗ", "3110");
	PassengerCar vaz("ВАЗ", "2109");
	Bus bus("Уралец", "66Б");
	Minivan mv("Лада", "Ларгус");
	std::cout << "---------------------------------- \n" << std::endl;


// Task 3
	std::cout << "Задание №3.\n" << std::endl;

	Fraction f1(2, 5);
	Fraction f2(3, 10);

	Fraction sum = f1+f2;
	Fraction sub = f1-f2;
	Fraction mult = f1*f2;
	Fraction div = f1/f2;
	Fraction neg = -f1;

	std::cout << "Результат "<< f1.getFrac() << "+" << f2.getFrac() << "=" << sum.getFrac() << std::endl;
	std::cout << "Результат "<< f1.getFrac() << "-" << f2.getFrac() << "=" << sub.getFrac() << std::endl;
	std::cout << "Результат "<< f1.getFrac() << "*" << f2.getFrac() << "=" << mult.getFrac() << std::endl;
	std::cout << "Результат "<< f1.getFrac() << ":" << f2.getFrac() << "=" << div.getFrac() << std::endl;
	std::cout << "Результат "<< neg.getFrac() << std::endl;

	printf("Дробь %s %sравна дроби %s\n", f1.getFrac().c_str(), f1==f2?"":"не", f2.getFrac().c_str());	//Проверка на равенство
	printf("Дробь %s %sравна дроби %s\n", f1.getFrac().c_str(), f1!=f2?"не":"", f2.getFrac().c_str());	//Проверка на неравенство
	printf("Дробь %s %s дроби %s\n", f1.getFrac().c_str(), f1>f2?"больше":"меньше", f2.getFrac().c_str());	//Проверка на больше
	printf("Дробь %s %s дроби %s\n", f1.getFrac().c_str(), f1<f2?"меньше":"больше", f2.getFrac().c_str());	//Проверка на меньше
	printf("Дробь %s %s дроби %s\n", f1.getFrac().c_str(), f1<=f2?"меньше или равна":"больше или равна", f2.getFrac().c_str());	//Проверка на меньше или равно
	printf("Дробь %s %s дроби %s\n", f1.getFrac().c_str(), f1>=f2?"больше или равна":"меньше или равна", f2.getFrac().c_str());	//Проверка на меньше или равно

	std::cout << "---------------------------------- \n" << std::endl;


// Task 4

	std::cout << "Задание №4.\n" << std::endl;

	Card a(Card::Value::queen, Card::Suit::diamonds);

	std::cout << "Значение карты: " << a.getValue() << std::endl;
	std::cout << "---------------------------------- \n" << std::endl;
	
	return 0;
}