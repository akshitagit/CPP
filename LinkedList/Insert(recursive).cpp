/*
Given a linked list, an integer n and a position i, Insert that node n into Linked List at ith position recursively.
If position i is greater than length of LL, then you should return the same LL without any change. And if position i is equal to length of input LL, insert the node at last position.
Indexing starts from 0. You don't need to print the elements, just insert and return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)
Line 3 : Integer n (Node to be inserted)

Output format :

Updated LL elements (separated by space)

Sample Input 1 :

3 4 5 2 6 1 9 -1
3
100

Sample Output 1 :

3 4 5 100 2 6 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
0
20

Sample Output 2 :

20 3 4 5 2 6 1 9

*/


//head is head of linked list,i is the index, data is data of your node
// Following is the node structure
/**************
 class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
 };
***************/


#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
        return NULL;
    if(i==0){
        Node* temp=new Node(data);
        temp->next=head;
        return temp;
    }
    
    if(i==1){
        Node* temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    Node* curr=insertNodeRec(head->next,i-1,data);
    
    return head;
    
}


void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
