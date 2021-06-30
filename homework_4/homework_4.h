//Task 1
/*
Добавить в контейнерный класс, который был написан в этом уроке, методы:
для удаления последнего элемента массива (аналог функции pop_back() в векторах)
для удаления первого элемента массива (аналог pop_front() в векторах)
для сортировки массива
для вывода на экран элементов.
*/

class Container
{
private:
	int m_size;
	int *m_data;

public:
	Container()
		:m_size(0), m_data(nullptr)
	{

	}
	
	Container(int size)
		:m_size(size)
	{
        assert(size >= 0);

        if (size > 0)
            m_data = new int[size];
        else
            m_data = nullptr;
	}

	~Container()
	{
		delete m_data;
	}

	void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }
    
    int getSize() 
    {
    	return m_size;
    }

    int& operator[](int index)
    {
        //assert(index >= 0 && index < m_size);
        return m_data[index];
    }

    void resize(int newSize)
    {

        if (newSize == m_size)
            return;


        if (newSize <= 0)
        {
            erase();
            return;
        }

        int *data = new int[newSize];


        if (m_size > 0)
        {
            int elementsToCopy = (newSize > m_size) ? m_size : newSize;

            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }


        delete[] m_data;

        m_data = data;
        m_size = newSize;
    }

     void insertBefore(int value, int index)
    {

        assert(index >= 0 && index <= m_size);

        int *data = new int[m_size+1];

        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        data [index] = value;


        for (int after=index; after < m_size; ++after)
            data[after+1] = m_data[after];
        
        delete[] m_data;
        m_data = data;
        ++m_size;
    }
    void push_back(int value)
    {
    	insertBefore(value, m_size); 
    }

    int popBack()
    {
    	int *data = new int[m_size-1];

    	for (int i = 0; i < m_size-1; ++i)
    	{
    		data[i] = m_data[i];
    	}

    	int value = m_data[m_size-1];

    	delete m_data;

    	m_data = data;
    	m_size--;

    	return value;
    }

    int popFront()
    {
    	int *data = new int[m_size-1];

    	for (int i = 0; i < m_size-1; ++i)
    	{
    		data[i] = m_data[i+1];
    	}

    	int value = m_data[0];

    	delete[] m_data;

    	m_data = data;
    	m_size--;

    	return value;

    }

    void sort()
    {
    	std::sort(m_data, m_data + m_size);
    }

    void print()
    {
    	std::cout << "(";
    	for (int i = 0; i < m_size; ++i)
    	{
    		std::cout << m_data[i] << ", ";
    	}
    	std::cout << ")" << std::endl;
    }

	
};


// Task 2

/*
Дан вектор чисел, требуется выяснить, сколько среди них различных. 
Постараться использовать максимально быстрый алгоритм.

*/

void print(std::vector<int> &v)
{
    int size = v.size();
    std::cout << "(";
    for (int i = 0; i < size; ++i)
        {
            std::cout << v[i] << ", ";
        }
        std::cout << ")" << std::endl;
}

std::vector<int> getUnique(std::vector<int> &v)
{
    int size = v.size();
    std::vector<int> result(0);


    for (int i = 0; i < size; ++i)
        {
            bool flag = true;
            for (int j = i + 1; j < size; ++j)
            {
                if(v[i] == v[j])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {   
                result.push_back(v[i]);
                flag = true;
            }

        }
    return result;
}
