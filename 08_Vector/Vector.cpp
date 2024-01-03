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
	if (size > this->capacity)
	{
		this->capacity = size;
		reserve_buffer(this->capacity);
	}
	for (this->size; this->size < size; this->size++)
	{
		this->buffer[this->size] = value;
	}
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
	this->capacity = capacity;
	reserve_buffer(this->capacity);
}

Vector Vector::operator*(const int& number)
{
	auto tmp(*this);
	for (size_t i = 0; i < this->size; i++)
	{
		tmp.buffer[i] *= number;
	}
	return tmp;
}

Vector Vector::operator+(const Vector& other)
{
	auto tmp = *this;
	for (size_t i = 0; i < other.size; i++)
	{
		tmp.pushBack(other.getValue(i));
	}
	return tmp;
}

void Vector::operator=(const Vector& other)
{
	if (this->capacity < other.size)
	{
		this->capacity = other.capacity;
		this->reserve_buffer(this->capacity);
	}
	this->size = other.size;
	copy(this->buffer, other.buffer);
}

Vector& Vector::operator++()
{
	for (size_t i = 0; i < this->size; i++)
	{
		++this->buffer[i];
	}
	return *this;
}

Vector& Vector::operator++(int)
{
	auto tmp(*this);
	++* this;
	return tmp;
}

bool Vector::operator==(const Vector& other) const
{
	if (this->size != other.size) {
		return false;
	}
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->buffer[i] != other.buffer[i])
			return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& other) const
{
	return !(*this == other);
}

int Vector::operator[](const size_t& index) const
{
	static int ErrorValue = 0;
	if (this->outRange(index))
	{
		cout << "Error! The index goes beyond the vector" << endl;
		return ErrorValue;
	}
	return this->buffer[index];
}

int& Vector::operator[](const size_t& index)
{
	static int ErrorValue = 0;
	if (this->outRange(index))
	{
		cout << "Error! The index goes beyond the vector" << endl;
		return ErrorValue;
	}
	return this->buffer[index];
}

Vector& Vector::operator!()
{
	auto tmp(*this);
	for (size_t i = 0; i < tmp.size / 2; i++)
	{
		swap(tmp.buffer[i], tmp.buffer[tmp.size - i - 1]);
	}
	return tmp;
}

void Vector::operator+=(const Vector& other)
{
	*this = *this + other;
}

void Vector::operator*=(const int& number)
{
	*this = *this * number;
}

Vector::operator int()
{
	int sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		sum += this->buffer[i];
	}
	return sum;
}
