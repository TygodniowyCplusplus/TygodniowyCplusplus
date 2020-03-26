// LoopDetection.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Loop Detection: Given a circular linked list, implement an 
//algorithm that returns the node at the beginning of the loop. 
//DEFINITION Circular linked list: A (corrupt) linked list in 
//which a node's next pointer points to an earlier node, so as to 
//make a loop in the linked list. 
//EXAMPLE 
//Input: A->B->C->D->E->C    [the same C as earlier] 
//Output: C

#include <iostream>
using namespace std;

class node
{
public:
    int a = 0;
    node* next = nullptr;
};
class Forward_list
{
    node* tail = nullptr;
public:
    node* head = nullptr;

    Forward_list(int size)
    {
        head = new node;
        head->a = 0;
        node* nodeIter;
        node* nodeIterBefore = head;
        for (int i = 1; i < size; ++i)
        {
            nodeIter = new node;
            nodeIterBefore->next = nodeIter;
            nodeIter->a = i;
            nodeIterBefore = nodeIter;
        }
        tail = nodeIterBefore;
    }

    void makeLoop(int place)
    {
        node* nodeIter = head;
        for (int i = 0; nodeIter->next != nullptr && 
            i < place; ++i)
            nodeIter = nodeIter->next;
        tail->next = nodeIter;
    }
};

node* loopDetection(node* head)
{
    node* slowIter = head;
    node* fastIter = head;
    while (true)
    {
        if (slowIter == nullptr || fastIter == nullptr || 
            fastIter->next == nullptr)
            return nullptr;
        slowIter = slowIter->next;
        fastIter = fastIter->next->next;
        if (slowIter == fastIter)
            break;
    }
    slowIter = head;
    while (slowIter != fastIter)
    {
        slowIter = slowIter->next;
        fastIter = fastIter->next;
    }
    return slowIter;
}

int main()
{
    std::cout << "Hello World!\n";
    Forward_list li(10);
    li.makeLoop(0);
    node* resoult = loopDetection(li.head);
    return 0;
}