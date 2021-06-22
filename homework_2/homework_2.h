// Task 1
/*Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. 
Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. 
Создать счетчик количества созданных студентов. 
В функции main() создать несколько студентов. По запросу вывести определенного человека.*/

class Person
{
private:
	std::string m_name;
	short m_age;
	std::string m_sex;
	short m_weight;

public:
	Person(std::string name, short age, std::string sex, short weight)
		:m_name(name), m_sex(sex), m_age(age), m_weight(weight)
		{

		}
	void print()
	{
		std::cout << "------------------------------" << std::endl;
		std::cout << "Имя: " << m_name << std::endl;
		std::cout << "Возраст: " << m_age << std::endl;
		std::cout << "Пол: " << m_sex << std::endl;
		std::cout << "Вес: " << m_weight << std::endl;
	}

	void setName(std::string name)
	{
		m_name = name;
	}

	void setAge(short age)
	{
		m_age = age;
	}

	void setSex(std::string sex)
	{
		m_sex = sex;
	}

	void setWeight(short weight)
	{
		m_weight = weight;
	}

};

class Student: public Person
{
	private:
		static int m_count;
		short m_course;
	
	public:
		Student(std::string name, short age, std::string sex, short weight, short course = 1)
			:Person(name, age, sex, weight), m_course(course)
		{
			m_count++;
		}
	
	void print()
	{
		Person::print();
		std::cout << "Курс: " << m_course << std::endl;
		std::cout << "Всего студентов: " << m_count << std::endl;
	}

	void setCourse(short course)
	{
		m_course = course;
	}

	void courseUp()
	{
		m_course++;
	}
};

int Student::m_count = 0;

// Task 2

/*
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
У Fruit есть две переменные-члена: name (имя) и color (цвет). 
Добавить новый класс GrannySmith, который наследует класс Apple.
*/


class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string name, std::string color)
		:m_name(name), m_color(color)
		{

		}
	
	std::string getName()
	{
		return m_name;
	}

	std::string getColor()
	{
		return m_color;
	}

	void print()
	{
		std::cout << "------------------------------"<< std::endl;
		std::cout << "Имя: " << m_name << std::endl;
		std::cout << "Цвет: " << m_color << std::endl;
	}

};

class Apple: public Fruit
{
public:
	Apple(std::string color = "green", std::string name = "apple")
		:Fruit(name, color)
		{

		}

};

class Banana: public Fruit
{
public:
	Banana(std::string color = "yellow")
		:Fruit("banana", color)
		{

		}

};

class GrannySmith: public Apple
{

public:
	GrannySmith()
		:Apple("green", "Granny Smith apple")
		{

		}
	
};