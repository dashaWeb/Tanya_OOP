#include "String.h"

void String::print() const
{
	cout << str;
}

size_t String::getSize() const
{
	return size;
}

void String::input()
{
	char s;
	int counter = 0;
	do
	{
		s = _getch();
		if (s == 13) { cout << endl; break; }
		cout << s;
		if (size == counter) {
			resize();
		}
		str[counter++] = s;
	} while (s != 13);
	str[counter] = '\0';
}

String String::concat(const String& other) const
{
	String tmp(strlen(this->str) + strlen(other.str) + 20);
	int counter = 0;
	while (this->str[counter] != '\0')
	{
		tmp.str[counter] = this->str[counter];
		counter++;
	}
	int i = 0;
	while (other.str[i] != '\0')
	{
		tmp.str[counter++] = other.str[i++];
	}
	tmp.str[counter++] = '\0';
	//strcpy_s(tmp.str, strlen(this->str) + 1, this->str);
	//strcat_s(tmp.str, strlen(other.str) + 1, other.str);
	return tmp;
}

String String::slice(const String& other) const
{
	String tmp;
	int counter = 0;
	for (size_t i = 0; i < strlen(this->str); i++)
	{
		bool flag = false;
		for (size_t j = 0; j < strlen(other.str); j++)
		{
			if (this->str[i] == other.str[j]) {
				flag = true;
				for (size_t q = 0; q < counter; q++)
				{
					if (tmp.str[q] == this->str[i]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				tmp.str[counter++] = this->str[i];
				break;
			}
		}
	}
	tmp.str[counter] = '\0';
	return tmp;
}

const char& String::get(const int& index) const
{
	if (index < 0 || index >= size) {
		return '\0';
	}
	return str[index];
}

void String::set(const int& index, const char& letter)
{
	if (index < 0 || index >= size || index > strlen(str)) {
		return;
	}
	if (index == strlen(str)) {
		str[index + 1] = '\0';
	}
	str[index] = letter;
}

void String::copyStr(const char* other)
{
	if (this->str != nullptr) {
		delete[] this->str;
	}
	this->size = strlen(other);
	this->str = new char[this->size + 1];
	strcpy_s(this->str, this->size + 1, other);
}

const char* String::getLine() const
{
	return str;
}

String::~String()
{
	if (str != nullptr) {
		delete[] str;
	}
}

void String::resize()
{
	size += 10;
	char* new_str = new char[size + 1];
	strcpy_s(new_str, strlen(str) + 1, str);
	delete[] str;
	str = new_str;
}

