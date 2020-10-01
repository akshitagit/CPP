// C++ program to get intersection point of two linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

/* Function to get the counts of node in a linked list */
int getCount(Node* head); 

/* function to get the intersection point of two linked 
lists head1 and head2 where head1 has d more nodes than 
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2); 

/* function to get the intersection point of two linked 
lists head1 and head2 */
int getIntesectionNode(Node* head1, Node* head2) 
{ 

	// Count the number of nodes in 
	// both the linked list 
	int c1 = getCount(head1); 
	int c2 = getCount(head2); 
	int d; 

	// If first is greater 
	if (c1 > c2) { 
		d = c1 - c2; 
		return _getIntesectionNode(d, head1, head2); 
	} 
	else { 
		d = c2 - c1; 
		return _getIntesectionNode(d, head2, head1); 
	} 
} 

/* function to get the intersection point of two linked 
lists head1 and head2 where head1 has d more nodes than 
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
	// Stand at the starting of the bigger list 
	Node* current1 = head1; 
	Node* current2 = head2; 

	// Move the pointer forward 
	for (int i = 0; i < d; i++) { 
		if (current1 == NULL) { 
			return -1; 
		} 
		current1 = current1->next; 
	} 

	// Move both pointers of both list till they 
	// intersect with each other 
	while (current1 != NULL && current2 != NULL) { 
		if (current1 == current2) 
			return current1->data; 

		// Move both the pointers forward 
		current1 = current1->next; 
		current2 = current2->next; 
	} 

	return -1; 
} 

/* Takes head pointer of the linked list and 
returns the count of nodes in the list */
int getCount(Node* head) 
{ 
	Node* current = head; 

	// Counter to store count of nodes 
	int count = 0; 

	// Iterate till NULL 
	while (current != NULL) { 

		// Increase the counter 
		count++; 

		// Move the Node ahead 
		current = current->next; 
	} 

	return count; 
} 

// Driver Code 
int main() 
{ 
	/* 
		Create two linked lists 
	
		1st 3->6->9->15->30 
		2nd 10->15->30 
	
		15 is the intersection point 
	*/

	Node* newNode; 

	// Addition of new nodes 
	Node* head1 = new Node(); 
	head1->data = 10; 

	Node* head2 = new Node(); 
	head2->data = 3; 

	newNode = new Node(); 
	newNode->data = 6; 
	head2->next = newNode; 

	newNode = new Node(); 
	newNode->data = 9; 
	head2->next->next = newNode; 

	newNode = new Node(); 
	newNode->data = 15; 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = new Node(); 
	newNode->data = 30; 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 

	cout << "The node of intersection is " << getIntesectionNode(head1, head2); 
} 


