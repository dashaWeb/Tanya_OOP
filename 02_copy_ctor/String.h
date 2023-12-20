#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
class String
{
public:
	String():String(80)
	{

	}
	String(const size_t size) :size{size}
	{
		str = new char[size + 1];
	}
	String(const char* line)
	{
		copyStr(line);
	}
	String(const String& other) // this -> clone; other -> str_3
	{
		copyStr(other.str);
		cout << "Copy ctor :: " << str << endl;
	}
	void operator =(const String& other) { // this -> clone; other -> str_3
		copyStr(other.str);
		cout << "operator = :: " << str << endl;
	}
	void print() const;
	size_t getSize() const;
	void input();
	String concat(const String& other) const;
	String slice(const String& other) const;
	const char& get(const int& index) const;
	void set(const int& index, const char& letter);
	void copyStr(const char* other);
	const char* getLine() const;
	~String();
private:
	char* str = nullptr;
	size_t size = 0;
	void resize();
};

