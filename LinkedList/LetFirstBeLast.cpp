/*
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.
Input format :

Line 1 : Linked list elements of length n (separated by space and terminated by -1)

Output format :

Updated list elements (separated by space)

Constraints :
1 <= n <= 10^4
Sample Input :

 1 2 3 4 5 6 -1

Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :

 6 1 2 3 4 5


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


//Move last element to front of a given Linked List
#include<iostream>
using namespace std;

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



Node<int>* getSecLast(Node<int>* head){
    if(head->next->next==NULL)
        return head;
    
    Node<int>* ans=getSecLast(head->next);
    return ans;
}

Node<int>* moveToFront(Node<int> *head_ref) {
	// Write your code here
    if(head_ref==NULL)
        return NULL;
    if(head_ref->next==NULL)
        return head_ref;
    
    Node <int>* sec=getSecLast(head_ref);
    
    Node<int>* newHead=sec->next;
    sec->next=NULL;
    newHead->next=head_ref;
    
    return newHead;
}

Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
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

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	Node<int>* head = takeLLInput();
	head = moveToFront(head);
	printLL(head);
	delete head;
}
