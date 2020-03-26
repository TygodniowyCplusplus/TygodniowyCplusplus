// PalindromeList.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Palindrome: Implement a function to check if a 
//linked list is a palindrome

#include <iostream>
#include <list>
using namespace std;

bool palindrome(list<int>& li)
{
    auto iter = li.begin();
    auto riter = li.rbegin();
    while (&*iter != &*riter)
    {
        if (*iter != *riter)
            return false;
        ++iter;
        if (&*iter == &*riter)
            return true;
        ++riter;
    }
    return true;
}

int main()
{
    std::cout << "Hello World!\n";
    list<int> li = { 1,2,3,4,3,2,1 };
    bool resoult = palindrome(li);
    return 0;
}