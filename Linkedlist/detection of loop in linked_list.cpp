
#include <bits/stdc++.h>
using namespace std; 

//code to detect the presence of loop in singly linked list using floyd's cycle finding technique

//Definition for singly-linked list.
struct node 
{
	int val;
	node *next;	
	node()//default constructor
	{
		val=0;next=nullptr;
	}
	node(int x)
	{
		val=x;next=nullptr;
	}
	node(int x, node *next_node)
	{
		val=x;
		next=next_node;
	}
};

bool detect_loop(node *head)
{
	if(head==nullptr)return false; //empty linked list doesn't have any cycle
	node *slow,*fast;
	slow=head;
	fast=head;
	bool flag=false;
	while(slow and fast and fast->next)
	{
		slow=slow->next;       //slow pointer moves node by node
		fast=fast->next->next; //fast pointer moves at twice(2x) the speed of slow pointer
		if(slow==fast)         //If there is loop in the list they would definitely meet after sometime
		{
			flag=true; //indicates the presence of loop or cycle in the linked list
			break;
		}
	}
	return flag;
}
int main()
{
	node *head;
	head=new node(1);
	head->next=head;  //single node with self loop for illustration purpose
	cout<<detect_loop(head);
}
