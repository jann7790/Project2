#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "calculator.h"
using namespace std;

calculator::calculator() :to_be_cal("0"), index(0) {}

calculator::oper::oper():op(-1), precedence(9999), associativity('L'){}

calculator::oper::oper(int op):op(op)
{
	switch (op)
	{
	case ADDITION:
		precedence = 6;
		associativity = 'L';
		break;
	case -1:
		precedence = 999;
		associativity = 'L';
		break;
	case SUBSTRACTION:
		precedence = 6;
		associativity = 'L';
		break;
	case MULTIPLICATION:
		precedence = 5;
		associativity = 'L';
		break;
	case DIVISION:
		precedence = 5;
		associativity = 'L';
		break;
	case FACTORIAL:
		precedence = 2;
		associativity = 'R';
		break;
	case POWER:
		precedence = 3;
		associativity = 'R';
		break;
	default:
		break;
	}
}


calculator::opValue::opValue(oper op, bignum val) :op(op), val(val) {}

bignum fact(bignum l)
{
	bignum s = 1;
	for (bignum i(1); i < l || i == l; i = i + 1)
	{
		s = s * i;
	}
	return s;
}

bignum calculator::compute(bignum l, oper op, bignum r)
{
	switch (op.op)
	{
	case ADDITION:
		return l + r;
		break;
	case SUBSTRACTION:
		return l - r;
		break;
	case MULTIPLICATION:
		return l * r;
		break;
	case DIVISION:
		return l / r;
		break;
	case FACTORIAL:
		return !l;
		break;
	case POWER:
		return l ^ r;
		break;
	default:
		return bignum(0);
		break;
	}
}

calculator::oper calculator::GetOp()
{
	if(index >= to_be_cal.length())
		return oper(-1);

	switch (to_be_cal[index])
	{
	case '+':
		index++;
		return oper(ADDITION);
		break;
	case '-':
		index++;
		return oper(SUBSTRACTION);
		break;
	case '*':
		index++;
		return oper(MULTIPLICATION);
		break;
	case '/':
		index++;
		return oper(DIVISION);
		break;
	case '!':
		index++;
		return oper(FACTORIAL);
		break;
	case '^':
		index++;
		return oper(POWER);
		break;
	default:
		index++;
		return oper(-1);
		break;
	}

}

bignum calculator::getValue()
{
	string num = "";
	for (; index < to_be_cal.length(); index++)
	{
		if (isdigit(to_be_cal[index]) || to_be_cal[index] == '.')
			num += to_be_cal[index];
		else if (to_be_cal[index] == '(')
		{
			bignum result;
			index++;
			result = fuction();
			if (to_be_cal[index-1] != ')')
				cout << "aaaaaaaaaaaa";
			return result;
			break;
		}
		else
		{
			break;
		}
	}
	if (num == "")return 0;
	return bignum(num);
}

bignum calculator::fuction()
{
	//3 + 5 + 3
	bignum value = getValue();
	stack.push(opValue(oper(-1), 0));
	while (!stack.empty())
	{
		oper onthestack = GetOp();
		while (stack.top().op.precedence < onthestack.precedence || (stack.top().op.precedence == onthestack.precedence && onthestack.associativity == 'L'))
		{
			if (stack.top().op.op == -1)
			{
				stack.pop();
				return value;
			}
			value = compute(stack.top().val, stack.top().op, value);
			stack.pop();
		}
		stack.push(opValue(onthestack, value));
		value = getValue();
	}
	stack.push(opValue(oper(-1), 0));

}

void calculator::Removewhite()
{
	for (size_t i = 0; i < to_be_cal.length(); i++)
	{
		if (to_be_cal[i] == ' ')
		{
			to_be_cal = to_be_cal.substr(0, i) + to_be_cal.substr(i + 1, to_be_cal.length());

		}
	}
}

