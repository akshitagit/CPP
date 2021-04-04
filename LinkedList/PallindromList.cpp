/*
Check if a given linked list is palindrome or not. Return true or false.
Indexing starts from 0.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

9 2 3 3 2 9 -1

Sample Output 1 :

true

Sample Input 2 :

0 2 3 2 5 -1

Sample Output 2 :

false

*/

#include <bits/stdc++.h>
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


bool check_palindrome(node* head)
{
    //write your code here
    vector <int> v;
    while(head){
        v.push_back(head->data);
        head=head->next;
    }
    
    int i=0,j=v.size()-1;
    while(i<=j){
        if(v[i]!=v[j])
            return false;
        i++;
        j--;
    }
    return true;
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
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
