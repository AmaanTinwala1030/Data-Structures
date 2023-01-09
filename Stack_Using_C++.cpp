#include<iostream>

using namespace std;

#define size 5

class Stack{
    public:

    int s[size];
    int top;
}st;

void push(int item)
{
    if(st.top == size-1)
    {
        cout<<"Stack Overflow";
    }
    else
    {
        st.top++;
        st.s[st.top] = item;
    }
}

int pop()
{
    int item;
    if(st.top == -1)
    {
        cout<<"Stack Underflow";
    }
    else{
        item = st.s[st.top];
        st.top--;
        return item;
    }
}

void display(){
    if(st.top == -1)
    {
        cout<<"Stack Underflow";
    }
    else{
        int i;
        for(i=st.top;i>=0;i--)
        {
            cout<<st.s[i];
        }
    }
}

int peek()
{
    if(st.top==-1)
    {
        cout<<"Stack Underflow";
    }
    else{
        return st.s[st.top];
    }
}

int main()
{
    int choice,item;
    char ans;
    st.top = -1;

    do{

    
    cout<<"Implementation of Stack...\n";
    cout<<".....Main Menu.....\n";
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Display\n";
    cout<<"4.Peek\n";

    
    cout<<"Enter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter item to be pushed:";
            cin>>item;
            push(item);
            break;
        
        case 2:
            item = pop();
            cout<<"The value popped from stack is:"<<item;
            break;

        case 3:
            display();
            break;

        case 4:
            item = peek();
            cout<<"The Top Value of Stack is:"<<item;
            break;
        
        case 5:
            exit(0);

    }
    cout<<"Do You Want To Continue:";
    cin>>ans;

    }while(ans == 'y' || ans == 'Y');

    return 0;
}