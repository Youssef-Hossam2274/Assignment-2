// File: main.cpp
// Purpose: solve sheet1
// Author: Abdullah Saeed Alnami
// Section: All A
// ID: 20220705
// TA: Samar Sabry
// Date: 26 Oct 2023



#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <fstream>
using namespace std;



//------------------------Q12--------------------------------------
void phishingScanner() {
    ifstream phishingScannerWords("PhishingScannerWords.txt");
    ifstream fileText("text.txt");

    map<string, int> wordsCount;
    map<string, int> wordsPoint;
    string word;
    int totalPoints = 0;

    while (getline(phishingScannerWords, word)) {
        wordsPoint[word.substr(1)] = word[0] - '0';
    }

    string text;
    while (fileText >> text) {
        if (wordsPoint.count(text)) {
            if (wordsCount.count(text))
                wordsCount[text]++;
            else
                wordsCount[text] = 1;
            totalPoints++;
        }
    }

    for (auto i: wordsCount) {
        cout << i.first << " cont: " << i.second << " points: " << wordsPoint[i.first] << endl;
    }

    cout << "total_points: " << totalPoints << endl;

    phishingScannerWords.close();
    fileText.close();
}








int main() {

    cout << "----------------Q12--------------------" << endl;
    phishingScanner();

}



