/*
Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода: 
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

*/

class Card
{
public:
	enum Suit
	{
		hearts,
		diamonds,
		clubs,
		spades

	};

	enum Value
	{
		ace=1,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		junior,
		queen,
		king
	};

	Suit m_suit;
	Value m_value;
	bool m_turn = false;

public:
	Card(Value value, Suit suit)
		:m_value(value), m_suit(suit)
	{

	}

	void flip()
	{
		m_turn = !m_turn;
	}

	Value getValue()
	{
		return m_value;
	}

	void print()
	{
		std::cout << m_turn << std::endl;
	}
	
};
