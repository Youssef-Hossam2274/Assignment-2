// File: main.cpp
// Purpose: solve sheet1
// Author: Abdullah Saeed Alnami
// Section: All A
// ID: 20220705
// TA: Samar Sabry
// Date: 26 Oct 2023



#include <iostream>
#include <string>
#include <vector>
using namespace std;




//---------------------Q3-----------------------------------



vector<string> split(string target, string delimiter) {
    vector<string> result;

    while (true) {
        //----- for last value if there isn't delimiter after it then push it and break----
        if(target.find(delimiter) == string::npos) {
            result.push_back(target);
            break;
        }
        int pos = target.find(delimiter);
        result.push_back(target.substr(0, pos));
        target.erase(0, pos + delimiter.length());
    }
    return result;
}









int main() {

    cout << "----------------Q3--------------------" << endl;

    vector<string> test1 = split("10,20,30", ",");

    for (auto i: test1)
        cout << i << ' ';
    cout << endl;

    vector<string> test2 = split("do re mi fa so la ti do", " ");

    for (auto i: test2)
        cout << i << ' ';
    cout << endl;


}




