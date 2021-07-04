// Task 1

/*
Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
*/

template <class T1>
class Pair1
{
private:
	T1 m_a;
	T1 m_b;

public:
	Pair1(){}

	Pair1(T1 a, T1 b)
		:m_a(a), m_b(b)
	{

	}

	T1 first() const
	{
		return m_a;
	}

	T1 second() const
	{
		return m_b;
	}
	
};

// Task 2
/*
Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
*/

template<class T2, class T3>
class Pair
{
public:
	T2 m_a;
	T3 m_b;
public:
	Pair(T2 a, T3 b)
		:m_a(a), m_b(b)
	{

	}
	T2 first() const
	{
		return m_a;
	}

	T3 second() const
	{
		return m_b;
	}
};