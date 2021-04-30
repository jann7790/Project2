#include "bignum.h"
#include "calculator.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	/*bignum num1;
	bignum num2;
	bignum num3;
	bignum num4;
	string a = "12.34555";
	string b = "1234555";
	bignum aa = bignum("0.1");
	cin >> num1;
	cin >> num2;
	cout << "num1 + num2 = " << num1 + num2 << endl;
	cout << "num1 - num2 = " << num1 - num2 << endl;
	cout << "num1 * num2 = " << num1 * num2 << endl;
	cout << "num1 / num2 = " << num1 / num2 << endl;*/
	calculator ccc;
	ccc.to_be_cal = "2*(2+1)*9+(1234*3+9*5+(5+6))";
	cout << ccc.fuction();

}