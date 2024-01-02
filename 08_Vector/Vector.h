#pragma once
#include <iostream>
using namespace std;
class Vector
{
	int* buffer = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	void fill(const int& value = 0);
	void setCapacity();
	void copy(int* dest, const int* source);
	bool empty() const;
	bool outRange(const int& index) const;
	void reserve_buffer(const int& capacity);
	bool full() const;
public:
	Vector() = default;
	Vector(const size_t& size):Vector(size,0){}
	Vector(const size_t& size, const int& value)
		:size{size}
	{
		this->setCapacity();
		this->buffer = new int[this->capacity];
		this->fill(value);
	}
	Vector(const Vector& other)
		:Vector(other.size)
	{
		this->capacity = other.capacity;
		copy(this->buffer, other.buffer);
	}
	~Vector()
	{
		if (this->buffer == nullptr)
		{
			delete[] this->buffer;
		}
	}
	void print() const;
	const size_t& capacity_() const;
	const size_t& size_() const;
	void setValue(const int& index, const int& value);
	const int& getValue(const int& index) const;
	void pushBack(const int& value);
	void popBack();
	void insert(const int& index, const int& value);
	void remove(const int& index);
	void resize(const int& size, const int& value);
	int& front();
	int& back();
	void clear();
	void reserve(const int& capacity);
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


