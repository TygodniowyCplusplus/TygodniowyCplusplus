// Partition.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Partition; Write code to partition a linked list 
//around a value x, such that all nodes less than x 
//come before all nodes greater than or equal tox. 
//If x is contained within the list, the values of x 
//only need to be after the elements less than x (see below). 
//The partition element x can appear anywhere 
//in the "right partition"; it does not need to appear between 
//the left and right partitions. 
//EXAMPLE 
//input: 3 -> 8 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5] 
//Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8 

#include <iostream>
#include <list>
using namespace std;

void partition(list<int> &li, int x) //O(n)
{
    if (li.size() <= 1)
        return;
    auto end = li.end();
    --end;
    auto iter = li.begin();
    decltype(iter) toMoveAndRemove;
    while(iter != end)
    {
        toMoveAndRemove = iter;
        ++iter;
        if (*toMoveAndRemove < x)
            li.push_front(*toMoveAndRemove);
        else
            li.push_back(*toMoveAndRemove);
        li.erase(toMoveAndRemove);
    }
    toMoveAndRemove = iter;
    ++iter;
    if (*toMoveAndRemove < x)
        li.push_front(*toMoveAndRemove);
    else
        li.push_back(*toMoveAndRemove);
    li.erase(toMoveAndRemove);
}

int main()
{
    std::cout << "Hello World!\n";
    list<int> li = { 6,3,2,5,6,5,8,2,1,2 };
    partition(li, 5);
    return 0;
}