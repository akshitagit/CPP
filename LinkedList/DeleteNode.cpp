/*
Given a linked list and a position i, delete the node of ith position from Linked List iteratively.
If position i is greater than length of LL, then you should return the same LL without any change.
Indexing starts from 0. You don't need to print the elements, just delete the node and return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : Integer i (position)

Output format :

Updated LL elements (separated by space)

Sample Input 1 :

3 4 5 2 6 1 9 -1
3

Sample Output 1 :

3 4 5 6 1 9

Sample Input 2 :

3 4 5 2 6 1 9 -1
0

Sample Output 2 :

4 5 2 6 1 9

*/


/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

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

Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(i==0){
        Node *temp=head->next;
        delete head;
        return temp;
    }
    int c=1;
    Node* cur=head->next;
    Node* prev=head;
    while(cur!=NULL){
        if(c==i){
            prev->next=cur->next;
            delete cur;
            return head;
        }
        prev=cur;
        cur=cur->next;
        c++;
    }
    return head;
    
}




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
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
    return 0;
}

