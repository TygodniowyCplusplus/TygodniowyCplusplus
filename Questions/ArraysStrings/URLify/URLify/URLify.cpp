// URLify.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

//Cracking the Coding Interview, 6th Edition
//URLify: Write a method to replace all spaces in a string with '%20' 
//You may assume that the string has sufficient space at the end to 
//hold the additional characters, and that you are given the "true" 
//length of the string.
//Input:"Mr John Smith"
//Output:"Mr%20John%20Smith"

string changeSpace(string str) //O(n^2)
{
    string space = "%20";
    auto found = str.find(" "); //O(n)
    while (found != std::string::npos)
    {
        str.replace(found, 1, space); //O(n)
        found = str.find(" "); //O(n)
    }
    return str;
}

string changeSpace2(string str) //O(n)
{
    string space = "%20";
    int counter = 0;
    for (int i = 0; i < static_cast<int>(str.length()); ++i)
    {
        if (str[i] == ' ')
        {
            ++counter;
        }
    }
    if (counter == 0)
        return str;
    int index = str.length() + (counter * 2);
    int trueLength = str.length();
    str.resize(str.length() + (counter * 2));
    for (int i = (trueLength - 1); i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        }
        else
        {
            str[index - 1] = str[i];
            index--;
        }
    }
    return str;
}

int main()
{
    std::cout << "Hello World!\n";

    cout << changeSpace("Mr John Smith ") << endl;
    cout << changeSpace2("Mr John Smith ") << endl;
}
