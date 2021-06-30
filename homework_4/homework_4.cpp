#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

#include "blackjack.h"

#include "homework_4.h"




int main(int argc, char const *argv[])
{

	// Task 1

	std::cout << "Задание №1: " << std::endl;

	Container array(10);

	for (int i = 0; i < 10; ++i)
	{
		array[i] = rand()%100;
	}
	
	array.print();

	std::cout << "Размер массива: " << array.getSize() << std::endl;
	std::cout << "Зачение popBack ячейки: " << array.popBack() << std::endl;
	std::cout << "Размер массива: " << array.getSize() << std::endl;
	std::cout << "Зачение popFront ячейки: " << array.popFront() << std::endl;
	std::cout << "Размер массива: " << array.getSize() << std::endl;

	std::cout << "Неотсортированный массив: ";
	array.print();
	array.sort();
	std::cout << "Отсортированный массив: ";
	array.print();
	std::cout << "--------------------------------------------------------" << std::endl;
	
	// Task 2
	std::cout << "Задание №2: " << std::endl;

	int size = 10;

	std::vector<int> unique(size);
	srand(43);
	for (int i = 0; i < size; ++i)
	{
		unique[i] = rand()%5;
	}

	std::cout << "В массиве: ";
	print(unique);
	std::vector<int> test = getUnique(unique);
	std::cout << test.size() << " уникальных данных." << std::endl;
	print(test);
	std::cout << "--------------------------------------------------------" << std::endl;

	// Task 3
	std::cout << "Задание №3: " << std::endl;

	Card a(Card::Value::ace, Card::Suit::hearts);
	Card b(Card::Value::queen, Card::Suit::hearts);

	Hand hand;
	hand.Add(a);
	hand.Add(b);

	std::cout << hand.getValue() << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	
	return 0;
}