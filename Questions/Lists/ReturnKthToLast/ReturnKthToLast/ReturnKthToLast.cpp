// ReturnKthToLast.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Return Kth to Last: implement an algorithm to 
//find the kth to last element of a singly linked list.

#include <iostream>
#include <forward_list>
using namespace std;

int returnKthToLast(forward_list<int>::iterator head, int k,
    forward_list<int>::iterator end)
{
    auto iter = head;
    auto iter2 = head;
    for (int i = 0; i < k; ++i)
    {
        ++iter2;
    }
    while (iter2 != end)
    {
        ++iter;
        ++iter2;
    }
    return *iter;
}

int main()
{
    std::cout << "Hello World!\n";
    forward_list<int> li = { 1,2,3,4,5,6,7,8,9,10 };
                            //->
                            // n=size-k
                            //O(2*n),  O(n)
    int k = 8; //k < wielkosc(li);    i    k > 0;
    int returnVal = returnKthToLast(li.begin(), k, li.end());
}
