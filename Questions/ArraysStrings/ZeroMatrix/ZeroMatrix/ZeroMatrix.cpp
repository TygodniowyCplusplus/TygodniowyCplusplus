// ZeroMatrix.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Zero Matrix: Write an algorithm such that if an element in 
//an MxN matrix is 0, its entire row and column are set to 0.
// 1 1 1 1
// 1 1 1 1
// 0 1 0 1

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

void matrix0(vector<vector<int>>& vec) //O(n^2)
{
    if (vec.size() == 0)
        return;
    if (vec[0].size() == 0)
        return;
    for (int row = 1; row < vec.size(); ++row)
    {
        if (vec[row].size() != vec[0].size())
            return;
    }
    bool rowHasZero = false;
    bool colHasZero = false;

    for (int i = 0; i < vec[0].size(); ++i)
    {
        if (vec[0][i] == 0)
        {
            rowHasZero = true;
            break;
        }
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i][0] == 0)
        {
            colHasZero = true;
            break;
        }
    }

    for (int i = 1; i < vec.size(); ++i)
    {
        for (int j = 1; j < vec[0].size(); ++j)
        {
            if (vec[i][j] == 0)
            {
                vec[i][0] = 0;
                vec[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i][0] == 0)
        {
            for (int j = 1; j < vec[0].size(); ++j)
            {
                vec[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < vec[0].size(); ++i)
    {
        if (vec[0][i] == 0)
        {
            for (int j = 1; j < vec.size(); ++j)
            {
                vec[j][i] = 0;
            }
        }
    }

    if (rowHasZero == true)
    {
        for (int i = 0; i < vec[0].size(); ++i)
        {
            vec[0][i] = 0;
        }
    }
    if (colHasZero == true)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i][0] = 0;
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> vec{ { 11,12,13,00 }, { 21,0,23,24 },
        { 31,32,33,34 }, { 41,42,0,44 } };
    for (auto iterRow = vec.begin(); iterRow != vec.end(); 
        ++iterRow)
    {
        for (auto iterCol = (*iterRow).begin(); 
            iterCol != (*iterRow).end(); ++iterCol)
        {
            if(*iterCol == 0)
                cout << "00" << " ";
            else
                cout << *iterCol << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix0(vec);

    for (auto iterRow = vec.begin(); iterRow != vec.end(); 
        ++iterRow)
    {
        for (auto iterCol = (*iterRow).begin(); 
            iterCol != (*iterRow).end(); ++iterCol)
        {
            if (*iterCol == 0)
                cout << "00" << " ";
            else
                cout << *iterCol << " ";
        }
        cout << endl;
    }
    cout << endl;
}