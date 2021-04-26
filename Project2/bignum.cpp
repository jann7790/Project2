#pragma once
#include <string>
#include "bignum.h"
void bignum::input()
{
    cin >> numbers;
}
bignum bignum::operator+(const bignum& rhs)
{
    string left_string = numbers;
    string right_string = rhs.numbers;
    string result = "";
    if (numbers.length() > rhs.numbers.length())
    {
        right_string.insert(0, numbers.length() - right_string.length(), '0');
    }
    else
    {
        left_string.insert(0, right_string.length() - numbers.length(), '0');

    }
    int temp;
    int length = left_string.length();
    int carry = 0;
    for (size_t i = 0; i < length; i++)
    {
        temp = (right_string[length - i - 1] + left_string[length - i - 1]) - '0' - '0' + carry;
        carry = temp / 10;
        temp %= 10;
        result.insert(0, 1, temp + '0');
    }
    if (carry)
        result.insert(0, 1, carry + '0');

    return bignum(result);
}
bignum bignum::operator-(const bignum& rhs)
{
    string left_string = numbers;
    string right_string = rhs.numbers;
    string result = "";
    if (numbers.length() > right_string.length())
    {
        right_string.insert(0, numbers.length() - right_string.length(), '0');
    }
    else
    {
        left_string.insert(0, right_string.length() - numbers.length(), '0');
    }
    int length = left_string.length();
    int carry = 0;
    int left = 0;
    int* arr = new int[length];
    for (int i = length - 1; i >= 0; i--)
    {
        arr[i] = 0;
        arr[i] = left_string[i] - right_string[i];
        if (arr[i] != 0)
            left = arr[i];
    }
    result = "";
    if (left < 0)
    {
        result.insert(0, "-");
    }
    for (int i = 0; i < length; i++)
    {
        if (left < 0)
        {
            arr[i] *= -1;
            if (arr[i] < 0)
            {
                arr[i] += 10;
                arr[i - 1]--;
            }
        }
        else
        {
            if (arr[i] < 0)
            {
                arr[i] += 10;
                arr[i - 1]--;
            }
        }

    }
    for (size_t i = 0; i < length; i++)
    {
        result += to_string(arr[i]);
    }
    return bignum(result);

}
bignum bignum::operator*(const bignum& rhs)
{
    string str = "";
    str.insert(0, rhs.numbers.length() + numbers.length(), '0');
    bignum result(str);
    string line = "";
    int temp;
    int carry = 0;
    string padding = "";
    for (int i = rhs.numbers.length() - 1; i >= 0; i--)
    {
        
        for (int j = numbers.length() - 1 ; j >= 0; j--)
        {
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
    return result;
}
bignum bignum::operator/(const bignum& rhs)
{
    return *this;

}
bignum bignum::operator=(const bignum& rhs)
{
    numbers = rhs.numbers;
    return *this;
}

ostream& operator<<(ostream& str, bignum rhs)
{
    str << rhs.numbers;
    return str;
}
istream& operator>>(istream& str, bignum& rhs)
{
    str >> rhs.numbers;
    return str;
}
