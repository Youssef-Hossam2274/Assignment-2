// FCAI - OOP Programming - 2023 - Assignment 2- task 3
// Program Name: Vole Machine.cpp
// Last Modification Date:  19/10/2023
// Author1 and ID and Group:  Abdullah Saeed Alnami  20220705  bdallhsydalnmy@gmail.com Section 9
// Author2 and ID and Group:  Eslam Sayed Younus     20220495  eslam894408@gmail.com    Section 9
// Author3 and ID and Group:  Youssef Hossam Ahmed   20220390  y.hossam2274@gmail.com   Section 9
// Teaching Assistant: Samar Sabry Shaker

// Purpose: simulation for CPU and internal memory for a computer with basic functionality 

#include <iostream>
#include "Utility.cpp"
#include "Memory.cpp"
#include "CPU.cpp"
using namespace std;

class Machine: private CPU {
private:

public:
    Machine(string file_Address) : CPU(file_Address) {}

    void run() {
        while (instruction_Register != "C000") {
            instruction_Register = fetch(program_counter);
            program_counter += 2; // as it moves two lines for every instruction register
            cout << instruction_Register << ":\n";
            excute(instruction_Register);
            for (int i = 0 ; i < 16; ++i)
                cout << i << ' ' << Register[i] << '\n';
            cout << "---------------------------\n";
        }
    }
};

int main()
{
    Machine MY_MACHINE("Main Memory.txt");    
    MY_MACHINE.run();
    return 0;
}