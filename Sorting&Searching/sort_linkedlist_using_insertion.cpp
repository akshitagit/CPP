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

void buildlist(node*&head,int n)
{
    int data;
    int j=0;
    while(j<n)
    {
        cin>>data;
        insert_At_tail(head,data);
        j++;
    }
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void sorted(node*&head)
{
    node *q,*p;
    q=head;
    int data;
    while(q!=NULL)
    {
       p=q->next;
       while(p!=NULL)
         {
         if(q->data>p->data)
             {
                 data=q->data;
                 q->data=p->data;
                 p->data=data;
             }
         p=p->next;
         }
         q=q->next;
    }
}
int main(int argc, char **argv)
{
	node *head=NULL;
    int n;
    cin>>n;
    buildlist(head,n);
    sorted(head);
    print(head);
    return 0;
}
