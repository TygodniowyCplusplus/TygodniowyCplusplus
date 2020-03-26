// RemoveDups.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Remove Dups: Write code to remove duplicates from 
//an unsorted linked list. 
//FOLLOW UP 
//How would you solve this problem if a temporary 
//buffer is not allowed? 

#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

void removeDups(list<int>& li)//0(n)
{
    unordered_set<int> usSet;
    list<int>::iterator iter2;
    for (auto iter = li.begin(); iter != li.end();)//O(n)
    {
        if (!((usSet.insert(*iter)).second))//O(1)
        {
            if (iter != li.end())
            {
                iter2 = iter;
                ++iter;
                li.erase(iter2);
            }
            else
            {
                li.erase(iter);
                return;
            }
        }
        else
            ++iter;
    }
}

void removeDupsNoBuff(list<int>& li)//O(nlog n)
{
    if (li.size() < 1)
        return;
    list<int>::iterator iterPriv;
    li.sort(); //O(nlog n)
    auto iter = li.begin();
    int iValue = *iter;
    ++iter;
    for (; iter != li.end(); ++iter)//O(n)
    {
        if (*iter == iValue)
        {
            li.erase(iterPriv);
        }
        iValue = *iter;
        iterPriv = iter;
    }
}

int main()
{
    std::cout << "Hello World!\n";
    list<int> li = { 7,7,5,16,16,8,8,8,8 };
    //removeDups(li);
    removeDupsNoBuff(li);
}

