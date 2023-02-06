/*
Вам нужно реализовать умный массив для данных типа int в духе идиомы RAII, 
который сам управляет своей памятью: самостоятельно выделяет её при создании и очищает, 
когда объект данного класса не используется.
Должны быть реализованы следующие функции:

Конструктор, принмающий количество элементов, которое будет хранить массив.
Функция добавления нового элемента в массив. Не забудьте обработать случай, 
когда количество элементов больше количества элементов, на которую выделена память.
Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
Деструктор.
*/


#include <iostream>

class smart_array
{
public:
	smart_array(int value);
	~smart_array();
	void add_element(int data);
	int get_element(int n);
protected:
	int* arr;
	int i;
	int value;
	int count_calc;
};

smart_array::smart_array(int value)
{
	i = count_calc = 0;
	arr = new int[value];
	this->value = value;
}
void smart_array::add_element(int data)
{
	count_calc++;
	if (count_calc > value)
	{
		throw std::exception("The number of elements is greater than the number of elements for which memory is allocated!");
	}
	arr[i++] = data;
}
int smart_array::get_element(int n)
{
	if (n > (value - 1))
	{
		throw std::exception("There is no such index in the current array!");
	}
	return arr[n];
}

smart_array::~smart_array()
{
	delete[] arr;
}

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

    return 0;
}
