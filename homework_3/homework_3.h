// Task 1
/*
Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/

class Figure
{
public:
	float m_a;
	float m_b;

	Figure(float a, float b)
		:m_a(a), m_b(b)
	{

	}
	virtual void area() = 0;
	
};

class Parallelogram: public Figure
{

public:
		float m_angle;
private:

		float m_area;

	void area()
	{
		m_area = m_a * m_b * sin(m_angle * M_PI / 180);
	} 
public:

	Parallelogram(float side_a, float side_b, float angle)
		:Figure(side_a, side_b), m_angle(angle)
	{
		area();
	}

	float getArea()
	{
		return m_area;
	}

	
};

class Circle: public Figure
{
private:
	float m_area;

	void area()
	{
		m_area = M_PI * pow(m_a, 2);
	} 

public:
	Circle(float radius)
		:Figure(radius, radius)
	{
		area();
	}

	float getArea()
	{
		return m_area;
	}
	
};

class Rectangle: public Parallelogram
{
private:
	float m_area;

	void area()
	{
		m_area = m_a * m_b;
	} 
public:
	Rectangle(float side_a, float side_b)
		:Parallelogram(side_a, side_b, 90)
	{
		area();
	}

	float getArea()
	{
		return m_area;
	}
	
};

class Square: public Parallelogram
{
private:
	float m_area;

	void area()
	{
		m_area = m_a * m_b;
	} 
public:
	Square(float side_a)
		:Parallelogram(side_a, side_a, 90)
	{
		area();
	}

	float getArea()
	{
		return m_area;
	}
	
};

class Rombus: public Parallelogram
{
private:
	float m_area;

	void area()
	{
		m_area = m_a * m_b * sin(m_angle * M_PI / 180);;
	} 
public:
	Rombus(float side_a, float angle)
		:Parallelogram(side_a, side_a, angle)
	{
		area();
	}

	float getArea()
	{
		return m_area;
	}
	
};

// Task 2

/*
Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти». 
*/

class Car
{
private:
	std::string m_company;
	std::string m_model;
public:
	Car(std::string company, std::string model)
		:m_company(company), m_model(model)
	{
		std::cout << "---------------------------------- \n" << std::endl;
		std::cout << "Класс Car: Компания: " << m_company << ", Модель: " << m_model << std::endl;
		std::cout << "---------------------------------- \n" << std::endl;
	}
	friend class PassengerCar;
	friend class Bus;
	friend class Minivan;
};

class PassengerCar: public Car
{
public:
	PassengerCar(std::string company, std::string model)
		:Car(company, model)
	{
		std::cout << "---------------------------------- \n" << std::endl;
		std::cout << "Класс PassengerCar: Компания: " << m_company << ", Модель: " << m_model << std::endl;
		std::cout << "---------------------------------- \n" << std::endl;
	}
	
};

class Bus: public Car
{
public:
	Bus(std::string company, std::string model)
		:Car(company, model)
	{
		std::cout << "---------------------------------- \n" << std::endl;
		std::cout << "Класс Bus: Компания: " << m_company << ", Модель: " << m_model << std::endl;
		std::cout << "---------------------------------- \n" << std::endl;
	}
	
};

class Minivan: public Bus, public PassengerCar
{
public:
	Minivan(std::string company, std::string model)
		:Bus(company, model), PassengerCar(company, model)
	{
		std::cout << "---------------------------------- \n" << std::endl;
		std::cout << "Класс Minivan: Компания: " << Bus::m_company << ", Модель: " << Bus::m_model << std::endl;
		std::cout << "---------------------------------- \n" << std::endl;
	}

};

// Task 3

/*
Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
*/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator, int denominator)
		:m_numerator(numerator), m_denominator(denominator)
	{

	}
	
	Fraction operator-()
	{
		return Fraction(-m_numerator, m_denominator);
	}

	int getNumerator()
	{
		return m_numerator;
	}

	int getDenominator()
	{
		return m_denominator;
	}

	std::string getFrac()
	{
		return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
	}


	
};

Fraction operator+( Fraction &frac1,  Fraction &frac2)
{
	Fraction sum((frac1.getNumerator() * frac2.getDenominator()) + frac2.getNumerator() * frac1.getDenominator(), frac1.getDenominator() * frac2.getDenominator());

	return sum;
}

Fraction operator-( Fraction &frac1,  Fraction &frac2)
{
	Fraction sub((frac1.getNumerator() * frac2.getDenominator()) - frac2.getNumerator() * frac1.getDenominator(), frac1.getDenominator() * frac2.getDenominator());

	return sub;
}

Fraction operator*( Fraction &frac1,  Fraction &frac2)
{
	Fraction mult(frac1.getNumerator() * frac2.getNumerator(), frac1.getDenominator() * frac2.getDenominator());

	return mult;
}

Fraction operator/( Fraction &frac1,  Fraction &frac2)
{
	Fraction div(frac1.getNumerator() * frac2.getDenominator(), frac1.getDenominator() * frac2.getNumerator());

	return div;
}

bool operator==( Fraction &frac1,  Fraction &frac2)
{
	return frac1.getNumerator() * frac2.getDenominator()==frac1.getDenominator() * frac2.getNumerator();
}

bool operator!=( Fraction &frac1,  Fraction &frac2)
{
	return !(frac1==frac2);
}

bool operator<( Fraction &frac1,  Fraction &frac2)
{
	return frac1.getNumerator() * frac2.getDenominator()<frac1.getDenominator() * frac2.getNumerator();
}

bool operator>( Fraction &frac1,  Fraction &frac2)
{
	return !(frac1<frac2);
}

bool operator<=( Fraction &frac1,  Fraction &frac2)
{
	return frac1.getNumerator() * frac2.getDenominator()<=frac1.getDenominator() * frac2.getNumerator();
}

bool operator>=( Fraction &frac1,  Fraction &frac2)
{
	return !(frac1<=frac2);
}