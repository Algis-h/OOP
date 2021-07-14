// Task 1

/*Написать шаблонную функцию div, 
которая должна вычислять результат деления двух параметров 
и запускать исключение DivisionByZero, если второй параметр равен 0. 
В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
*/

template <class T1, class T2>
double div(T1 a, T2 b)
{
	if(b == 0) throw "Деление на 0.";
	return (a/b);
}

// Task 2

/*
Написать класс Ex, хранящий вещественное число x 
и имеющий конструктор по вещественному числу, 
инициализирующий x значением параметра. 
Написать класс Bar, хранящий вещественное число y 
(конструктор по умолчанию инициализирует его нулем) 
и имеющий метод set с единственным вещественным параметром a. 
Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. 
В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/

class Ex
{
private:
	double m_x;
public:
	Ex(double x)
		:m_x(x)
		{

		}
	double getErr()
	{
		return m_x;
	}

};

class Bar
{
private:
	double m_y;
public:
	Bar(double y = 0)
	{

	}

	void set(double a)
	{
		if(m_y + a > 100) throw Ex(a * m_y);
		m_y = a;
	}
	
};

// Task 3

/*
Написать класс «робот», моделирующий перемещения робота по сетке 10x10, 
у которого есть метод, означающий задание переместиться на соседнюю позицию. 
Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, 
и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. 
Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
а также выводящую подробную информацию о всех возникающих ошибках.
*/

class OffTheField
{
public:
	OffTheField()
	{

	}

	std::string getErr()
	{
		std::string err = "Робот ушел с поля!";
		return err;
	}
	
};

class IllegalCommand
{
public:
	IllegalCommand()
	{

	}

	std::string getErr()
	{
		std::string err = "Неправильная команда!";
		return err;
	}
		
};


class Robot
{
private:
	int m_x;
	int m_y;

	void checkCoordinates()
	{
		if(m_x < 1 || m_x > 10 || m_y < 1 || m_y > 10)
		{
			throw OffTheField();
		}
	}

public:
	Robot(int x = 1, int y = 1)
		:m_x(x), m_y(y)
	{
		checkCoordinates();
	}

	int getX()
	{
		return m_x;
	}

	int getY()
	{
		return m_y;
	}

	void move(char command)
	{

		switch (command)
		{
			case 'l':
				m_x--;
				break;

			case 'r':
				m_x++;
				break;

			case 'u':
				m_y++;
				break;

			case 'd':
				m_y--;
				break;
			
			default:
				throw IllegalCommand();
		}
		checkCoordinates();
	}


	
	friend std::ostream& operator<< (std::ostream &out, const Robot &r);
};

std::ostream& operator<<(std::ostream &out, const Robot &r)
{
	out << "X = " << r.m_x << ", Y = " << r.m_y;
	return out;
}
