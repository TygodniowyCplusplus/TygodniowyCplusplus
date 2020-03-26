// Intersection.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Cracking the Coding Interview, 6th Edition
//Intersection: Given two (singly) linked lists, 
//determine if the two lists intersect. Return the 
//intersecting node. Note that the intersection is defined 
//based on reference, not value. That is, if the kth node of 
//the first linked list is the exact same node (by reference) 
//as the jt h node of the second linked list, then they are 
//intersecting.
//
//a->b->c->d
//         d->e->f
//   t->c->d
//Rozwiązanie: unordered_set O(n).
//
#include <iostream>
#include <forward_list>
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

    void addList(Forward_list& li)
    {
        tail->next = li.head;
        tail = li.tail;
    }
};

node* intersection(node* head1, node* head2)
{
    node* nodeIter1 = head1;
    int size1 = 0;
    while (nodeIter1->next != nullptr)
    {
        nodeIter1 = nodeIter1->next;
        size1 += 1;
    }
    node* nodeIter2 = head2;
    int size2 = 0;
    while (nodeIter2->next != nullptr)
    {
        nodeIter2 = nodeIter2->next;
        size2 += 1;
    }


    if (nodeIter1 == nodeIter2)
    {
        nodeIter1 = head1;
        nodeIter2 = head2;

        if (size1 >= size2)
        {
            int diff = size1 - size2;
            for (int i = 0; i < diff; ++i)
                nodeIter1 = nodeIter1->next;
        }
        else //(size1 < size2)
        {
            int diff = size2 - size1;
            for (int i = 0; i < diff; ++i)
                nodeIter2 = nodeIter2->next;
        }

        while (nodeIter1->next != nullptr)
        {
            if (nodeIter1 == nodeIter2)
                return nodeIter1;
            nodeIter1 = nodeIter1->next;
            nodeIter2 = nodeIter2->next;
        }
    }
    else
    {
        return nullptr;
    }
}

int main()
{
    std::cout << "Hello World!\n";
    Forward_list li(4);
    Forward_list li2(4);
    Forward_list li3(3);
    li.addList(li3);
    li2.addList(li3);
    node* resoult = intersection(li.head, li2.head);
    return 0;
}