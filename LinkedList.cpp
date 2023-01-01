// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* first;

public:
    LinkedList(){first = NULL;}

    LinkedList(int A[], int n);

    ~LinkedList();

    void insert(int index , int val);
    void Display();
    int Delete(int index);
    int Length();

};

LinkedList::LinkedList(int A[], int n)
{
    Node* last, * t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1;i < n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node* t = first;

    while (t)
    {
        first = first->next;
        delete t;
        t = first;
    }
}


void LinkedList::insert(int index , int val)
{
   
    if (index < 0 || index > Length())
    {
        cout << "Index is Invalid";
    }

    Node* p = new Node;
    p->data = val;
    p->next = NULL;

    if (index == 0)
    {
        p->next = first;
        first = p;
    }

    else {
        Node* t = first;
        for (int i = 0;i < index - 1;i++)
        {
            t=t->next;
        }
      
        p->next = t->next;
        t->next = p;
    }
}



int LinkedList::Delete(int index)
{
    Node* p;
    Node* q = NULL;
    int x = -1;
    if (index < 1 || index > Length())
    {
        return -1;
    }

    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else {
        p = first;
        for (int i = 0; i < index - 1;i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;

    }
    
        return x;

}


void LinkedList::Display()
{
    Node* p = first;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}


int LinkedList::Length()
{
    Node* p = first;
    int count=0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main()
{
    int A[] = { 12,32,44,2,7 };
    LinkedList l(A,5);
    l.Display();
    
    cout << endl;
    cout <<"Deleted Element: " <<l.Delete(1) << endl;
    cout << endl;
    l.Display();



    return 0;
}

