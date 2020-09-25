#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  //constructor
 Node(int data){
 this->data= data;
 next= NULL;
}
};

Node* reverse(Node* head){
Node* curr= head;
Node* prev= NULL;
Node* next= NULL;

  while(curr){
  next= curr->next;
  curr->next= prev;
  prev= curr;
  curr= next;
  }
  //prev becomes the new head
  return prev;
}

int main(){

  int n; //enter the length of the link list
  cin>>n;
   Node* head=NULL;
   Node* tail=NULL;
   for(int i=0;i<n;i++){
     int node; //values of the link list from the user
    cin>>node;
    Node* newnode= new Node(node);
    if(head==NULL){
     head= newnode;
     tail= newnode;
    }
    else{
    tail->next= newnode;
    tail= newnode;
    }
   }
  Node* nhead=reverse(head);
  //reversed link list
  while(!nhead){
  cout<<nhead->data<<" ";
  nhead= nhead->next;
  }

   return 0;
}
