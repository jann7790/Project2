#pragma once
#include <iostream>
#include <string>
using namespace std;
class bignum
{
public:
	bignum(string nums) :numbers(nums), power(0) {}/////power power
	bignum() :numbers(""), power(0) {}
	void input();
	bignum operator=(const bignum& rhs);
	bignum operator+(const bignum& rhs);
	bignum operator-(const bignum& rhs);
	bignum operator*(const bignum& rhs);
	bignum operator/(const bignum& rhs);
	friend ostream& operator<<(ostream& str, bignum rhs);
	friend istream& operator>>(istream& str, bignum& rhs);
	string numbers;
	int power;
};
