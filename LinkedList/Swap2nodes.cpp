/*
Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
Assume i & j given will be within limits. And i can be greater than j also.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : i and j (separated by space)
Sample Input 1 :

3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :

3 4 5 6 2 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
2 4

Sample Output 2 :

3 4 6 2 5 1 9


*/

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    if(i>j){
        i=i+j;
        j=i-j;
        i=i-j;
    }
    //Find nodes
    if(i==0){
        if(j==1){
            node *cur=head->next;
            head->next=cur->next;
            cur->next=head;
            return cur;
        }
        node *pt=head;
        for(int c=1;c<j;c++)
            pt=pt->next;
        
        node *temp=head->next;
        node *cur=pt->next;
        
        head->next=cur->next;
        pt->next=head;
        cur->next=temp;
        return cur;
        
    }
    if(j-i==1){
        node * pt=head;
        for(int c=1;c<i;c++)
            pt=pt->next;
        
        node* cur=pt->next;
        node* cur1=cur->next;
        
        cur->next=cur1->next;
        pt->next=cur1;
        cur1->next=cur;
        return head;
        
    }
    node* pt1=head;
    node *pt2=head;
    
    for(int c=1;c<i;c++)
        pt1=pt1->next;
    
    for(int c=1;c<j;c++)
        pt2=pt2->next;
    
    node *cur1=pt1->next;
    node *cur2=pt2->next;
    
    node *temp=cur1->next;
    
    cur1->next=cur2->next;
    pt2->next=cur1;
    pt1->next=cur2;
    cur2->next=temp;
    
    return head;
}

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

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}
