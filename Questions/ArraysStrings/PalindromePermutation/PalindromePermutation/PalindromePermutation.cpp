// PalindromePermutation.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//Cracking the Coding Interview, 6th Edition
//Palindrome Permutation : Given a string, write a function 
//to check if it is a permutation of a palindrome.A palindrome 
//is a word or phrase that is the same forwards and backwards, 
//A permutation is a rearrangement of letters.The palindrome 
//does not need to be limited to just dictionary words.
//EXAMPLE 
//Input: Tact Coa
//Output: True (permutations: "taco cat""atco cta" etc.)

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

bool palindrom(string str) //O(nlogn)
{
    if (str.length() <= 1)
        return true;
    map<char,int> tab;
    for (auto iter = str.begin(); iter != str.end(); ++iter)
    {
        ++tab[*iter]; //O(logn)
    }
    bool foundOdd = false;
    for (auto iter = tab.begin(); iter != tab.end(); ++iter)
    {
        if (iter->second % 2)
        {
            if (foundOdd)
                return false;
            foundOdd = true;
            if (!(str.length() % 2))
                return false;
        }
    }
    return true;
}

#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
bool palindromWithBits(string str) //O(n)
{
    if (str.length() <= 1)
        return true;
    int bitvector = 0, x;
    int a = static_cast<int>('a');
    int z = static_cast<int>('z');
    for (char c : str)
    {
        x = static_cast<int>(c);
        if (a <= x && x <= z)
        {
            x = x - a;
            BIT_FLIP(bitvector, x);
        }        
    }
    // 00010000 - 1 = 00001111 
    // 00010000 & 00001111 = 0
    if ((bitvector & (bitvector - 1)) == 0 ||
        bitvector == 0)
        return true;
    return false;
}

int main()
{
    std::cout << "Hello World!\n";

    cout << palindrom("rrarratttuut") << endl;
    cout << palindromWithBits("rrarratttuut") << endl;
}
