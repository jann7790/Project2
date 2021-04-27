#include "bignum.h"
#include <iostream>
using namespace std;
int main()
{

	bignum num1;
	bignum num2;
	cin >> num1;
	cin >> num2;
	cout << num1 + num2 <<endl;
	cout << num1 - num2 << endl;
	cout << num1 * num2 <<endl;
}