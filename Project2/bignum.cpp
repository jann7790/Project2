#pragma once
#include <string>
#include "bignum.h"
bool bignum::isNegtive()const
{
    if (numbers.find("-") != string::npos)
        return 1;
    return 0;

}
const bool operator==(const bignum& lhs, const bignum& rhs)
{
    if (lhs.numbers.length() == rhs.numbers.length())
    {
        for (size_t i = 0; i < lhs.numbers.length(); i++)
        {
            if (lhs.numbers[i] != rhs.numbers[i])
                return 0;
        }
        return 1;
    }
    return 0;
}

void bignum::input()
{
    cin >> numbers;
}
const bool operator>=(const bignum& lhs, const bignum& rhs)
{
    if (lhs < rhs)
        return 0;
    return 1;
}

const bool operator>(const bignum& lhs, const bignum& rhs)
{
    if (!lhs.isNegtive() && !rhs.isNegtive())
    {
        if (lhs.numbers.length() > rhs.numbers.length())
            return 1;
        if (lhs.numbers.length() < rhs.numbers.length())
            return 0;
        for (size_t i = 0; i < lhs.numbers.length(); i++)
        {
            if (lhs.numbers[i] > rhs.numbers[i])
                return 1;
            if (lhs.numbers[i] < rhs.numbers[i])
                return 0;
        }
    }
    else if (!lhs.isNegtive() && rhs.isNegtive())
    {
        return 1;
    }
    else if (lhs.isNegtive() && !rhs.isNegtive())
    {
        return 0;
    }
    else
    {
        if (lhs.numbers.length() > rhs.numbers.length())
            return 0;
        if (lhs.numbers.length() < rhs.numbers.length())
            return 1;
        for (size_t i = 1; i < lhs.numbers.length(); i++)
        {
            if (lhs.numbers[i] > rhs.numbers[i])
                return 0;
            if (lhs.numbers[i] < rhs.numbers[i])
                return 1;
        }
    }
    return 0;

    
}
const bool operator<(const bignum& lhs, const bignum& rhs)
{
    if (lhs > rhs || (lhs == rhs))
        return 0;
    return 1;
}
const bignum bignum::operator+(const bignum& rhs)
{
    if (isNegtive() && !rhs.isNegtive())
        return bignum(rhs) - bignum(numbers.substr(1, numbers.length()));
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
const bignum bignum::operator-(const bignum& rhs)
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
            int j = i;
            while (arr[j] < 0)
            {
                arr[j] += 10;
                arr[--j]--;
            }
        }
        else
        {
            int j = i;
            while (arr[j] < 0)
            {
                arr[j] += 10;
                arr[--j]--;
            }
        }

    }
    for (size_t i = 0; i < length; i++)
    {
        result += to_string(arr[i]);
    }
    return bignum(result);

}
const bignum bignum::operator*(const bignum& rhs)
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
const bignum bignum::operator/(const bignum& rhs)
{
    string left_string = numbers;
    string right_string = rhs.numbers;
    string quotient = "";
    bignum fraction;
    int count = 0;
    int length = 0;
    if (left_string.length() > right_string.length())
        length = left_string.length();
    else
    {
        length = right_string.length();
    }
    for (int i = 1; i <= length; i++)
    {
        fraction = bignum(left_string.substr(0, i));
        //cout << "frac :"<<fraction << endl;
        if (fraction >= bignum(right_string))
        {
            while (fraction >= bignum(right_string))
            {
                fraction = fraction - bignum(right_string);
                count++;
            //    cout << "faaaaaaarac :" << fraction << endl;
            }
            if (fraction.isNegtive())
            {
                count--;
                fraction = fraction + bignum(right_string);
            }
            //cout << "frac :" << fraction << endl;
            //cout << "count:" <<count << endl;
            left_string = fraction.numbers + left_string.substr(i, left_string.length());
            //cout << "remaing" << left_string << endl;
            quotient += to_string(count);
        }
        count = 0;
    }

    return bignum(quotient);

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
