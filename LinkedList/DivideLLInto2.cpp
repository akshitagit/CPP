/*
Write a function that takes one list and divides up its nodes to create two smaller lists A and B. The sub lists should be made from alternating elements in the original list.
Nodes should be in the reverse order of which they occurred in the source list.
Print both linked lists in different lines.
Input format :

Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :

Line 1 : Output Linked List 1 elements (separated by space)
Line 2 : Output Linked List 2 elements (separated by space)

Constraints :
1 <= n <= 10^4
Sample Input :

 8 2 5 9 1 4 3 7 -1

Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 8.
Sample Output :

 3 1 5 8
 7 4 9 2

*/




/*************
 Following is the Node structure already written.

 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
 next = NULL;
 this->data = data;
	}
 
	~Node() {
 if (next != NULL) {
 delete next;
 }
	}
 };
 
*************/
#include<iostream>
#include <vector>
using namespace std;

//Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists a and b. 
//The sublists should be made from alternating elements in the original list.
//nodes should be in the reverse order of which they occurred in the source list


template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

void AlternatingSplit(Node<int>* head) {
	// Write your code here
    if(head==NULL)
        return;
    if(head->next==NULL){
        cout<<head->data;
        return;
    }
    vector <int> v1;
    vector <int> v2;
    
    Node<int>* ptr1=head;
    Node<int>* ptr2=head->next;
    
    while(ptr1){
        v1.push_back(ptr1->data);
        if(ptr1->next!=NULL){
            ptr1=ptr1->next->next;
        }
        else
            break;
    }
    while(ptr2){
        v2.push_back(ptr2->data);
        if(ptr2->next!=NULL){
            ptr2=ptr2->next->next;
        }
        else
            break;
    }
    
    for (int i=v1.size()-1;i>=0;i--)
        cout<<v1[i]<<" ";
    cout<<endl;
    for (int i=v2.size()-1;i>=0;i--)
        cout<<v2[i]<<" ";
    
}




Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL) {
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

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}
