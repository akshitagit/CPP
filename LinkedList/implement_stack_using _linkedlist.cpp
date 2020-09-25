#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*next;
    node(int value)
    {
        data=value;
        next=nullptr;
    }
};

class Stack{
        int size;
        node*top;
    public:
        Stack()
        {
            top=nullptr;
            size=0;
        }
        
        void push(int value);
        void pop();
        void print();
        void get_size();
        void is_empty();
};

void Stack :: push(int value)
{
    int n=size;
    node* temp=new node(value);

    if(n==0)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
    size++;
}

void Stack :: pop()
{
    int n=size;
    if(n==0)
    {
        cout<<"Stack is empty!\n";
    }
    else
    {
        node*temp=top;
        cout<<"Value popped is : "<<temp->data<<"\n";
        temp=temp->next;
        top=temp;
        size--;
    }
}

void Stack :: print()
{
    cout<<"Stack: \n";
    node *temp=top;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void Stack :: get_size()
{
    int n= size;
    cout<<"Size of stack : "<<n<<"\n";
}

void Stack :: is_empty()
{
    if(size==0)
    cout<<"Empty\n";
    else
    {
        cout<<"Not Empty\n";
    }
}

int main()
{
    int value,choice;
    Stack s;
    while(1)
    {
        cout<<"Select your choice: \n";
        cout<<"1. Push a value \n";
        cout<<"2. Pop a value \n";
        cout<<"3. Show stack \n";
        cout<<"4. Print size \n";
        cout<<"5. Check if empty \n";
        cout<<"6. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cin>>value;
                s.push(value);
                break;
            }
            case 2:{
                s.pop();
                break;
            }
            case 3:{
                s.print();
                break;
            }
            case 4:{
                s.get_size();
                break;
            }
            case 5:{
                s.is_empty();
                break;
            }
            case 6:break;
        }
    }
    return 0;
}
