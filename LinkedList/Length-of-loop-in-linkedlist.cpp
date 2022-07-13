#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
//Display likedlist
void show(struct Node *p)
{
 while(p!=NULL)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
}
//Created linkedlist
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}


int count(struct Node *q){
	struct Node *temp =q;
	int len =1;
	while(temp->next!=q){
		
		len++;
		temp=temp->next;
	}
	return len;
}

int detectl (struct Node *head){
	struct Node *p=head;
	struct Node *q=head;
	while(p && p->next){
		p=p->next;
		q=q->next->next;
	
	if(p->data == q->data){ //if linkedlist contain loop then send fast pointer(q) to count function
		return count(q);
	
	}
	
	}
	return 0;
	
}

int main(){
	struct Node *temp ; 
		int a[]={1,2,3,4,5};
		int n = sizeof(a)/sizeof(a[0]); //size of linkedlist
		
		create(a, n); //created linkedlist
		 first->next->next->next->next->next = first->next; //added loop linkedlist
 	cout<<detectl(first); //show length of loop in linkedlist

	}
