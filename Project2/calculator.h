#include <iostream>
#include <stack>
#include <string>
using namespace std;
enum MyEnum
{
	ADDITION,
	SUBSTRACTION,
	MULTIPLICATION,
	DIVISION
};
class calculator
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
		int val;
		opValue(oper op, int val);
	};

	int compute(int l, oper op, int r);

	oper GetOp();

	int getValue();

	void fuction();

	string to_be_cal;
	int index;
	stack<opValue> stack;
};

