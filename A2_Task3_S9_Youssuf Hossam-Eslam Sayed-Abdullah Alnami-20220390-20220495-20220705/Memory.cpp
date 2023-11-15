#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Utility.cpp"
#pragma once
using namespace std;

class Memory {
protected:
    vector<string> adddress_cells;
    int first_command(){  // getting first command on the memory
        for (int i = 0; i < adddress_cells.size(); i++) {
            if (adddress_cells[i] != "00") {
                return i;
            }
        }
        return -1;
    }

public:
    Memory(string file_Address)
    {
       adddress_cells.resize(256);
       fill(adddress_cells.begin(), adddress_cells.end(), "00");

       fstream file_handle (file_Address.c_str());
       if (file_handle.fail())
           cout << "something is error in Memory.\n";
       string line;
       while(getline(file_handle, line))
       {
           string address = line.substr(0, 2);
           string content = line.substr(3);
           int idx = htoi(address);
           adddress_cells[idx] = content;
       }
    }

    void print_memory_details()
    {
        for (int i = 0 ; i < adddress_cells.size() ;++i)
            if (adddress_cells[i].size())
                cout << i << ' ' << adddress_cells[i] << '\n';
    }
};