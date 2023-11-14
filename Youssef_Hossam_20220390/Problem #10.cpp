#include <iostream>
#include <istream>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

void build_lookUpTable(unordered_map<string, string>& table, string file_name)
{
    fstream file_handle(file_name.c_str());
    if (file_handle.fail())
        cout << "something is error in build_lookUpTable\n";
    string line;
    while (getline(file_handle, line))
    {
        int idx = line.find(" ");
        string s1 = line.substr(0, idx);
        string s2 = line.substr(idx + 1);
        table[s1] = s2;
    }
}

vector <string> SplitLine(string line)
{
    vector<string> details;
    string substr;

    while (line.find(" ") != -1)
    {
        int pos = line.find(" ");
        substr = line.substr(0, pos);
        details.push_back(substr);
        line.erase(0, pos + 1);
    }
    details.push_back(line);
    return details;
}

void build_txt(vector<vector<string>>& content, string file_name)
{
    fstream file_handle(file_name.c_str());
    if (file_handle.fail())
        cout << "something is error in build_txt\n";

    string line;
    while (getline(file_handle, line))
        content.push_back(SplitLine(line));
}

void Alternative_save(vector<vector<string>>& content, unordered_map<string, string>& table, string file_name)
{
    fstream file_handle(file_name.c_str());
    if (file_handle.fail())
        cout << "something is error in Alternative_save\n";

    for (int i = 0; i < content.size(); ++i)
        for (int j = 0; j < content[i].size(); ++j)
            if (table.count(content[i][j]))
                content[i][j] = table[content[i][j]];

    file_handle.clear();

    for (int i = 0; i < content.size(); ++i)
    {
        for (int j = 0; j < content[i].size(); ++j)
            file_handle << content[i][j] << ' ';
        file_handle << '\n';
    }
}

int main()
{
    unordered_map<string, string> table;
    vector<vector<string>> content;
    build_lookUpTable(table, "look up table.txt");
    build_txt(content, "text.txt");
    Alternative_save(content, table, "text.txt");
    return 0;
}