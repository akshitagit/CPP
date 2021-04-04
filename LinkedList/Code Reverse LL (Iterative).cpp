Code: Reverse LL (Iterative)
Send Feedback
Given a linked list, reverse it iteratively.
You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
**************************************

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
     node* cur = head;
    node* prev = NULL;
    node* next = NULL;

    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head = prev;
    return head;
}
*********************

// Reverse Linked List  a. Using recursion  b. Without using recursion
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
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
int main(){
    node* head=takeinput();
    head=rev_linkedlist_itr(head);
    print(head);
    return 0;
}



