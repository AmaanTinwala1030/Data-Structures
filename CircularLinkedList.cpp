#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

class CircularLL {
private:
    Node* first;

public:
    CircularLL(int A[], int n);
    void insert(int index, int value);
    int Delete(int index);
    int Lenght();
    void Display();
};


CircularLL::CircularLL(int A[], int n)
{
    Node* t, * last;

    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1;i < n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}




void CircularLL::Display()
{
    Node* p = first;
    do {
        cout << " " << p->data<<"->";
        p = p->next;
    } while (p != first);
    cout << endl;
}


int CircularLL::Lenght()
{
    Node* p = first;
    int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != first);

    return count;
}


void CircularLL::insert(int index, int val)
{
    Node* p, * t;
    int i;

    if (index<0 || index>Lenght())
    {
        cout << "Index is Invalid Please Enter the Index between 0 to " << Lenght()<<endl;
    }

    t = new Node;
    t->data = val;

    if (index == 0)
    {
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            p = first;
            while (p->next != first)
            {
                p = p->next;
            }
            t->next = first;
            first = t;
            p->next = first;
        }
    }
    else
    {
        p = first;
        for (i = 0;i < index - 1;i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}


int CircularLL::Delete(int index)
{
    Node* p, * q = NULL;
    int x = -1;

    if (index<1 || index>Lenght())
    {
        cout << "Index is Invalid Please Enter the Index between 1 to " << Lenght()<<endl;
    }

    if (index == 1)
    {
        p = first;
        while (p->next != first)
        {
            p = p->next;
        }
        q = first;
        first = first->next;
        x = q->data;
        delete q;
        p->next = first;
    }

    else
    {
        p = first;
        for (int i = 0;i < index - 1;i++)
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
int main()
{
    
    int A[] = {1,2,3,4,5};
    CircularLL l(A,5);
    l.Display();
    l.insert(0, 0);
    cout << " " << endl;
    l.Display();
    cout << " DELETED ITEM:: " << l.Delete(4)<<endl;
    l.Display();
    return 0;
}


