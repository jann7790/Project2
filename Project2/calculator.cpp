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
	default:
		break;
	}
}


calculator::opValue::opValue(oper op, int val) :op(op), val(val) {}

int calculator::compute(int l, oper op, int r)
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
	default:
		return 0;
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
	default:
		index++;
		return oper(-1);
		break;
	}

}

int calculator::getValue()
{
	string num = "";
	for (; index < to_be_cal.length(); index++)
	{
		if (isdigit(to_be_cal[index]))
			num += to_be_cal[index];
		else if (to_be_cal[index] == '(')
		{
			int result;
			index++;
			result = fuction();
			if (to_be_cal[index-1] != ')')
				cout << "aaaaaaaaaaaa";
			num = to_string(result);
			break;
		}
		else
		{
			break;
		}
	}
	if (num == "")return 0;
	return stoi(num);
}

int calculator::fuction()
{
	//3 + 5 + 3
	int value = getValue();
	stack.push(opValue(oper(-1), 0));
	while (!stack.empty())
	{
		oper onthestack = GetOp();
		while (stack.top().op.precedence < onthestack.precedence || stack.top().op.precedence == onthestack.precedence)
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


