#include <iostream>
#include <cmath>
#include <cstdint>

#define STACK_SIZE 10


// Task 1

/*
Создать класс Power, который содержит два вещественных числа. 
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, 
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. З
адать значения этих двух чисел по умолчанию.*/

class Power
{
private:
	int m_a;
	int m_b;

public:
	Power()
	{
		m_a = 2;
		m_b = 2;
	}

	void set(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	int calculate()
	{
		return pow(m_a, m_b);
	}
};


// Task 2

/*
Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
Написать функцию print(), которая будет выводить значения переменных-членов.
*/

class RGBA
{
private:
	std::uint8_t m_red, m_green, m_blue, m_alpha;

public:
	RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255)
		:m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
		{

		}

	void print()
	{
		std::cout<<"red = "<< unsigned(m_red) << std::endl;
		std::cout<<"green = "<< unsigned(m_green) << std::endl;
		std::cout<<"blue = "<< unsigned(m_blue) << std::endl;
		std::cout<<"alpha = "<< unsigned(m_alpha) << std::endl;
	}
	
};


// Task 3

/*
Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;
public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, 
если массив уже заполнен, и true в противном случае;
public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
public-метод с именем print(), который будет выводить все значения стека.
*/

class Stack
{
private:
	int m_array[STACK_SIZE] = {0};
	int m_size = 0;
public:
	void reset()
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_array[i] = 0;
			m_size = 0;
		}
	}
	bool push(int a)
	{
		if (m_size + 1 >= STACK_SIZE)
		{
			return false;
		}
		m_array[m_size++] = a;
		return true;
	}
	int pop()
	{
		if(m_size != 0)
		{
			int tmp = m_array[--m_size];
			m_array[m_size] = 0;
			return tmp;
		}
		std::cout << "Стек пуст!" << std::endl;
	}

	void print()
	{
		std::cout << "(";
		for (int i = 0; i < m_size; ++i)
		{
			std::cout << m_array[i] << ", ";
		}
		std::cout << ")" << std::endl;
	}
};