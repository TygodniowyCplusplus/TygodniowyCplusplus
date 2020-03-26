// RotateMatrix.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Rotate Matrix : Given an image represented by an NxN matrix,
//where each pixel in the image is 4 bytes, write a method to
//rotate the image by 90 degrees.

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

void rotateMatrix(vector<vector<int>>& vec) //O(n^2)
{
    if (vec.size() == 0 || vec.size() != vec[0].size())
        return;
    int n = vec.size();
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = vec[first][i]; // save top
            // left -> top 
            vec[first][i] = vec[last - offset][first];
            // bottom -> left 
            vec[last - offset][first] = 
                vec[last][last - offset];
            //right -> bottom
            vec[last][last - offset] = vec[i][last];
            // top -> right
            vec[i][last] = top; //right <- saved top 
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> vec{ { 11,12,13,14 }, { 21,22,23,24 }, 
        { 31,32,33,34 }, { 41,42,43,44 } };
    //vector<vector<int>> vec{ { 11,12,13 }, { 21,22,23 },
     //       { 31,32,33 } };
    for (auto iterRow = vec.begin(); iterRow != vec.end(); 
        ++iterRow)
    {
        for (auto iterCol = (*iterRow).begin(); iterCol != 
            (*iterRow).end(); ++iterCol)
        {
            cout << *iterCol << " ";
        }
        cout << endl;
    }
    cout << endl;
    rotateMatrix(vec);

    for (auto iterRow = vec.begin(); iterRow != vec.end(); 
        ++iterRow)
    {
        for (auto iterCol = (*iterRow).begin(); iterCol != 
            (*iterRow).end(); ++iterCol)
        {
            cout << *iterCol << " ";
        }
        cout << endl;
    }
    cout << endl;
}