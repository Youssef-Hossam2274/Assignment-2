#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num1("0022654.9232320000");
    BigReal num2 ("0.0");

    cout << (num2 + num1);

    return 0;
}