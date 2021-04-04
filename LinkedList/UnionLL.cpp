/*
Given a two Linked Lists, find out union of both given input lists and return the new Linked List.
Order of elements are not important.
Note : You don't need to print the linked list, just return the head. It will be printed internally.

Input format :

Line 1 : Linked list 1 elements (separated by space and terminated by -1)

Line 2 : Linked list 2 elements (separated by space and terminated by -1)
Sample Input 1 :

1 2 3 4 -1
8 7 5 3 -1

Sample Output 1 :

1
2
3
4
8
7
5

Sample Input 2 :

1 2 1 1 -1
8 -1

Sample Output 2 :

1
2
1
1
8

*/


/*class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};
*/
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};




ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    ListNode<int> * union1=head1;
    unordered_map<int,int> m;
    
    vector<int>v;
    
    ListNode<int>* cur=head1;
    
    while(cur->next){
        m[cur->data]+=1;
        cur=cur->next;
    }
    m[cur->data]+=1;
    
    ListNode<int> *cur2=head2;
    while(cur2){
        if(m[cur2->data]!=0){
            m[cur2->data]--;
        }
        else
            v.push_back(cur2->data);
        cur2=cur2->next;
    }
    if(v.empty())
        return union1;
    
    ListNode<int>* newHead=new ListNode<int>(v[0]);
    ListNode<int>* ntail=newHead;
    for(int i=1;i<v.size();i++){
        ListNode<int>* t=new ListNode<int>(v[i]);
        ntail->next=t;
        ntail=t;
    }
    cur->next=newHead;
    return union1;
    
    
}


ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}

int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}