#include "calculator.h"
#include "input.h"
#include <string>
#include <iostream>

using namespace variable;
using namespace std;
int main()
{
	bignum num1;
	bignum num2;
	bignum num3;
	bignum num4;
	//cout << "input a, b:";

	//cout << (bignum(2) ^ bignum(-2)) << endl;

	//cout << "num1 >= num2 = " << (num1 >= num2) << endl;
	//cout << "num1 > num2 = " << (num1 > num2) << endl;
	//cout << "num1 < num2 = " << (num1 < num2) << endl;
	//cout << "num1 == num2 = " << (num1 == num2) << endl;
	//cout << "num1 + num2 = " << num1 + num2 << endl;
	//cout << "num1 - num2 = " << num1 - num2 << endl;
	//cout << "num1 * num2 = " << num1 * num2 << endl;
	//cout << "num1 / num2 = " << num1 / num2 << endl;
	//cout << "num1! = " << (!num1) << endl;
	//cout << "num1 ^ num2 = " << (num1 ^ num2) << endl;
	calculator ccc;
	//cin.ignore(123123123123, '\n');
	//cout << "input calculation:";
	while (1)
	{
		ccc.input();
		ccc.fuction();
		ccc.parse();
		cout << ccc.output << endl;
	}
	////cout << ccc.to_be_cal;
	//cout << ccc.fuction();
}