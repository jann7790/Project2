#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "bignum.h"
using namespace std;
enum MyEnum
{
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISION,
	FACTORIAL,
	POWER
};
class calculator : public bignum
{
public:
	calculator();
	struct oper
	{
		int op;
		int precedence;
		char associativity;
		oper();
		oper(int op);
	};
	struct opValue
	{
		oper op;
		bignum val;
		opValue(oper op, bignum val);
	};

	bignum compute(bignum l, oper op, bignum r);

	oper GetOp();

	bignum getValue();

	bignum fuction();

	void Removewhite();
	string to_be_cal;
	int index;
	stack<opValue> stack;
};

