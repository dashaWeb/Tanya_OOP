#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;
class Fraction
{
public:
	Fraction()
	{
		num = 0;
		denum = 1;
		//cout << "Default ctor " << toString() << endl;
	}
	Fraction(const int& num):Fraction(num,1)
	{
		//cout << "Ctor 1 params " << toString() << endl;

	}
	Fraction(const int& num, const int& denum) //:num{ num }, denum{denum}
	{
		/*this->num = num;
		this->denum = denum;*/
		// valid
		setNum(num);
		setdeNum(denum);
		//cout << "Ctor 2 params " << toString() << endl;
	}
	const int& getNum() const;
	const int& getDenum() const;
	void setNum(const int& num);
	void setdeNum(const int& denum);
	void print() const;
	string toString() const;
	Fraction add(const Fraction& other) const; //res =  one{this}.add(two{other})
	Fraction sub(const Fraction& other) const; //res =  one{this}.add(two{other})
	Fraction mult(const Fraction& other) const; //res =  one{this}.add(two{other})
	Fraction division(const Fraction& other) const; //res =  one{this}.add(two{other})
	Fraction addNum(const int& number) const;
	Fraction multNum(const int& number) const;
	bool Equals(const Fraction& other) const;
	void reduction();
	~Fraction()
	{
		//cout << "Dtoc " << toString() << endl;
	}
private:
	int num, denum;
};
inline const int& Fraction::getNum() const
{
	return this->num;
}

inline const int& Fraction::getDenum() const
{
	return this->denum;
}

inline void Fraction::setNum(const int& num)
{
	this->num = num;
}

inline void Fraction::setdeNum(const int& denum)
{
	if (denum < 0) {
		cout << "Error" << endl;
		this->denum = 1;
		return;
	}
	this->denum = denum;
}
