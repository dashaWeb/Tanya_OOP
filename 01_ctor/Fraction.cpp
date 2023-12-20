#include "Fraction.h"
void Fraction::print() const
{
	cout << getNum() << "/" << getDenum();
}

string Fraction::toString() const
{
	return to_string(this->num) + "/" + to_string(this->denum);
}

Fraction Fraction::add(const Fraction& other) const
{
	if (this->denum == other.denum) {
		return Fraction(this->num + other.num, this->denum);
	}
	/*int num = this->num * other.denum + other.num * this->denum;
	int denum = this->denum * other.denum;
	return Fraction(num, denum);*/
	return Fraction(this->num * other.denum + other.num * this->denum, this->denum * other.denum);
}

Fraction Fraction::sub(const Fraction& other) const
{
	if (this->denum == other.denum) {
		return Fraction(this->num - other.num, this->denum);
	}

	return Fraction(this->num * other.denum - other.num * this->denum, this->denum * other.denum);
}

Fraction Fraction::mult(const Fraction& other) const
{
	return Fraction(this->num * other.num, this->denum * other.denum);
}

Fraction Fraction::division(const Fraction& other) const
{
	return Fraction(this->num * other.denum, this->denum * other.num);
}

Fraction Fraction::addNum(const int& number) const
{
	return add(Fraction(num));
}

Fraction Fraction::multNum(const int& number) const
{
	return Fraction(this->num * number, this->denum);
}

bool Fraction::Equals(const Fraction& other) const
{
	return this->num == other.num && this->denum == other.denum;
}

void Fraction::reduction()
{
	int start;
	this->num < this->denum ? start = this->num : start = this->denum;
	for (size_t i = start; i > 1; i--)
	{
		if (num % i == 0 && denum % i == 0) {
			num /= i;
			denum /= i;
			i = start / i;
		}
	}
}

// 1/5 + 3
// 1/5 + 3/1
// 