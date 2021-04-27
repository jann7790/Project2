#pragma once
#include "bignum.h"
void bignum::input()
{
    cin >> numbers;
}
bignum& bignum::operator+(bignum& rhs)
{
    if (numbers.length() > rhs.numbers.length())
    {
        rhs.numbers.insert(0, numbers.length() - rhs.numbers.length(), '0');
    }
    else
    {
        numbers.insert(0, rhs.numbers.length() - numbers.length(), '0');

    }
    string result = "";
    int temp;
    int carry = 0;
    for (size_t i = 0; i < numbers.length(); i++)
    {
        temp = (rhs.numbers[numbers.length() - i - 1] + numbers[numbers.length() - i - 1]) - '0' - '0' + carry;
        carry = temp / 10;
        temp %= 10;
        result.insert(0, 1, temp + '0');
    }
    if (carry)
        result.insert(0, 1, carry + '0');
    numbers = result;
    return *this;
}

bignum& bignum::operator-(bignum& rhs)
{
    if (numbers.length() > rhs.numbers.length())
    {
        rhs.numbers.insert(0, numbers.length() - rhs.numbers.length(), '0');
    }
    else
    {
        numbers.insert(0, rhs.numbers.length() - numbers.length(), '0');

    }
    string result = "";
    int temp;
    int carry = 0;
    for (size_t i = 0; i < numbers.length(); i++)
    {
        temp = numbers[numbers.length() - i - 1] - rhs.numbers[numbers.length() - i - 1];
        if (temp < 0)
        {
            int j = i;
            while (j >= 0)
            {
                if (numbers[j] > 0)
                {
                    numbers[j] = numbers[j] - 1;
                    temp = 10 - temp;
                    break;
                }
            }
        }

        result.insert(0, 1, temp + '0');
    }
    numbers = result;
    return *this;
    //10003
    //01234
    //1-1-2-3-1
    //
    //10234
    //09876
    //    1-9-6-4-2
}
bignum& bignum::operator*(bignum& rhs)
{
    return *this;

}
bignum& bignum::operator/(bignum& rhs)
{
    return *this;

}
bignum& bignum::operator=(bignum& rhs)
{
    numbers = rhs.numbers;
    return *this;
}

ostream& operator<<(ostream& str, bignum& rhs)
{
    str << rhs.numbers;
    return str;
}
istream& operator>>(istream& str, bignum& rhs)
{
    str >> rhs.numbers;
    return str;
}
void bignum::stringHandle()
{
    stack<char> st;
    string str;
    for (auto x : numbers)
    {
        if (x == '(')
            st.push('(');
        else if (!st.empty() && x == ')')
        {
            if (x == ')')
                st.pop();
        }
    }
    if (st.empty())
        cout << "good";
    else
        cout << "fuck";
}
