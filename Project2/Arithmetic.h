#pragma once
#include<iostream>
using namespace std;

string add(string, string);
string subtract(string, string);
string multiply(string, string);
string divide(string, string);
bool is_floationg(string&, string&);
void hi(string&);
int is_floating_for_M(string&, string&);
void hi_M(string&, int);
bool is_floating_for_div(string&, string&);
void hi_div(string&);

int trans(char ch)
{
    return static_cast<int>(ch) - static_cast<int>('0');
}

char trans(int num)
{
    return static_cast<char>(num + static_cast<int>('0'));
}

int is_negative(string& m, string& n) // 1:++ 2:+- 3:-+ 4:--
{
    if (m[0] == '-' && n[0] == '-')
    {
        string real_m = "", real_n = "";
        for (int i = 1; i < m.length(); ++i)
        {
            real_m += m[i];
        }
        for (int i = 1; i < n.length(); ++i)
        {
            real_n += n[i];
        }
        m = real_m;
        n = real_n;
        return 4;
    }
    else if (m[0] != '-' && n[0] == '-')
    {
        string real_n = "";
        for (int i = 1; i < n.length(); ++i)
        {
            real_n += n[i];
        }
        n = real_n;
        return 2;
    }
    else if (m[0] == '-' && n[0] != '-')
    {
        string real_m = "";
        for (int i = 1; i < m.length(); ++i)
        {
            real_m += m[i];
        }
        m = real_m;
        return 3;
    }
    return 1;
}

bool compare(string m, string n)
{
    bool m_greater = true;
    if (m.length() < n.length())
    {
        m_greater = false;
    }
    else if (m.length() == n.length())
    {
        for (int i = 0; i < m.length(); ++i)
        {
            if (m[i] == n[i])
            {
                continue;
            }
            else if (m[i] < n[i])
            {
                m_greater = false;
                break;
            }
            else
            {
                break;
            }
        }
    }

    return m_greater;
}

void max(string& m, string& n)
{
    if (compare(n, m))
    {
        string temp = m;
        m = n;
        n = temp;
    }
    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());
}

string add(string m, string n)
{
    int situation = is_negative(m, n);

    string ans = "";
    if (situation == 4)
    {
        ans = "-";
        ans += add(m, n);
        return ans;
    }
    else if (situation == 3)
    {
        ans = subtract(n, m);
        return ans;
    }
    else if (situation == 2)
    {
        ans = subtract(m, n);
        return ans;
    }
    else
    {
        bool is_floating = is_floationg(m, n);
        max(m, n);
        int carry = 0;
        for (int i = 0; i < n.length(); ++i)
        {
            int temp = trans(n[i]) + trans(m[i]) + carry;
            carry = 0;
            if (temp < 10)
            {
                ans += trans(temp);
            }
            else
            {
                ans += trans(temp % 10);
                carry = temp / 10;
            }
        }
        for (int i = n.length(); i < m.length(); ++i)
        {
            int temp = trans(m[i]) + carry;
            carry = 0;
            if (temp < 10)
            {
                ans += trans(temp);
            }
            else
            {
                ans += trans(temp - 10);
                carry = 1;
            }
        }
        if (carry != 0)  ans += trans(carry);
        reverse(ans.begin(), ans.end());
        if (!is_floating)
        {
            return ans;
        }
        else
        {
            ans.insert(ans.size() - 100, ".");
            return ans;
        }
    }
}

string subtract(string m, string n)
{
    if (m == n)  return "0";
    string ans = "";
    int situation = is_negative(m, n);
    if (situation == 4)
    {
        ans = subtract(n, m);
        return ans;
    }
    else if (situation == 3)
    {
        ans = "-";
        ans += add(m, n);
        return ans;
    }
    else if (situation == 2)
    {
        ans = add(m, n);
        return ans;
    }
    else
    {
        bool is_floating = is_floationg(m, n);
        bool negative = compare(n, m);
        max(m, n);
        int borrow = 0;
        for (int i = 0; i < n.length(); ++i)
        {
            int temp = trans(m[i]) - trans(n[i]) - borrow;
            borrow = 0;
            if (temp >= 0)
            {
                ans += trans(temp);
            }
            else
            {
                ans += trans(temp + 10);
                borrow = 1;
            }
        }
        for (int i = n.length(); i < m.length(); ++i)
        {
            int temp = trans(m[i]) - borrow;
            borrow = 0;
            if (temp >= 0)
            {
                ans += trans(temp);
            }
            else
            {
                ans += trans(temp + 10);
                borrow = 1;
            }
        }
        int node = ans.length() - 1;
        string real_ans = "";
        for (int i = ans.length() - 1; i >= 0; --i)
        {
            if (ans[i] != '0')
            {
                node = i;
                break;
            }
        }
        if (node != ans.length() - 1)
        {
            for (int i = 0; i <= node; ++i)
            {
                real_ans += ans[i];
            }
        }

        else
        {
            real_ans += ans;
        }
        if (negative)
        {
            real_ans += '-';
        }
        reverse(real_ans.begin(), real_ans.end());

        if (!is_floating)
        {
            return real_ans;
        }
        else
        {

            hi(real_ans);
            return real_ans;

        }
    }
}

string multiply(string m, string n)
{

    int situation = is_negative(m, n);
    string ans = "0";
    if (situation == 2 || situation == 3)
    {
        if (multiply(m, n) == "0")
        {
            ans = multiply(m, n);
            return ans;
        }
        else
        {
            ans = "-";
            ans += multiply(m, n);
            return ans;
        }

    }
    int is_floating = is_floating_for_M(m, n);
    max(m, n);
    for (int i = 0; i < n.length(); ++i)
    {
        string temp = "";
        int carry = 0;
        for (int j = 0; j < m.length(); ++j)
        {
            int now = trans(n[i]) * trans(m[j]) + carry;
            carry = 0;
            if (now < 10)
            {
                temp += trans(now);
            }
            else
            {
                temp += trans(now % 10);
                carry = now / 10;
            }
        }
        if (carry != 0)
        {
            temp += trans(carry);
        }
        reverse(temp.begin(), temp.end());

        for (int j = 0; j < i; ++j)
        {
            temp += "0";
        }
        ans = add(ans, temp);
    }
    if (is_floating == 0)
    {
        return ans;
    }
    else
    {
        hi_M(ans, is_floating);
        return ans;
    }
}

string divide(string m, string n)
{
    int situation = is_negative(m, n);
    string quotient = "";
    string remainder = m;

    if (situation == 2 || situation == 3)
    {
        if (divide(m, n) == "0")
        {
            quotient = divide(m, n);
            return quotient;
        }
        else
        {
            quotient = "-";
            quotient += divide(m, n);
            return quotient;
        }
    }
    bool is_floating = is_floating_for_div(m, n);

    bool normal = compare(m, n);
    if (!normal)
    {
        quotient = "0";
    }
    else
    {
        for (int i = m.length() - n.length(); i >= 0; --i)
        {
            string temp = n;
            for (int j = 0; j < i; ++j)
            {
                temp += "0";
            }
            if (compare(remainder, temp))
            {
                string last = temp;
                for (int j = 2; j <= 10; ++j)
                {
                    string q = "";
                    q += trans(j);
                    string mul = multiply(temp, q);
                    if (compare(mul, remainder))
                    {
                        remainder = subtract(remainder, last);
                        quotient += trans(j - 1);
                        break;
                    }
                    last = mul;
                }
            }
            else
            {
                if (i != m.length() - n.length())    quotient += "0";
            }
        }
    }
    if (!is_floating)
    {
        return quotient;
    }
    else
    {
        hi_div(quotient);
        return quotient;
    }
}




int main()
{
    string a, b;
    /*cin >> a >> b;
    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << subtract(a, b) << endl;
    cout << "a * b = " << multiply(a, b) << endl;
    cout << "a / b =" << divide(a, b) << endl;
    */
    while (cin >> a >> b)
    {
        cout << "a + b = " << add(a, b) << endl;
        cout << "a - b = " << subtract(a, b) << endl;
        cout << "a * b = " << multiply(a, b) << endl;
        // cout << "a / b = " << divide(a, b) << endl;
    }
}
//判斷是否為小數(for 加減)
bool is_floationg(string& m, string& n)
{
    bool isFloating = false;
    int pointPosM = m.find(".");
    int pointPosN = n.find(".");
    if (pointPosM != std::string::npos || pointPosN != std::string::npos)
    {

        if (pointPosM != std::string::npos)
        {
            int sizeM = m.size();
            for (int i = 0; i < 100 - (sizeM - pointPosM - 1); i++)
            {
                m += "0";
            }
            m.erase(m.begin() + pointPosM);
        }
        else
        {
            for (int i = 0; i < 100; i++)
            {
                m += "0";
            }
        }
        if (pointPosN != std::string::npos)
        {
            int sizeN = n.size();
            for (int i = 0; i < 100 - (sizeN - pointPosN - 1); i++)
            {
                n += "0";
            }
            n.erase(n.begin() + pointPosN);
        }
        else
        {
            for (int i = 0; i < 100; i++)
            {
                n += "0";
            }
        }
        return true;
    }
    return false;
}
void hi(string& result)
{
    if (result[0] == '-')
    {
        if (result.size() - 1 < 100)
        {
            int sizeR = result.size() - 1;
            for (int i = 0; i < 100 - sizeR; i++)
            {
                result.insert(1, "0");
            }
            result.insert(1, "0.");
        }
        else if (result.size() - 1 == 100)
        {
            result.insert(1, "0.");
        }
        else
        {
            result.insert(result.size() - 100, ".");
        }
    }
    else
    {
        if (result.size() < 100)
        {
            int sizeR = result.size();
            for (int i = 0; i < 100 - sizeR; i++)
            {
                result.insert(0, "0");
            }
            result.insert(0, "0.");
        }
        else if (result.size() == 100)
        {
            result.insert(0, "0.");
        }
        else
        {
            result.insert(result.size() - 100, ".");
        }
    }
}

int is_floating_for_M(string& m, string& n)
{
    int resultPointPos = 0;
    int pointPosM = m.find(".");
    int pointPosN = n.find(".");
    if (pointPosM != std::string::npos || pointPosN != std::string::npos)
    {
        if (pointPosM != std::string::npos)
        {
            int sizeM = m.size();
            m.erase(m.begin() + pointPosM);
            resultPointPos = sizeM - pointPosM - 1;
        }
        if (pointPosN != std::string::npos)
        {
            int sizeN = n.size();
            n.erase(n.begin() + pointPosN);
            resultPointPos += sizeN - pointPosN - 1;
        }
        return resultPointPos;
    }
    return 0;
}
void hi_M(string& result, int pointPos)
{
    result.insert(result.size() - pointPos, ".");
    for (int i = 0; i < 100 - pointPos; i++)
    {
        result += "0";
    }
}
bool is_floating_for_div(string& m, string& n)
{
    int pointPosM = m.find(".");
    int pointPosN = n.find(".");
    int shift_point = 0;
    if (pointPosM != std::string::npos || pointPosN != std::string::npos)
    {
        if (pointPosN != std::string::npos)
        {
            shift_point = n.size() - pointPosN - 1;
            n.erase(n.begin() + pointPosN);
        }
        if (pointPosM != std::string::npos)
        {
            int m_decimal = m.size() - pointPosM - 1;
            m.erase(m.begin() + pointPosM);
            for (int i = m_decimal; i < shift_point; i++)
            {
                m += "0";
            }
        }
        else
        {

            for (int i = 0; i < shift_point; i++)
            {
                m += "0";
            }
        }
        for (int i = 0; i < 100; i++)
        {
            m += "0";
        }
        return true;
    }
    return false;
}
void hi_div(string& result)
{
    result.insert(result.size() - 100, ".");
}