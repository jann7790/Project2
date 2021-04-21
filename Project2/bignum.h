#pragma once
#include <iostream>
using namespace std;
class bignum
{
public:
	void input();
	bignum& operator+(bignum& rhs);
	bignum& operator-(bignum& rhs);
	bignum& operator*(bignum& rhs);
	bignum& operator/(bignum& rhs);
private:
	string numbers;
	int power;
};