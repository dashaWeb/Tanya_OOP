#include "Vector.h"

void Vector::fill(const int& value)
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->buffer[i] = value;
	}
}
void Vector::copy(int* dest, const int* source)
{
	for (size_t i = 0; i < this->size; i++)
	{
		dest[i] = source[i];
	}
}
void Vector::resize(const int& size, const int& value)
{

}
inline void Vector::reserve_buffer(const int& capacity)
{
	if (this->buffer == nullptr) {
		this->buffer = new int[capacity];
		return;
	}
	int* tmp = new int[capacity];
	this->copy(tmp, this->buffer);
	delete[] this->buffer;
	this->buffer = tmp;
}
void Vector::print() const
{
	if (empty())
	{
		cout << "The vector is empty." << endl;
		return;
	}
	for (size_t i = 0; i < this->size; i++)
	{
		cout << this->buffer[i] << "\t";
	}
	cout << endl;
}
void Vector::setValue(const int& index, const int& value)
{
	if (outRange(index))
	{
		cout << "Error! The index goes beyond the vector" << endl;
		return;
	}
	this->buffer[index] = value;
}
const int& Vector::getValue(const int& index) const
{
	if (outRange(index))
	{
		static int ErrorValue = 0;
		cout << "Error! The index goes beyond the vector" << endl;
		return ErrorValue;
	}
	return this->buffer[index];
}

void Vector::pushBack(const int& value)
{
	if (full())
	{
		setCapacity();
		reserve_buffer(this->capacity);
	}
	this->buffer[this->size++] = value;
}

void Vector::popBack()
{
	if (empty())
	{
		cout << "Unable to delete last item. The vector is empty." << endl;
		return;
	}
	--this->size;
}
void Vector::insert(const int& index, const int& value)
{
	if (outRange(index))
	{
		cout << "Error! The index goes beyond the vector" << endl;
		return;
	}
	if (full())
	{
		setCapacity();
		reserve_buffer(this->capacity);
	}
	for (int i = this->size; i > index; i--)
	{
		this->buffer[i] = this->buffer[i - 1];
	}
	this->buffer[index] = value;
	this->size++;
}
void Vector::remove(const int& index)
{
	if (empty())
	{
		cout << "Unable to delete item. The vector is empty." << endl;
		return;
	}
	if (outRange(index))
	{
		cout << "Error! The index goes beyond the vector" << endl;
		return;
	}
	--this->size;
	for (size_t i = index; i < this->size; i++)
	{
		this->buffer[i] = this->buffer[i + 1];
	}
}
int& Vector::front()
{
	static int ErrorValue = 0;
	if (empty())
	{
		cout << "The vector is empty" << endl;
		return ErrorValue;
	}
	return this->buffer[0];
}

int& Vector::back()
{
	static int ErrorValue = 0;
	if (empty())
	{
		cout << "The vector is empty" << endl;
		return ErrorValue;
	}
	return this->buffer[this->size - 1];
}
void Vector::reserve(const int& capacity)
{
	if (capacity < this->capacity)
	{
		cout << "The value of the new reserve must be greater than the current one" << endl;
		return;
	}
	reserve_buffer(capacity);
}