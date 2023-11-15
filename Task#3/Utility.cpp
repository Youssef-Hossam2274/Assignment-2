#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

int htoi(string number)
{
    int num = 0;
    for (int i = 0 ; i < number.size() ; ++i)
    {
        if (number[i] >= 'A' && number[i] <= 'F')
            num += (number[i]-'A'+10)*pow(16, number.size()-i-1);
        else
            num += (number[i] - '0')*pow(16, number.size()-i-1);
    }
    return num;
}

string itoh(int number)
{
    string num = "";
    for ( ; number ; number/=16)
    {
        int tmp = number % 16;
        if (tmp < 10)
            num += tmp + 48;
        else
            num += tmp + 55;
    }
    while(num.size() < 2)
        num.push_back('0');
    reverse(num.begin(), num.end());
    return num;
}

int htoi(char ch) {
    return (ch >= 'A' && ch <= 'F') ? ch - 55 :
           ch - '0';
}

string add(string s1,string s2) {
    string res = itoh(htoi(s1) + htoi(s2));
    // avoiding the carry bit after the addition because we are dealing with tow's complement addition
    if(res.size() > 2)
        res = res.substr(1,2);
    return (res);

}

string htob(string num) {
    string res = "";
    res += bitset<32>(htoi(num[0])).to_string().substr(32 - 4);
    res += bitset<32>(htoi(num[1])).to_string().substr(32 - 4);
    return res;
}