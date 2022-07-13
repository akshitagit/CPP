/*
Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
You don't need to print the elements, instead return the head of updated LL.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 4 5 2 -1

Sample Output 1 :

1 5 4 2 

Sample Input 2 :

1 11 3 6 8 0 9 -1

Sample Output 2 :

1 11 3 9 6 8 0

*/

//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
#include <vector>
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

node* arrange_LinkedList(node* head)
{
    //write your code here
    if (head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
    node* pt1=head;
    
    //Find first even
    while(pt1->data % 2 !=0){
        if(!pt1->next)
            return head;
        pt1=pt1->next;
    }
    
    node* pt2=pt1->next;
    
    
    while(pt2){
        
        if(pt2->data%2!=0){
            
            vector <int> tmp;
            node* temp=pt1;
            
            while(temp!=pt2){
                tmp.push_back(temp->data);
                temp=temp->next;
            }
            
            pt1->data=pt2->data;
            
            temp=pt1->next;
            int k=0;
            while(temp!=pt2->next){
                temp->data=tmp[k];
                temp=temp->next;
                k++;
            }
            pt1=pt1->next;
        }
        pt2=pt2->next;
    }
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
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}


