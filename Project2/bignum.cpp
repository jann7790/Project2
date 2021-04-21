#include "bignum.h"
void bignum::input(string& input)
{
    numbers = input;
}
bignum& bignum::operator+(bignum& rhs)
{
    if (numbers.length() > rhs.numbers.length())
    {
        numbers.insert(0, '0', numbers.length() - rhs.numbers.length());
    }
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
