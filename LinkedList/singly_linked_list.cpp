#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAttail(Node *&tail, int da)
{
    Node *temp = new Node(da);
    tail->next = temp;
    tail = tail->next;
}
void insertAtMiddle(Node *&tail, Node *&head, int position, int dat)
{ // starting
    if (position == 1)
    {
        InsertAtHead(head, dat);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertAttail(tail, dat);
    }
    Node *nodetoinsert = new Node(dat);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *tail = node1;
    Node *head = node1;
    print(head);
    InsertAttail(tail, 12);
    print(head);
    InsertAttail(tail, 13);
    print(head);
    insertAtMiddle(tail, head, 2, 15);
    print(head);
    cout << "head" << head->data << endl;
    cout << "tail" << tail->data << endl;
}