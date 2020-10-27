#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}node;

int NoOfNodes=0;

node *head=NULL;


void display(node *p)
{
    printf(" %d",p->data);
    if(!p->link)return;
    display(p->link);
}
void Push(int data)
{
    NoOfNodes++;
    node *temp = (node*)calloc(1,sizeof(node));
    temp->data = data;
    temp->link = NULL;

    // If head is NULL or first node
    if(!head)
    {
        head = temp;
        return;
    }

    // Traverse list upto end
    node *traverse=head;
    while(traverse->link)
        traverse = traverse->link;

    traverse->link = temp;
}
int Pop()
{
    node *traverse = head;

    for(int i=0;i<NoOfNodes-2;i++)
        traverse = traverse->link;

    node *Delete = traverse->link;
    traverse->link = NULL;
    int data = Delete->data;
    free(Delete);
    NoOfNodes--;

    return data;
}

int main()
{
    int n,i;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements you want to enter\n");
    for(i=0;i<n;i++)
    {
        int el;
        scanf("%d",&el);
        Push(el);
    }

    Pop();
    printf("Stack after popping top element\n");
    display(head);

    return 0;
}
