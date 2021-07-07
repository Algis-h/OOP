#include <iostream>

// Task 1
/*
Создать программу, которая считывает целое число типа int. 
И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, 
нужно вывести сообщение об ошибке и предложить ввести число еще раз
*/

void task1()
{
    int a = 0;
    while(true)
    {
		std::cout << "Введите целое число: " << std::endl;;
		std::cin >> a;						   
		if (std::cin.peek() == '\n'){			
			break;	
		}
		else
		{
			std::cout << "Это не число! " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			//while (std::cin.get() != '\n'){}
		}  
	}
	std::cout << "Ваше число: "<< a << std::endl;
}

// Task 2
/*
Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/
void test()
{
	std::cout << "Test";
}

std::ostream& endll(std::ostream &out)
{
	out << "\n\n";
	out.flush();
	return out;
}


int main(int argc, char const *argv[])
{
	// Task 1

	// task1();

	// Task 2

	std::cout << "Тест!" <<  endll;
	std::cout << "Тест!" << std::endl;


	return 0;
}