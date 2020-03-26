// DeleteMiddleNode.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Delete Middle Node: Implement an algorithm to delete a node in 
//the middle (i.e., any node but the first and last node, 
//not necessarily the exact middle) of a singly linked list, 
//given only access to that node. 
//EXAMPLE Input: the node c from the linked list a->b->c->d->e->f 
//Result: nothing is returned, but the new linked list looks like 
//a->b->d->e->f 

#include <iostream>
#include <forward_list>
using namespace std;

forward_list<int>::iterator deleteMiddleNode(forward_list<int>::iterator node,
    forward_list<int>::iterator end)
{
    auto node2 = node;
    auto node3 = node;
    ++node;
    ++node;
    ++node2;
    while (node != end)
    {
        *node3 = *node2;
        ++node3;
        ++node2;
        ++node;
    }
    *node3 = *node2;

    return node3;
}

int main()
{
    std::cout << "Hello World!\n";
    forward_list<int> li = { 1,2,3,4,5,6,7,8,9,10 };
    auto node = li.begin();
    ++node;
    ++node;
    auto afterErase = deleteMiddleNode(node, li.end());
    li.erase_after(afterErase);
}
