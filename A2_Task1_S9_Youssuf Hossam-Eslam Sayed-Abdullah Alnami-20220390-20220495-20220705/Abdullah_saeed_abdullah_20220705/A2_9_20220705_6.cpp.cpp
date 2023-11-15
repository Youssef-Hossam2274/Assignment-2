// File: main.cpp
// Purpose: solve sheet1
// Author: Abdullah Saeed Alnami
// Section: All A
// ID: 20220705
// TA: Samar Sabry
// Date: 26 Oct 2023



#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;




//---------------------Q6(a)-----------------------------------


class Binary {
public:
    static void binaryPrint(int n) {
        if (n == 0) {
            cout << '0';
            return;
        }

        if (n == 1) {
            cout << '1';
            return;
        }

        binaryPrint(n / 2);
        cout << (n % 2);
    }
};


//---------------------Q6(b)-----------------------------------
class prefix_num {
        static string ss;

        static void string_binary(int n) {
            if (n == 0) {
                ss += '0';
                return;
            }

            if (n == 1) {
                ss += '1';
                return;
            }

            string_binary(n / 2);
            if (n % 2 == 0)
                ss += "0";
            else
                ss += "1";
        }

    public:
        static void numbers(string prefix, int k) {
            for (int i = 0; i < pow(2, k); ++i) {
                cout << prefix;
                ss = "";
                string_binary(i);  //to change k into binary//
                string ans(k - ss.size(), '0');  //fill the least signiphant bits whith zeros//
                cout << ans + ss;
                cout << endl;
            }
        }


    };
string prefix_num::ss = "";



//-----------------------Q6(b) using bitset---------------------------------

class prefix_num2 {
private:
    static void numbersRecursive(string prefix, int k, int i) {
        if (i >= pow(2, k))
            return;

        string binary = bitset<32>(i).to_string().substr(32 - k);

        cout << prefix << binary << endl;

        numbersRecursive(prefix, k, i + 1);

    }

public:
    static void numbers(string prefix, int k) {
        numbersRecursive(prefix, k, 0);
    }

};








int main() {

    cout << "----------------Q6(a)--------------------" << endl;
    Binary b1;
    b1.binaryPrint(0);
    cout << endl;

    b1.binaryPrint(4);
    cout << endl;

    b1.binaryPrint(27);
    cout << endl;


    cout << "----------------Q6(b)--------------------" << endl;

    prefix_num test;
    test.numbers("00101", 2);

}




