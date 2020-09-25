#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    //CONSTRUCTOR
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
int length(node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len+=1;
    }
    return len;
}
//passing head by reference
void insert_At_head(node *&head,int data)
{
    node *n=new node(data);
    n->next=head;
    head=n;
}
void insert_At_tail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
void insert_At_middle(node *&head,int data,int p)
{
    if(head==NULL||p==0)
    {
        insert_At_head(head,data);
    }
    else if(p>length(head))
    {
        insert_At_tail(head,data);
    }
    else{
        int jump=1;
        node*temp=head;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump+=1;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
    
}

//pass by value no change in head
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(int argc, char **argv)
{
	node *head=NULL;
	insert_At_head(head,5);
    insert_At_head(head,7);
    insert_At_head(head,9);
    insert_At_tail(head,0);
    insert_At_middle(head,2,3);
    print(head);
}
