// File: problem #1.cpp 
// Purpose: to make between each two blank one space and all character to be lower and the first character in sentece to be a upper.  
// Author: Youssef Hossam. 
// Section: S9/S10. 
// ID: 20220390 
// TA: Samar Sabry Shaker
// Date: 26 Oct 2023

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{

    string sentence, word;
    getline(cin, sentence, '.');
    sentence += '.';
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    sentence[0] = toupper(sentence[0]);

    istringstream iss(sentence);
    while (iss >> word)
        cout << word << ' ';

    return 0;
}