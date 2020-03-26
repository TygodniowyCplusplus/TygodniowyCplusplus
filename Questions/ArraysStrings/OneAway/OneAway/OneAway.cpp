// OneAway.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//One Away: There are three types of edits that can be 
//performed on strings: insert a character, remove a 
//character, or replace a character. Given two strings, 
//write a function to check if they are one edit (or zero 
//edits) away.
//EXAMPLE:
//pale , pile - > true
//pales, pale - > true
//pales, bales - > true
//pales, bae - > false

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

bool oneEdit(string strFirst, string strSecound) //O(n)
{
    if (strFirst == strSecound)
        return true;
    //check insert
    if (strSecound.length() == strFirst.length() + 1)
    {
        int i = 0;
        for (; i < strFirst.length(); ++i)
        {
            if (strFirst[i] != strSecound[i])
            {
                if (strFirst[i] != strSecound[i + 1])
                {
                    break;
                }
            }
        }
        if (i == strFirst.length())
            return true;
    }

    //check remove
    if (strSecound.length() == strFirst.length() - 1)
    {
        int i = 0;
        for (; i < strSecound.length(); ++i)
        {
            if (strFirst[i] != strSecound[i])
            {
                if (strFirst[i + 1] != strSecound[i])
                {
                    break;
                }
            }
        }
        if (i == strSecound.length())
            return true;
    }

    //check replase
    if (strSecound.length() == strFirst.length())
    {
        int i = 0;
        int counter = 0;
        for (; i < strFirst.length(); ++i)
        {
            if (strFirst[i] != strSecound[i])
            {
                ++counter;
                if (counter > 1)
                    break;
            }
        }
        if (counter <= 1)
            return true;
    }

    return false;
}

int main()
{
    std::cout << "Hello World!\n";

    string str1, str2;
    bool flag = true;
    while (flag) {
        cin >> str1;
        cin >> str2;
        cout << oneEdit(str1, str2) << endl;
        if (str1 == "q")
            flag = false;
    }
}
