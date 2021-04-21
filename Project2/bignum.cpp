#include "bignum.h"
void bignum::input()
{
    cin >> numbers;
}
bignum& bignum::operator+(bignum& rhs)
{
    if (numbers.length() > rhs.numbers.length())
    {
        numbers.insert(0, numbers.length() - rhs.numbers.length(), '0');
    }
    else
    {
        rhs.numbers.insert(0, rhs.numbers.length() - numbers.length(), '0');
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
    return *this;
}

bignum& bignum::operator-(bignum& rhs)
{
    return *this;

}
bignum& bignum::operator*(bignum& rhs)
{
    return *this;

}
bignum& bignum::operator/(bignum& rhs)
{
    return *this;

}
