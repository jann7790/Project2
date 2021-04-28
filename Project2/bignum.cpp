#pragma once
#include <iostream>
#include <string>
#include "bignum.h"
#define DIVISION_DECIMAL_PLACE 10
using namespace std;

bignum::bignum(const bignum& rhs) {
	if (rhs.isFloating()) {
		floating_position = rhs.floating_position;
		int i = 0;
		for (i = rhs.numbers.length(); i >= floating_position; i++) {
			if (rhs.numbers[i] != '0')
				break;
		}
		numbers = rhs.numbers.substr(0, i);
	}
	else {
		floating_position = rhs.floating_position;
		int i = 0;
		for (i = 0; i < rhs.numbers.length(); i++)
		{
			if (rhs.numbers[i] != '0')
				break;
		}
		numbers = rhs.numbers.substr(i, rhs.numbers.length());
	}
}

bignum::bignum() :numbers(""), floating_position(0) {
}

bignum::bignum(string input) {
	if (input == "") {
		numbers = "0";
		floating_position = input.length();
	}

	if (input.find(".") != string::npos) {
		input = input.substr(0, input.find(".")) + input.substr(input.find(".") + 1, input.length());
		int floating_point = input.find(".");
		int i = input.length() - 1;
		for (; i > floating_point + 1; i--) {
			if (input[i] != '0')
				break;
		}
		input = input.substr(0, i + 1);
		i = 0;
		for (; i < floating_point - 1; i++) {
			if (input[i] != '0')
				break;
		}
		input = input.substr(i, input.length());
		numbers = input;
		floating_position = floating_point - i;
	}
	else {
		int i = 0;
		for (; i < input.length(); i++) {
			if (input[i] != '0')
				break;
		}
		numbers = input.substr(i, input.length());
		floating_position = numbers.length();
	}

}

bignum::bignum(string input, int floating_point) {
	if (input == "") {
		numbers = "0";
		floating_position = input.length();
	}
	int i = input.length() - 1;
	for (; i > floating_point + 1; i--) {
		if (input[i] != '0')
			break;
	}
	input = input.substr(0, i + 1);
	i = 0;
	for (; i < floating_point - 1; i++) {
		if (input[i] != '0')
			break;
	}
	input = input.substr(i, input.length());
	numbers = input;
	floating_position = floating_point - i;
}

bool bignum::isNegtive()const {
	if (numbers.find("-") != string::npos)
		return 1;
	return 0;
}

bool bignum::isFloating()const {
	if (floating_position < numbers.length())
		return 1;
	return 0;
}

void bignum::input() {
	cin >> numbers;
}

const bool operator==(const bignum& lhs, const bignum& rhs) {
	if (lhs.numbers.length() == rhs.numbers.length()) {
		for (size_t i = 0; i < lhs.numbers.length(); i++) {
			if (lhs.numbers[i] != rhs.numbers[i])
				return 0;
		}
		return 1;
	}
	return 0;
}

const bool operator>=(const bignum& lhs, const bignum& rhs) {
	if (lhs < rhs)
		return 0;
	return 1;
}

const bool operator>(const bignum& lhs, const bignum& rhs) {
	if (!lhs.isNegtive() && !rhs.isNegtive()) {
		if (lhs.numbers.length() > rhs.numbers.length())
			return 1;
		if (lhs.numbers.length() < rhs.numbers.length())
			return 0;
		for (size_t i = 0; i < lhs.numbers.length(); i++) {
			if (lhs.numbers[i] > rhs.numbers[i])
				return 1;
			if (lhs.numbers[i] < rhs.numbers[i])
				return 0;
		}
	}
	else if (!lhs.isNegtive() && rhs.isNegtive()) {
		return 1;
	}
	else if (lhs.isNegtive() && !rhs.isNegtive()) {
		return 0;
	}
	else {
		if (lhs.numbers.length() > rhs.numbers.length())
			return 0;
		if (lhs.numbers.length() < rhs.numbers.length())
			return 1;
		for (size_t i = 1; i < lhs.numbers.length(); i++) {
			if (lhs.numbers[i] > rhs.numbers[i])
				return 0;
			if (lhs.numbers[i] < rhs.numbers[i])
				return 1;
		}
	}
	return 0;
}

const bool operator<(const bignum& lhs, const bignum& rhs) {
	if (lhs > rhs || (lhs == rhs))
		return 0;
	return 1;
}

const bignum bignum::operator+(const bignum& rhs) {
	//negtive
	if (isNegtive() && !rhs.isNegtive())
		return bignum(rhs) - bignum(numbers.substr(1, numbers.length()));
	//floating
	if (isFloating() || rhs.isFloating()) {
		bignum int_part = bignum(numbers.substr(0, floating_position)) + bignum(rhs.numbers.substr(0, rhs.floating_position));
		int result_position = int_part.numbers.length();
		string left_floating_num = numbers.substr(floating_position, numbers.length());
		string right_floating_num = rhs.numbers.substr(rhs.floating_position, rhs.numbers.length());
		if (left_floating_num.length() > right_floating_num.length()) {
			right_floating_num.append(left_floating_num.length() - right_floating_num.length(), '0');
		}
		else {
			left_floating_num.append(right_floating_num.length() - left_floating_num.length(), '0');
		}
		bignum floating_part = bignum(left_floating_num) + bignum(right_floating_num);

		string result = int_part.numbers + floating_part.numbers;

		return bignum(result, result_position);
	}
	string left_string = numbers;
	string right_string = rhs.numbers;
	string result = "";
	if (numbers.length() > rhs.numbers.length()) {
		right_string.insert(0, numbers.length() - right_string.length(), '0');
	}
	else {
		left_string.insert(0, right_string.length() - numbers.length(), '0');
	}
	int temp;
	int length = left_string.length();
	int carry = 0;
	for (size_t i = 0; i < length; i++) {
		temp = (right_string[length - i - 1] + left_string[length - i - 1]) - '0' - '0' + carry;
		carry = temp / 10;
		temp %= 10;
		result.insert(0, 1, temp + '0');
	}
	if (carry)
		result.insert(0, 1, carry + '0');

	return bignum(result);
}

const bignum bignum::operator-(const bignum& rhs) {
	if (isFloating() || rhs.isFloating()) {
		//int part padding
		string left_int_num = numbers.substr(0, floating_position);
		string right_int_num = rhs.numbers.substr(0, rhs.floating_position);
		if (left_int_num.length() > right_int_num.length()) {
			right_int_num.insert(0, left_int_num.length() - right_int_num.length(), '0');
		}
		else {
			left_int_num.insert(0, right_int_num.length() - left_int_num.length(), '0');
		}

		//float part padding
		string left_floating_num = numbers.substr(floating_position, numbers.length());
		string right_floating_num = rhs.numbers.substr(rhs.floating_position, rhs.numbers.length());
		if (left_floating_num.length() > right_floating_num.length()) {
			right_floating_num.append(left_floating_num.length() - right_floating_num.length(), '0');
		}
		else {
			left_floating_num.append(right_floating_num.length() - left_floating_num.length(), '0');
		}
		string left = left_int_num + left_floating_num;
		string right = right_int_num + right_floating_num;

		bignum result = bignum(left) - bignum(right);
		result.floating_position = left_int_num.length();

		return result;
	}
	string left_string = numbers;
	string right_string = rhs.numbers;
	string result = "";
	if (numbers.length() > right_string.length()) {
		right_string.insert(0, numbers.length() - right_string.length(), '0');
	}
	else {
		left_string.insert(0, right_string.length() - numbers.length(), '0');
	}
	int length = left_string.length();
	int carry = 0;
	int left = 0;
	int* arr = new int[length];
	for (int i = length - 1; i >= 0; i--) {
		arr[i] = 0;
		arr[i] = left_string[i] - right_string[i];
		if (arr[i] != 0)
			left = arr[i];
	}
	result = "";
	if (left < 0) {
		result.insert(0, "-");
	}
	for (int i = 0; i < length; i++) {
		if (left < 0) {
			arr[i] *= -1;
			int j = i;
			while (arr[j] < 0) {
				arr[j] += 10;
				arr[--j]--;
			}
		}
		else {
			int j = i;
			while (arr[j] < 0) {
				arr[j] += 10;
				arr[--j]--;
			}
		}

	}
	for (size_t i = 0; i < length; i++) {
		result += to_string(arr[i]);
	}
	return bignum(result);

}

const bignum bignum::operator*(const bignum& rhs) {
	if (isFloating() || rhs.isFloating()) {
		//int part padding
		string left_int_num = numbers.substr(0, floating_position);
		string right_int_num = rhs.numbers.substr(0, rhs.floating_position);
		if (left_int_num.length() > right_int_num.length()) {
			right_int_num.insert(0, left_int_num.length() - right_int_num.length(), '0');
		}
		else {
			left_int_num.insert(0, right_int_num.length() - left_int_num.length(), '0');
		}

		//float part padding
		string left_floating_num = numbers.substr(floating_position, numbers.length());
		string right_floating_num = rhs.numbers.substr(rhs.floating_position, rhs.numbers.length());
		int result_floating_position = left_floating_num.length() + right_floating_num.length();
		string left = left_int_num + left_floating_num;
		string right = right_int_num + right_floating_num;

		bignum result = bignum(left) * bignum(right);
		result.floating_position = result.numbers.length() - result_floating_position;
		return result;
	}
	string str = "";
	str.insert(0, rhs.numbers.length() + numbers.length(), '0');
	bignum result(str);
	string line = "";
	int temp;
	int carry = 0;
	string padding = "";
	for (int i = rhs.numbers.length() - 1; i >= 0; i--) {
		for (int j = numbers.length() - 1; j >= 0; j--) {
			temp = (numbers[j] - '0') * (rhs.numbers[i] - '0') + carry;
			carry = temp / 10;
			temp %= 10;
			line.insert(0, to_string(temp));
		}
		if (carry)
			line.insert(0, to_string(carry));
		line += padding;
		result = result + bignum(line);
		line = "";
		carry = 0;
		padding += "0";
	}
	//strip redundant  0
	return result;
}

const bignum bignum::operator/(const bignum& rhs) {
	string left_string = numbers;
	string right_string = rhs.numbers;

	if (isFloating() || rhs.isFloating()) {
		int offset;
		if (left_string.length() - floating_position > right_string.length() - rhs.floating_position) {
			offset = (left_string.length() - floating_position - right_string.length() + rhs.floating_position);
		}
		else {
			offset = (right_string.length() - rhs.floating_position - left_string.length() + floating_position);
		}
		bignum left = (bignum(pow(10, offset)) * bignum(left_string));
		bignum right = (bignum(pow(10, offset)) * bignum(right_string));
		//return  left / right;
	}
	string quotient = "";
	bignum fraction;
	int count = 0;
	int length = 0;
	int floating_position = left_string.length();
	if (left_string.length() > right_string.length())
		length = left_string.length();
	else {
		length = right_string.length();
	}
	string padding = "";
	padding.insert(0, DIVISION_DECIMAL_PLACE, '0');
	left_string += padding;
	for (int i = 1, j = 1; i < length + DIVISION_DECIMAL_PLACE; i++, j++) {
		fraction = bignum(left_string.substr(0, j));
		//cout << "frac :"<<fraction << endl;
		if (fraction >= bignum(right_string)) {
			while (fraction >= bignum(right_string)) {
				fraction = fraction - bignum(right_string);
				count++;
				//cout << "faaaaaaarac :" << fraction << endl;
			}
			if (fraction.isNegtive()) {
				count--;
				fraction = fraction + bignum(right_string);
			}
			//cout << "frac :" << fraction << endl;
			//cout << "count:" <<count << endl;
			left_string = fraction.numbers + left_string.substr(j, left_string.length());
			//cout << "remaing" << left_string << endl;
			quotient += to_string(count);
			j = 1;
		}
		else {
			quotient += "0";
		}

		count = 0;
	}

	return bignum(quotient, floating_position);
}

bignum bignum::operator=(const bignum& rhs) {
	numbers = rhs.numbers;
	floating_position = rhs.floating_position;
	return *this;
}
bignum::bignum() :numbers(""), floating_position(0) {}
bignum::bignum(string input)
{
    if (input == "")
    {
        numbers = "0";
        floating_position = input.length();
    }
   

    if (input.find(".") != string::npos)
    {
        int floating_point = input.find(".");
        input = input.substr(0, input.find(".")) + input.substr(input.find(".") + 1, input.length());
        
            int i = input.length() - 1;
        for (; i > floating_point + 1; i--)
        {
            if (input[i] != '0')
                break;
        }
        input = input.substr(0, i + 1);
        i = 0;
        for (; i < floating_point - 1; i++)
        {
            if (input[i] != '0')
                break;
        }
        input = input.substr(i, input.length());
        numbers = input;
        floating_position = floating_point - i;
    }
    else
    {
        int i = 0;
        for (; i < input.length(); i++)
        {
            if (input[i] != '0')
                break;
        }
        numbers = input.substr(i, input.length());
        floating_position = numbers.length();
    }
    

ostream& operator<<(ostream& str, bignum rhs) {
	if (rhs.isFloating()) {
		if (rhs.isNegtive())
			str << (rhs.numbers.substr(0, rhs.floating_position + 1) + "." + rhs.numbers.substr(rhs.floating_position + 1, rhs.numbers.length()));
		else
			str << (rhs.numbers.substr(0, rhs.floating_position) + "." + rhs.numbers.substr(rhs.floating_position, rhs.numbers.length()));
	}
	else
		str << rhs.numbers;
	return str;
}

istream& operator>>(istream& str, bignum& rhs) {
	string tmp;
	str >> tmp;
	rhs = bignum(tmp);
	return str;
}
