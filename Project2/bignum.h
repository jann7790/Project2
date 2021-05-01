#pragma once
#include <iostream>
#include <string>
using namespace std;
class bignum
{
public:
	bignum(string);
	bignum(double);
	bignum(string, string, bool);
	bignum(const bignum&);
	bignum();
	void input();
	bool isNegtive()const;
	bool isFloating()const;
	void Stripzero();

	bignum operator=(const bignum& rhs);
	const bignum operator+(const bignum& rhs);
	const bignum operator-(const bignum& rhs);
	const bignum operator*(const bignum& rhs);
	const bignum operator/(const bignum& rhs);
	const bignum operator!(void);
	const bignum operator^(const bignum& rhs);
	friend ostream& operator<<(ostream& str, bignum rhs);
	friend istream& operator>>(istream& str, bignum& rhs);
	friend const bool operator>(bignum, bignum);
	friend const bool operator>=(bignum, bignum);
	friend const bool operator<(bignum, bignum);
	friend const bool operator<(bignum, bignum);
	friend const bool operator==(bignum, bignum);
	friend const bool operator!=(bignum, bignum);
	string integer_part;
	string float_part;
	bool negtive;
};

