// IsUnique.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Is Unique: Implement an algorithm to determine if a string has 
//all unique characters. What if you cannot use additional data 
//structures?

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

bool determinUnique(string str) //O(n)
{
    unordered_set<char> unOrdSet;
    for (int i = 0; i < str.size(); ++i)
    {
        if (!unOrdSet.insert(str[i]).second)
            return false;
    }
    return true;
}

//jeśli jest to ASCII to jest 128 znaków i można zrobić tablice 
//bool i tam jeśi będzie już true przy wpisywaniu to znaczy że
//nie jest uniq.
//przy ASCII Extended jest 255 i też to można zrobić.

//bez bufora:
//* porównac każdy z każdym 0(n^2)
//* posortować O(n log n) i przececieć, czy nie ma identycznych obok siebie,
//ale przeważnie alg. sortujące maja jakis bufor.

int main()
{
    std::cout << "Hello World!\n";
    cout << determinUnique("arr") << endl;
}