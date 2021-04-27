#include "bignum.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	bignum num1;
	bignum num2;
	bignum num3;
	bignum num4;
	string a = "12.34555";
	string b = "1234555";
	bignum aa = bignum("0.1");
	cin >> num1;
	cin >> num2;
	/*cout << "num1 > num2 = " << (num1 > num2) << endl;
	cout << "num1 >= num2 = " << (num1 >= num2) << endl;
	cout << "num1 < num2 = " << (num1 < num2) << endl;
	cout << "num1 == num2 = " << (num1 == num2) << endl;*/
	cout << "num1 + num2 = " << num1 + num2 << endl;
	cout << "num1 - num2 = " << num1 - num2 << endl;
	cout << "num1 * num2 = " << num1 * num2 << endl;
	cout << "num1 / num2 = " << num1 / num2 << endl;
}