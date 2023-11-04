#ifndef BIGREAL_H
#define BIGREAL_H

#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BigReal
{
private:
    vector<int> digits_d;
    vector<int> digits_r;
    char sign;
    
    // utility function
    bool isValidReal(string realNumber); 
    void fill_zeros(BigReal&other);
    void ninesComplemet(BigReal &b);
    BigReal add(BigReal other);
    BigReal compare_two_values(BigReal num1, BigReal num2);
    void remove_zeros();

public:
    BigReal(double realNumber = 0.0); 
    BigReal(string realNumber);      
    BigReal(const BigReal &other);    

    void setNum(string realNumber);
    int SIZE();
    
    BigReal operator=(BigReal other);
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);

    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    friend ostream &operator<<(ostream &out, BigReal num);
};

#endif