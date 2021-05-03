#pragma once
#include "bignum.h"
#include "calculator.h"
class Integer : public bignum
{
public:
	Integer()
	{
		integer_part = "0";
		negtive = false;
		float_part = "0";
		floating = false;
	}
	Integer& operator=(const char* rhs)
	{
		calculator cal;
		for (int i = 0;rhs[i] != NULL;i++)
		{
			cal.to_be_cal += rhs[i];
		}
		cal.fuction();
		integer_part = cal.result.integer_part;
		negtive = cal.result.negtive;
		float_part = "0";
		floating = false;
		return *this;

	}

	Integer(string expr)
	{
		calculator cal;
		cal.to_be_cal = expr;
		cal.fuction();
		integer_part = cal.result.integer_part;
		negtive = cal.result.negtive;
		float_part = "0";
		floating = false;
	}

};
class Decimal : public bignum
{
public:
	Decimal()
	{
		integer_part = "0";
		negtive = false;
		float_part = "0";
		floating = true;
	}
	Decimal& operator=(const char* rhs)
	{
		calculator cal;
		for (int i = 0; rhs[i] != NULL; i++)
		{
			cal.to_be_cal += rhs[i];
		}
		cal.to_be_cal = rhs;
		cal.fuction();
		integer_part = cal.result.integer_part;
		negtive = cal.result.negtive;
		float_part = cal.result.float_part;
		floating = cal.result.floating;
		return *this;

	}
	Decimal(string expr)
	{
		calculator cal;
		cal.to_be_cal = expr;
		cal.fuction();
		integer_part = cal.result.integer_part;
		negtive = cal.result.negtive;
		float_part = cal.result.float_part;
		floating = cal.result.floating;
	}

};