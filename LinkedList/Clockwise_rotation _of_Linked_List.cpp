#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* add(Node *head,int data)
{
    Node* temp=new Node(data);
    if(head==NULL)
    {
        head=temp;
    }
    else{
      Node *trav=head;
      while(trav->next!=NULL)
      {
        trav=trav->next;
      }
       
       trav->next=temp;
    }
    return head;
}

Node* rotateRight(Node* head, int k) {
       
    if (!head || !head->next || k == 0)
    return head;
    Node *cur = head;
    int len = 1;
    while (cur->next)
    {
        len++;             //count the length of LinkedList.
        cur = cur->next;
    } 
    cur->next = head;     //connect last node to first to make circular.
    k = len - k % len;    //to find actual number of rotation.
    while (k--)
    {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = nullptr;
   return head; 
   }
   
void print(Node* head)
{
   if(head==NULL)
   {
       cout<<"no data in linkedlist";
    
   }
   {
       Node *temp=head;
       while(temp!=NULL)
       {
           cout<<temp->data<<"-->";
           temp=temp->next;
       }
   }
   cout<<"NULL"<<endl;
}
int main()
{
    Node *head=NULL;
    int n,k;
    cout<<"enter the size of linkedlist and  k :";
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
      int element;
      cin>>element;
      head=add(head,element);
    }
   print(head);
   cout<<"after clockwise rotation"<<endl;
   head=rotateRight(head,k);
   print(head);
    return 0;
}