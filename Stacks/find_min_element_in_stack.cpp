// Find Minimum element in stack in O(1) time

#include<bits/stdc++.h>
using namespace std;

class MinStack
{
    private:
    stack<int>s;
    int min_e;

    public:
    MinStack()
    {
        while(!s.empty())  //------clear the stack
        s.pop();
        min_e=-1;
    }
    void push(int);
    void pop();
    int top();
    int getMin();
};

void MinStack::push(int x) 
{
    if(s.empty() )
    {
        min_e=x;
        s.push(x);
    }
    
    else if(x>=min_e)
    s.push(x);
    
    else if(x<min_e)
    {
        int temp=min_e;
        s.push(2*x-min_e);
        min_e=x;
    }
}
void MinStack::pop() 
{
    if(s.empty())
    return;
    
    int top=s.top();
    
    if(top>=min_e)
    {
        s.pop();
        if(s.empty()) //--------when stack is empty update min to -1
        min_e=-1;
    }    
    
    else
    {
        min_e=2*min_e-top;
        s.pop();
        if(s.empty())
        min_e=-1;
    }
    
}
int MinStack::top() 
{
    if(s.empty())
    return -1;
    
    int top=s.top();
    
    if(top>=min_e)
    return top;
    
    else
    {
        return min_e;
    }
}
int MinStack::getMin() 
{
    return min_e;
}

int main()
{
    MinStack m;
    char operation;
    int value;
    while(1)
    {
        cin>>operation;
        switch(operation)
        {
            case 'p':
            {
                cin>>value;
                m.push(value);
                break;
            }
            case 'd':
            {
                m.pop();
                break;
            }
            case 't':
            {
                cout<<"Top element in the stack is: "<<m.top()<<"\n";
                break;
            }
            case 'm':
            {
                cout<<"Min value in stack is: "<<m.getMin()<<"\n";
                break;
            }
            case 'e':
            {
                exit(0);
            }
        }
    }
    return 0;
}