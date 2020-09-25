#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// traversal in circular linked list
void printList(Node *head)
{
    Node *temp = head;
    if(head == NULL)
    {
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;    
}

// iserting at begining
Node * insertBegin(Node *head, int item)
{
    Node *new_node = new Node(item);
    if(head == NULL)
    {
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = head->next;
    head->next = new_node;
    int temp = head->data;
    head->data = new_node->data;
    new_node->data = temp;
    return head;
}

// insert at end;
Node *insertEnd(Node *head, int item)
{
    Node *new_node = new Node(item);
    if(head == NULL)
    {
        new_node = new_node->next;
        return new_node;
    }
    else
    {
        new_node->next = head->next;
        head->next = new_node;
        int temp;
        temp = head->data;
        head->data = new_node->data;
        new_node->data = temp;
        return head->next;
    }
    
}

// delete head node 
Node *deleteHead(Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        delete(head);
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete(temp);
    return head;
}

// delete kth node
Node * deleteKthNode(Node *head, int k)
{
    if(head == NULL)
    {
        return NULL; 
    }
    if(k == 1)
    {
        return deleteHead(head);
    }
    Node *curr = head;
    for(int i = 0; i < k-2; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
    return head;
}
int main(int argv, char *argc[])
{
    Node *head = insertBegin(NULL, 12);  
    head = insertBegin(head, 23);   
    head = insertBegin(head, 40);   
    head = insertBegin(head, 30);
    head = insertEnd(head, 1000);
    head = insertBegin(head, 1);
    printList(head);   
    head = deleteHead(head);
    printList(head);
    head = deleteKthNode(head, 3);
    printList(head);
    return 0;
}
