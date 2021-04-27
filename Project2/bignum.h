#pragma once
#include <iostream>
#include <stack>

using namespace std;
class bignum
{
public:
	bignum(string nums) :numbers(nums), power(0) {}/////power power
	bignum() :numbers(""), power(0) {}
	void input();
	void process();
	void output();
	void stringHandle();
	bignum& operator=(bignum& rhs);
	bignum& operator+(bignum& rhs);
	bignum& operator-(bignum& rhs);
	bignum& operator*(bignum& rhs);
	bignum& operator/(bignum& rhs);
	friend ostream& operator<<(ostream& str, bignum& rhs);
	friend istream& operator>>(istream& str, bignum& rhs);
private:
	string numbers;
	int power;
};
