#pragma once
#include <iostream>
using namespace std;
class Vector
{
	int* buffer = nullptr; // вказівник на динамічний масив цілих чисел
	size_t size = 0; //  фактичний розмір вектору(фактична кількість елементів вектору)
	size_t capacity = 0; // розмір масиву(з запасом)
	void fill(const int& value = 0);
	void setCapacity();
	void copy(int* dest, const int* source);
	bool outRange(const int& index) const;
	void reserve_buffer(const int& capacity);
	bool full() const;
public:
	Vector() = default;  // Конструктор за замовчуванням – масив порожній
	Vector(const size_t& size) :Vector(size, 0) {} // використали делегування конструктора
	Vector(const size_t& size, const int& value) //Конструктор резервує пам'ять для масиву, фактичний розмір = size, ємність- Ваша формула(збільшили в два рази, елементи = value
		:size{ size }
	{
		this->setCapacity();
		reserve_buffer(this->capacity);
		this->fill(value);
	}
	Vector(const Vector& other) // Конструктор копії
		:Vector(other.size)
	{
		this->capacity = other.capacity;
		copy(this->buffer, other.buffer);
	}
	~Vector() // Деструктор
	{
		if (this->buffer == nullptr)
		{
			delete[] this->buffer;
		}
	}
	bool empty() const; // Метод перевірки чи вектор пустий
	const size_t& capacity_() const; // Метод доступу(на читання) до поля capacity
	const size_t& size_() const; // Метод доступу(на читання) до поля size
	void setValue(const int& index, const int& value); // Метод встановлення(зміни) елемента за індексом
	const int& getValue(const int& index) const; // Метод доступу(читання) елемента за індексом
	void pushBack(const int& value); // Метод додавання нового елемента у кінець масиву
	void popBack(); // Метод вилучення останнього  елемента
	void insert(const int& index, const int& value);  // Метод вставки нового елемента за вказаним індексом
	void remove(const int& index); 
	int& front(); // Метод, що повертає посилання на перший елемент вектору
	int& back(); // Метод, що повертає посилання на останній елемент вектору
	void clear(); // Метод  очистки вектору
	void reserve(const int& capacity); // Метод зміни capacity
	void resize(const int& size, const int& value = 0); // Метод зміни фактичної довжини масиву
	void print() const; // Метод виводу  масиву
	Vector operator *(const int& number); // множення вектору на число
	Vector operator +(const Vector& other); // дозволяє об’єднати 2 вектори
	Vector& operator ++(); // збільшення кожного елементу вектора на 1 (префіксна)
	Vector& operator ++(int); // збільшення кожного елементу вектора на 1(постфіксна)
	bool operator ==(const Vector& other) const; // порівняння двох векторів
	bool operator !=(const Vector& other) const; // порівняння двох векторів
	Vector& operator !(); // реверс вектору
	int operator[](const size_t& index) const; //Оператор індексування(доступ до елемента за індексом) (читання)
	int& operator[](const size_t& index); // Оператор індексування(доступ до елемента за індексом) (запис)
	void operator =(const Vector& other); // операція присвоєння
	void operator +=(const Vector& other); // доповнення першого вектору елементами другого вектору
	void operator *=(const int& number); // домноження елементів вектору на деяке ціле  число
	operator int(); // операція перетворення до типу int, повертати суму елементів масиву
};

inline void Vector::setCapacity()
{
	this->capacity = this->size * 2;
}
inline const size_t& Vector::capacity_() const
{
	return this->capacity;
}

inline const size_t& Vector::size_() const
{
	return this->size;
}
inline bool Vector::empty() const
{
	return size == 0;
}

inline bool Vector::outRange(const int& index) const
{
	return (index < 0 || index >= this->size);
}
inline bool Vector::full() const
{
	return this->size == this->capacity;
}
inline void Vector::clear()
{
	this->size = 0;
}


