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
	//cin >> num1;
	//cin >> num2;

	//cout << (bignum(2) ^ bignum(-2)) << endl;
	//cout << (num1 ^ num2) << endl;

/*	cout << "num1 >= num2 = " << (num1 >= num2) << endl;
	cout << "num1 > num2 = " << (num1 > num2) << endl;
	cout << "num1 < num2 = " << (num1 < num2) << endl;
	cout << "num1 == num2 = " << (num1 == num2) << endl;
	cout << "num1 + num2 = " << num1 + num2 << endl;
	cout << "num1 - num2 = " << num1 - num2 << endl;
	cout << "num1 * num2 = " << num1 * num2 << endl;
	cout << "num1 / num2 = " << num1 / num2 << endl;
	cout << "num1! = " << (!num1) << endl;
	cout << "num1 ^ num2 = " << (num1 ^ num2) << endl;
	
	cin.ignore(123123123123, '\n');
	cout << "input calculation:";*/
	cout << pow(10, 100);
	calculator ccc;
	while (1)
	{
		ccc.input();
		ccc.Removewhite();
		cout << ccc.fuction() << endl;
	}
	

}