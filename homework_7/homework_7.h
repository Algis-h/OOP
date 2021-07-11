#pragma once

// Task 1

/*
Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
Первому присвойте значение сегодняшней даты. 
Для него вызовите по отдельности методы доступа к полям класса Date, 
а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. 
Затем переместите ресурс, которым владеет указатель today в указатель date. 
Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
*/

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(){}

	Date(int day, int month, int year)
		:m_day(day), m_month(month), m_year(year){}

	int getDay()
	{
		return m_day;
	}

	int getMonth()
	{
		return m_month;
	}

	int getYear()
	{
		return m_year;
	}

	void setDay(int day)
	{
		m_day = day;
	}

	void setMonth(int month)
	{
		m_month = month;
	}

	void setYear(int year)
	{
		m_year = year;
	}

	void setDate(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}


	friend std::ostream& operator<< (std::ostream &out, const Date &date);
	
};

std::ostream& operator<< (std::ostream &out, const Date &date)
{
    out << date.m_day << "." << date.m_month << "." << date.m_year;
    return out;
}

/*
По условию предыдущей задачи создайте два умных указателя date1 и date2. 
Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
*/

std::shared_ptr<Date> compare(std::shared_ptr<Date> &date1, std::shared_ptr<Date> &date2)
{
	if((*date1).getYear() > (*date2).getYear())
	{
		return date1;
	}
	else if((*date1).getYear() < (*date2).getYear())
	{
		return date2;
	}
	else if((*date1).getMonth() > (*date2).getMonth())
	{
		return date1;
	}
	else if((*date1).getMonth() < (*date2).getMonth())
	{
		return date2;
	}	
	else if((*date1).getDay() > (*date2).getDay())
	{
		return date1;
	}
	else if((*date1).getDay() < (*date2).getDay())
	{
		return date2;
	}	
	return date1;
}

void swap(std::shared_ptr<Date> &date1, std::shared_ptr<Date> &date2)
{
	auto tmp = date1;
	date1 = date2;
	date2 = tmp;
}

