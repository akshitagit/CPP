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

class Queue{
        int size;
        node*front,*rear;
    public:
        Queue()
        {
            front=nullptr;
            size=0;
            rear=nullptr;
        }
        
        void enqueue(int value);
        void dequeue();
        void print();
        void get_size();
        void is_empty();
};

void Queue :: enqueue(int value)
{
    node*temp=new node(value);
    if(size==0)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
    
    size++;
}

void Queue :: dequeue()
{
    if(size==0)
    {
        cout<<"Queue empty!\n";
    }
    else
    {
        cout<<"Value popped is : "<<front->data<<"\n";
        front=front->next;
        size--;
    }
    
}

void Queue :: print()
{
    cout<<"Queue : \n";
    node*temp=front;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void Queue :: get_size()
{
    cout<<"Size of queue : "<<size<<"\n";
}

void Queue :: is_empty()
{
    if(size==0)
    cout<<"Queue is empty\n";
    else
    cout<<"Queue is not empty\n";
}

int main()
{
    int value,choice;
    Queue q;
    while(1)
    {
        cout<<"Select your choice: \n";
        cout<<"1. Enqueue a value \n";
        cout<<"2. Dequeue a value \n";
        cout<<"3. Show queue \n";
        cout<<"4. Print size \n";
        cout<<"5. Check if empty \n";
        cout<<"6. Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cin>>value;
                q.enqueue(value);
                break;
            }
            case 2:{
                q.dequeue();
                break;
            }
            case 3:{
                q.print();
                break;
            }
            case 4:{
                q.get_size();
                break;
            }
            case 5:{
                q.is_empty();
                break;
            }
            case 6:break;
        }
    }
    return 0;
}
