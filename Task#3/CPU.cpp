#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Utility.cpp"
#include "Memory.cpp"

using namespace std;

class CPU :public Memory {
protected:
    vector<string> Register;
    string instruction_Register = "";
    int program_counter; // intializing program counter to first command on the memory

public:

    CPU(string file_Address) : Memory(file_Address) {
        Register.resize(16);
        fill(Register.begin(), Register.end(), "00");
        program_counter = first_command();
    }

    string fetch(int program_counter_1) {
        //                        first tow hexa digits           second two hexa digits
        string fetched_string = adddress_cells[program_counter_1] + adddress_cells[program_counter_1 + 1];
        return fetched_string;
    }

    void excute(string instruction_Register) {
        char op = instruction_Register[0];


        string operand = instruction_Register.substr(1,3);

        int xy = htoi(instruction_Register.substr(2,2));
        int r = htoi(instruction_Register[1]);


        switch (op) {
            case '1':
                Register[r] = adddress_cells[xy];
                break;
            case '2':
                Register[r] = operand.substr(1);
                break;
            case '3':
                if (xy == 0)
                    cout << Register[r];
                else
                {
                    adddress_cells[xy] = Register[r];
                    cout << "mem" << itoh(xy) << ": " << adddress_cells[xy] << '\n';
                }
                break;
            case '4':
                Register[htoi(operand[2])] = Register[htoi(operand[1])];
                break;
            case '5':
                Register[r] = add(Register[htoi(operand[1])], Register[htoi(operand[2])]);
                break;
            case '7':
            case '8':
            case '9': {
                int num1 = htoi(Register[htoi(operand[1])]);
                int num2 = htoi(Register[htoi(operand[2])]);
                if (op == '7')
                    Register[r] = itoh(num1 | num2);
                else if (op == '8')
                    Register[r] = itoh(num1 & num2);
                else if (op == '9')
                    Register[r] = itoh(num1 ^ num2);
                break;
            }
            case 'A': {
                string tmp = Register[r];
                int x = htoi(operand);
                tmp = htob(tmp);
                while (x--) {
                    char c = tmp.size() - 1;
                    tmp.erase(tmp.size() - 1);
                    tmp.insert(tmp.begin(), c);
                }
                break;
            }
            case 'B':
                if (Register[0] == Register[r])
                    program_counter = htoi(operand.substr(1,2));
                break;
        }

    }
};