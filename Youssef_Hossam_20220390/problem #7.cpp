// File: problem #7.cpp
// Purpose: verify to build a connected of dominos in correct way.
// Author: Youssef Hossam.
// Section: S9/S10.
// ID: 20220390
// TA: Samar Sabry Shaker
// Date: 27 Oct 2023

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

GRAPH build(vector<pair<int,int>> &dominos)
{
    GRAPH mapp;
    for (int i = 0 ; i < dominos.size() ; ++i)
    {
        mapp[i+1] = {};
        for (int j = 0 ; j < dominos.size() ; ++j)
            if (dominos[j].first == dominos[i].second && i != j)
                mapp[i+1].push_back(j+1);
    }
    return mapp;
}

bool dfs(GRAPH graph, int start, vector<int> &visited)
{
    visited.push_back(start);

    if (visited.size() == graph.size())
        return true;

    if (graph[start].empty())
        return false;
    
    for (int i : graph[start])
        if(!dfs(graph, i, visited))
            visited.pop_back();
    
    return (visited.size() == graph.size());
}

bool FormsDominoChain(vector<pair<int, int>> &dominos)
{
    GRAPH graph = build(dominos);
    for (int i = 1 ; i <= dominos.size() ; ++i)
    {
        vector<int> visited;
        if (dfs(graph, i, visited))
        {
            for (int i = 0 ; i < visited.size() ;++i)
            {
                if (i)
                    cout << " - ";
                int idx = visited[i];
                cout << dominos[idx-1].first << '|' << dominos[idx-1].second;
            }
            cout << '\n';
            return true;
        }
    }
    return false;
}

int main()
{
    vector <pair<int,int>> vec {{1,4},{2,6},{4,3},{6,1},{4,4}};
    cout << FormsDominoChain(vec);
    return 0;
}