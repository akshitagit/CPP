#include<iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
Node* newNode(int x)
{
    Node* temp=new Node(x);
    return temp;
}
Node* insert(Node* head,int data)
{
    if(head==NULL)
    head=newNode(data);
    else
    {
        Node* temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node* last=newNode(data);
        temp->next=last;
    }
    return head;
}
bool isPalindrome(Node *head)
{
    stack<int> s;
    struct  Node* temp;
    temp=head;
    while(head!=NULL)
    {
        s.push(head->data);
        head=head->next;
    }
    while(temp!=NULL)
    {
        if(s.top()==temp->data)
        {
            s.pop();
            temp=temp->next;
    }
    else
    return false;
    }
    if(temp==NULL)
    return true;
    else
    return false;
}
void printList(Node* head)
{
    Node* temp;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    printList(head);
    cout<<isPalindrome(head)<<endl;
    Node* head1=NULL;
    head1=insert(head1,1);
    head1=insert(head1,2);
    head1=insert(head1,1);
    printList(head1);
    cout<<isPalindrome(head1)
}