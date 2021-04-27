#pragma once
#include <iostream>
#include <string>
using namespace std;
class bignum
{
public:
	bignum(string input);
	bignum(string nums, int floating_point);
	bignum(const bignum& rhs);
	bignum(int num);
	bignum();
	void input();
	bool isNegtive()const;
	bool isFloating()const;
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
	int floating_position;
};
