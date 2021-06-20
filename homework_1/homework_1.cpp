#include "homework_1.h"

int main(int argc, char const *argv[])
{
	// Task 1
	std::cout << "Домашнее задание №1" << std::endl;

	Power task1;	// Создаем первый экземпляр класса Power
	Power def;		// Создаем второй экземпляр класса Power

	task1.set(4, 7);

	std::cout << task1.calculate() << std::endl;	//Вывод результата первого экземпляра.
	std::cout << def.calculate() << std::endl; 		//Вывод результата второго экземпляра. Значения по умолчанию.
	std::cout << "--------------------" << std::endl;


	// Task 2
	std::cout << "\nДомашнее задание №2" << std::endl;
	RGBA color1; 				//Экземпляр со значениями по умолчанию.
	RGBA color2(1, 2, 3, 25);
	color1.print();				//Вывод результата первого экземпляра. Значения по умолчанию.
	std::cout << "--------------------" << std::endl;
	color2.print();				//Вывод результата второго экземпляра. 
	std::cout << "--------------------" << std::endl;

	// Task 3
	std::cout << "\nДомашнее задание №3" << std::endl;
	
	Stack stack;				// Инициализация стека.

    stack.reset();				// Очистка стека.
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();



	return 0;
}