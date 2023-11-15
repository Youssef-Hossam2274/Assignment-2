// File: main.cpp
// Purpose: solve sheet1
// Author: Abdullah Saeed Alnami
// Section: All A
// ID: 20220705
// TA: Samar Sabry
// Date: 26 Oct 2023



#include <iostream>
#include <queue>
using namespace std;





//------------------------Q9--------------------------------------

class game {
private:
    queue<int> qu;

    void bear1() {
        if (qu.empty()) {
            cout << "false\n";
            return;
        }
        int node = qu.front();
        qu.pop();

        if (node == 42) {
            cout << "true\n";
            while (!qu.empty())
                qu.pop();  // to reuse the game with the same obj
            return;
        }

        if (node % 2 == 0 && node / 2 >= 42) {
            qu.push(node / 2);
        }

        if (node % 5 == 0 && node - 42 >= 42) {
            qu.push(node - 42);
        }

        if (node % 4 == 0 || node % 3 == 0) {
            int lastTowDigit = (node % 10) * ((node % 100) / 10);
            if (lastTowDigit != 0 && node - lastTowDigit >= 42) {
                qu.push(node - lastTowDigit);
            }
        }
        bear1();
    }

public:
    void bear(int n) {
        qu.push(n);
        bear1();
    }
};






int main() {

    cout << "----------------Q9--------------------" << endl;
    game g1;
    g1.bear(250);
    g1.bear(42);
    g1.bear(84);
    g1.bear(53);
    g1.bear(41);

}




