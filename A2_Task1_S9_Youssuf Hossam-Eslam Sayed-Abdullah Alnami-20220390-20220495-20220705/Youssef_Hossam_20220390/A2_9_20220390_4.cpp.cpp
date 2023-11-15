// File: problem #4.cpp 
// Purpose: List a prime number between (2,N) in Eratosthenes algorithm.  
// Author: Youssef Hossam. 
// Section: S9/S10. 
// ID: 20220390 
// TA: Samar Sabry Shaker
// Date: 26 Oct 2023

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    unordered_set<int> nums;
    int n;
    cin >> n;
    for (int i = 2; i < n; ++i)
        nums.insert(i);

    for (int i = 2; i < n; ++i)
    {
        vector<int> removed;
        if (nums.count(i))
        {
            cout << i << ' ';
            nums.erase(i);
            for (auto it : nums)
                if (it % i == 0)
                    removed.push_back(it);

            for (int it : removed)
                nums.erase(it);
        }
    }

    return 0;
}