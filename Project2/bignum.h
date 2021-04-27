#pragma once
#include <iostream>
#include <string>
using namespace std;
class bignum
{
public:
	bignum(string nums) :numbers(nums), power(0) {}/////power power
	bignum(const bignum& rhs):numbers(rhs.numbers){}
	bignum(int num)
	{
		numbers = "";
		do
		{
			numbers.insert(0, to_string(num % 10));
			num /= 10;
		} while (num != 0);
	}
	bignum() :numbers(""), power(0) {}
	void input();
	bool isNegtive()const;
	bignum operator=(const bignum& rhs);
	const bignum operator+(const bignum& rhs);
	const bignum operator-(const bignum& rhs);
	const bignum operator*(const bignum& rhs);
	const bignum operator/(const bignum& rhs);
	friend ostream& operator<<(ostream& str, bignum rhs);
	friend istream& operator>>(istream& str, bignum& rhs);
	friend const bool operator>(const bignum& lhs, const bignum& rhs);
	friend const bool operator>=(const bignum& lhs, const bignum& rhs);
	friend const bool operator<(const bignum& lhs, const bignum& rhs);
	friend const bool operator==(const bignum& lhs, const bignum& rhs);
	string numbers;
	int power;
};
