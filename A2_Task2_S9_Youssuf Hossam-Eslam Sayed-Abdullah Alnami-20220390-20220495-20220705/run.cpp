// FCAI - OOP Programming - 2023 - Assignment 2
// Program Name: BigReal Data Type.cpp
// Last Modification Date:  19/10/2023
// Author1 and ID and Group:  Abdullah Saeed Alnami  20220705  bdallhsydalnmy@gmail.com Section 9
// Author2 and ID and Group:  Eslam Sayed Younus     20220495  eslam894408@gmail.com    Section 9
// Author3 and ID and Group:  Youssef Hossam Ahmed   20220390  y.hossam2274@gmail.com   Section 9
// Teaching Assistant: Samar Sabry Shaker

// Purpose: Making a data type called Bigreal which can sotre and make different operations
// on large values that c++ standard data types for numbers can do

#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num1("0022654.9232320000");
    BigReal num2("0.0");

    cout << (num2 + num1);

    return 0;
}
