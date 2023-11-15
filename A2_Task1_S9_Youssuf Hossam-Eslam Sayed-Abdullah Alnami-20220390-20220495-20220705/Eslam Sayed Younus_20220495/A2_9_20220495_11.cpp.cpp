#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string file_1_name, file_2_name, line_1, line_2, word_1, word_2 ;
char character_1, character_2;

int line_counter = 0;
fstream file_handler_1, file_handler_2;

char COMMAND;

void menu() {
    cout << "Enter the name of the first file: ";
    cin >> file_1_name;
    cout << "Enter the name of the second file: ";
    cin >> file_2_name;

    file_handler_1.open(file_1_name.c_str());
    file_handler_2.open(file_2_name.c_str());

    if (file_handler_1.fail()) {
        cout << "Can't open file_1\n";
        exit(1);  // Exit the program if file_1 fails to open
    }
    else if (file_handler_2.fail()) {
        cout << "Can't open file_2\n";
        exit(1);  // Exit the program if file_1 fails to open
    }

    cout << "Enter 'w' if you want to compare word by word\nEnter 'c' if you want to compare character by character\n";
    cin >> COMMAND;
}

void Read_line_by_line() {
     
    while (getline(file_handler_1, line_1) && getline(file_handler_2, line_2)) {
        ++line_counter;
        stringstream ss_1(line_1);
        stringstream ss_2(line_2);

        while (ss_1 >> word_1 && ss_2 >> word_2) {
            if (word_1 == word_2) {
                continue;
            } else {
                cout << "There is a difference in line: " << line_counter << " between " << word_1 << " and " << word_2 << endl;
                return;
                
            }
            
        }
        
    }
    cout << "The two files are identical\n"; 
}

void character_by_character() {
    while (getline(file_handler_1, line_1) && getline(file_handler_2, line_2)) {
        ++line_counter;
        stringstream ss_1(line_1);
        stringstream ss_2(line_2);

        while (ss_1.get(character_1) && ss_2.get(character_2)) {
            if (character_1 == character_2) {
                continue;

            } else {
                cout << "There is a difference in line: " << line_counter << endl;
                cout << "line 1:" << line_1 << endl;
                cout << "line 2:" << line_2 << endl;
                return;
            }
            
        }
    }
        cout << "The two files are identical\n";
}

int main() {
    menu();

    switch (COMMAND) {
        case 'w':
            Read_line_by_line();
            break;

        case 'c':
            character_by_character();
            break;

        case 'e':
            break;

        default:
            cout << "Enter a valid command, and make sure that the character is in lowercase.\n";
            menu();
            break;
    }
    

    // Close the file handlers before exiting
    file_handler_1.close();
    file_handler_2.close();

    return 0;
}

