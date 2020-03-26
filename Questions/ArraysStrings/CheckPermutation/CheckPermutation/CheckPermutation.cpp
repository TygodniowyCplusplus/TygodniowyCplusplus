// CheckPermutation.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Check Permutation: Given two strings, write a method to decide 
//if one is a permutation of the other.

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

bool checkPermutation(string str1, string str2)//O(nlog n)
{
    str1.erase(remove_if(str1.begin(), str1.end(), isspace),//O(n)
        str1.end());
    str2.erase(remove_if(str2.begin(), str2.end(), isspace),//O(n)
        str2.end());

    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end()); //O(nlog n)
    sort(str2.begin(), str2.end()); //O(nlog n)

    auto iter = str1.begin();
    auto iter2 = str2.begin();
    while (iter != str1.end()) //O(n)
    {
        if (*iter != *iter2)
            return false;
        ++iter;
        ++iter2;
    }
    return true;
}

//jesli byśmy uzywali rozszerzonego ASCII to wtedy 
//rozmiar tablicy = 256, 
//string jest z char-ow wiec maksymalnie mamy 256 znakow
bool checkPermutation2(string str1, string str2)//O(n)
{
    str1.erase(remove_if(str1.begin(), str1.end(), isspace),//O(n)
        str1.end());
    str2.erase(remove_if(str2.begin(), str2.end(), isspace),//O(n)
        str2.end());

    if (str1.length() != str2.length())
        return false;

    int letters[128] = {};
    int number = 0;
    for (char c : str1) //O(n)
    {
        number = static_cast<int>(c);
        if (number < 0 || number > 128)
            throw "Mialo byc tylko ASCII";
        ++letters[number];
    }

    for (char c : str2)//O(n)
    {
        number = static_cast<int>(c);
        if (number < 0 || number > 128)
            throw "Mialo byc tylko ASCII";
        --letters[number];
        if (letters[c] < 0) //tylko mniejscy niż bo mamy ta sama
            return false;   //dlugosc stringa
    }
    return true;
}

int main()
{
    std::cout << "Hello World!\n";
    string str1 = "ss sda ds";
    string str2 = "sasd sds ";
    bool resoult = checkPermutation2(str1, str2);
}