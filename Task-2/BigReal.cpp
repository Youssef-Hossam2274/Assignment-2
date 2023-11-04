#include <iostream>
#include <algorithm>
#include <cassert>
#include "BigReal.h"

// Utilities Function

bool BigReal::isValidReal(string realNumber)
{
    bool one_decimal_dot= false; // flag to catch if more than one dot
        
        // handling 1st digit to equal (number or dot or a sign(+ or -))
    if (realNumber[0] == '+' || realNumber[0] == '-' || realNumber[0] == '.' || (realNumber[0] >= '0' && realNumber[0] <= '9')  ) { 
        if(realNumber[0] == '.'){one_decimal_dot = true;}

        for (int i = 1; i < realNumber.size(); i++) { // checking number digits after sign bit (if exist)
            if ((realNumber[i] <='9' && realNumber[i] >= '0')) {
                continue;
            } else if (realNumber[i] == '.' && !one_decimal_dot) {
                one_decimal_dot = true;
            } else {
                return false;
            }   
        }
        return true;
    }
    return false;
}
void BigReal::fill_zeros(BigReal&other) {

    int maxSize = max(digits_d.size(), other.digits_d.size());
    int minSize = min(digits_d.size(), other.digits_d.size());

    int numZeros = maxSize - minSize;

    if (other.digits_d.size() < digits_d.size())
        other.digits_d.insert(other.digits_d.begin(), numZeros, 0);
    else if (other.digits_d.size() > digits_d.size())
        digits_d.insert(digits_d.begin(), numZeros, 0);


    maxSize = max(digits_r.size(), other.digits_r.size());
    minSize = min(digits_r.size(), other.digits_r.size());
    numZeros = maxSize - minSize;

    if (other.digits_r.size() < digits_r.size()) {
        while (numZeros--)
            other.digits_r.push_back(0);

    } else if (other.digits_r.size() > digits_r.size()) {
        while (numZeros--)
            digits_r.push_back(0);
    }

}
void BigReal::ninesComplemet(BigReal &b) {
    for (int i = 0; i < b.digits_r.size(); ++i) {
        b.digits_r[i] = 9 - b.digits_r[i];
    }
    for (int i = 0; i < b.digits_d.size(); ++i) {
        b.digits_d[i] = 9 - b.digits_d[i];

    }
}

BigReal BigReal::add(BigReal other) {
    int maxSize = max(digits_d.size(), other.digits_d.size());
    BigReal res;
    res.digits_r.pop_back();
    int carry = 0;
    for (int i = 0; i < maxSize; ++i) {
        int sum = carry;
        if (i < digits_d.size())
            sum += digits_d[i];
        if (i < other.digits_d.size())
            sum += other.digits_d[i];
        res.digits_d.push_back(sum % 10);
        carry = sum / 10;
    }
    maxSize = max(digits_r.size(), other.digits_r.size());
    for (int i = 0; i < maxSize; ++i) {
        int sum = carry;
        if (i < digits_r.size())
            sum += digits_r[i];
        if (i < other.digits_r.size())
            sum += other.digits_r[i];
        res.digits_r.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0) res.digits_r.push_back(carry);
    return res;
}

BigReal BigReal::compare_two_values(BigReal num1, BigReal num2)
{
    if (num1.digits_r.size() < num2.digits_r.size())
        return num1;
    else if (num1.digits_r.size() > num2.digits_r.size())
        return num2;
    
    if (num1.digits_d.size() < num2.digits_d.size())
        return num1;
    else if (num1.digits_d.size() > num2.digits_d.size())
        return num2;
    
    for (int i = num1.digits_r.size()-1 ; i >= 0 ;--i)
        if (num1.digits_r[i] > num2.digits_r[i])
            return num2;
    
    for (int i = num1.digits_d.size()-1 ; i >= 0 ;--i)
        if (num1.digits_d[i] > num2.digits_d[i])
            return num2;
    
    return num1;
}

void BigReal::remove_zeros()
{
    while(digits_r.size() >= 1 && digits_r.back() == 0)
        digits_r.pop_back();
    
    reverse(digits_d.begin(), digits_d.end());

    while(!digits_d.empty() && digits_d.back() == 0)
        digits_d.pop_back();
    
    reverse(digits_d.begin(), digits_d.end());
    if (digits_r.empty())
        digits_r.push_back(0);
}

// Constructor Function

BigReal::BigReal(double realNumber)
{
    string real_number_str = to_string(realNumber);
    setNum(real_number_str);
}

BigReal::BigReal(string realNumber)
{
    setNum(realNumber);
}

BigReal::BigReal(const BigReal &other)
{
    this->digits_d = other.digits_d;
    this->digits_r = other.digits_r;
    this->sign = other.sign;
}

// setNum & SIZE Function

void BigReal::setNum(string realNumber)
{
    assert(isValidReal(realNumber));
    
    digits_d.clear();
    digits_r.clear();
    
    sign = '+';
    int start = 0;
    if (realNumber[0] == '-' || realNumber[0] == '+')
        sign = realNumber[0], start = 1;

    bool has_dot = false;
    for (int i = start ; i < realNumber.size() ; ++i)
    {
        if (realNumber[i] == '.')
        {
            has_dot = true;
            continue;
        }

        int digit = realNumber[i] - '0';
        if (has_dot)
            digits_d.push_back(digit);
        else
            digits_r.push_back(digit);
    }    
    reverse(digits_d.begin(), digits_d.end());     
    reverse(digits_r.begin(), digits_r.end());     

    remove_zeros();
}

int BigReal::SIZE()
{
    return (digits_d.size() + digits_r.size());
}

// Operators (+, -, =)

BigReal BigReal::operator+(BigReal &other) {
    BigReal res;
    fill_zeros(other);

    if (sign != other.sign) {
        if (other.sign == '-')
            ninesComplemet(other);
        else
            ninesComplemet(*this);

        res = this->add(other);
        if (this->SIZE() == res.SIZE()) {
            ninesComplemet(res);
            res.sign = '-';
        } else {
            res.digits_r.resize(res.digits_r.size() - 1);
            BigReal tmp;
            tmp.setNum(res.digits_d.empty() ? "+1" : "+.1");
            res = res.add(tmp);
            res.sign = '+';
        }

    } else {
        res = this->add(other);
        res.sign = sign;
    }

    res.remove_zeros();
    return res;
}
BigReal BigReal::operator-(BigReal &other) {

    other.sign = (other.sign == '-') ? '+' : '-';

    return *this + other;
}


BigReal BigReal::operator=(BigReal other) {
    if (this == &other)
        return *this;
    this->digits_r.clear();
    this->digits_d.clear();

    this->sign = other.sign;

    for (int i = 0; i < other.digits_r.size(); ++i)
        digits_r.push_back(other.digits_r[i]);

    for (int i = 0; i < other.digits_d.size(); ++i)
        digits_d.push_back(other.digits_d[i]);

    return *this;
}
// comparison operators (<, >, ==)

bool BigReal::operator<(BigReal anotherReal)
{
    if (sign == '+' && anotherReal.sign == '-')
        return false;
    else if (sign == '-' && anotherReal.sign == '+')
        return true;

    if (*this == anotherReal)
        return false;
    
    if (compare_two_values(*this, anotherReal) == *this)   // the value of *this is smallest
    {
        if (sign == '+')
            return true;
        else
            return false;
    }
    else   // the value of anotherReal is smallest
    {
        if (sign == '+')
            return false;
        else
            return true;
    } 

    return true;
}

bool BigReal::operator>(BigReal anotherReal)
{
    if (*this < anotherReal || *this == anotherReal)
        return false;
    return true;
}

bool BigReal::operator==(BigReal anotherReal)
{
    if (sign != anotherReal.sign)
        return false;
    if (digits_r.size() != anotherReal.digits_r.size())
        return false;
    if (digits_d.size() != anotherReal.digits_d.size())
        return false;

    for (int i = 0 ; i < digits_r.size() ; ++i)
        if (digits_r[i] != anotherReal.digits_r[i])
            return false;
    
    for (int i = 0 ; i < digits_d.size() ; ++i)
        if (digits_d[i] != anotherReal.digits_d[i])
            return false;
    
    return true;
}

// printing operator
ostream &operator<<(ostream &out, BigReal num)
{
    if (num.digits_d.empty() && num.digits_r.size() == 1 && num.digits_r[0] == 0)
    {
        out << 0;
        return out;
    }
    
    if (num.sign == '-')
        out << '-';
    
    for (int i = num.digits_r.size()-1 ; i >= 0; --i)
        out << num.digits_r[i];
    for (int i = num.digits_d.size()-1 ; i >= 0; --i)
    {
        if (i == num.digits_d.size()-1)
            out << '.';
        out << num.digits_d[i];
    }
    return out;
}