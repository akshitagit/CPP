#include<stdio.h>
#include<stdlib.h>
typedef struct btree
{ 
int data[3];
int count;
struct btree * left;
struct btree * mid;
struct btree * right;
struct btree * last;
struct btree *next;
struct btree *prev;
}Node;
Node * root = NULL;
Node * createNode(Node *, int);
void addnode(int);
Node * insert(Node *, int);
Node * frootsp(Node *);
Node * srootsp(Node *);
Node * divide(Node *, int);
int ft=1;
void sort(int arr[3])
{
 int i,j;
for( i=0; i<2; i++)
{
for( j=0; j<2-i; j++)
{
if(arr[j]>arr[j+1])
{
int temp = arr[j];
arr[j] = arr[j+1]; 
arr[j+1] = temp;
}
}
}
}
Node * createNode(Node* node, int data)
{
node = (Node*)malloc(sizeof(Node));
node->count = 1;
node->data[0] = data;
node->data[1]=-1;
node->data[2]=-1;
node->left = NULL;
node->mid = NULL;
node->right = NULL;
node->last = NULL;
return node;
}
void addnode(int data)
{
if(root == NULL)
{
root = createNode(root, data);
return;
}
Node * temp = root;
while(temp->left != NULL && temp->mid != NULL)
{ 
if(data < temp->data[0])
temp = temp->left;
else if(data > temp->data[0] && (temp->count == 1 || data < temp->data[1]))
temp = temp->mid;
else
temp = temp->right;
}
temp = insert(temp, data);
while(temp->count == 3)
{
if(temp == root)
{
if(ft==1)
{
temp = frootsp(temp);
root = temp;
ft=0;
}
else
{
temp=srootsp(temp);
root=temp;
}
}
else
{
temp = divide(temp, data);
} 
}
}
Node * insert(Node * node, int data)
{
if(node->count == 1)
{
if(data < node->data[0])
{
node->data[1] = node->data[0];
node->data[0] = data;
}
else
{
node->data[1] = data;
}
node->count = 2;
}
else if(node->count == 2)
{
if(data > node->data[1])
node->data[2] = data;
else if(data < node->data[0])
{
node->data[2] = node->data[1];
node->data[1] = node->data[0];
node->data[0] = data;
}
else 
{
node->data[2] = node->data[1];
node->data[1] = data;
}
node->count = 3;
//divide condition comes here
}
return node;
}
Node * frootsp(Node * node)
{
Node * newroot = createNode(newroot, node->data[1]);
Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1;
newroot->left = node;
newroot->mid = nbr;
//nbr->left = node->mid;
//nbr->mid = node->right;
node->right = NULL;
node->last = NULL;
node->next=nbr;
nbr->prev=node;
return newroot;
} 
Node * srootsp(Node * node)
{
Node * newroot = createNode(newroot, node->data[1]);
Node * nbr = createNode(nbr, node->data[2]);
nbr->count=1;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1;
newroot->left = node;
newroot->mid = nbr;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
//node->next=nbr;
//nbr->prev=node;
return newroot;
}
Node * divide(Node * node, int data)
{
Node * temp = root;
while(temp->left != node && temp->mid != node && temp->right != node)
{
if(data < temp->data[0])
temp = temp->left;
if(data > temp->data[0] && (temp->count == 1 || data < temp->data[1]))
temp = temp->mid;
else 
temp = temp->right;
}
if(temp->count == 1)
{
if(temp->left == node)
{
temp->data[1] = temp->data[0];
temp->data[0] = node->data[1];
temp->count = 2;
if(node->left!=NULL && node->right!=NULL && node->mid!=NULL)
{
 Node * nbr = createNode(nbr, node->data[2]);
 nbr->count=1;
 node->data[1]=-1;
 node->data[2]=-1;
 nbr->left = node->right;
 nbr->mid = node->last;
 node->right = NULL;
 node->last = NULL;
 node->count = 1;
 temp->right = temp->mid;
 temp->mid = nbr;
}
else {
 Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2;
node->data[1]=-1; 
node->data[2]=-1;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
node->count = 1;
temp->right = temp->mid;
temp->mid = nbr;
node->next=nbr;
nbr->prev=node;
nbr->next=temp->right;
temp->right->prev=nbr;
}
}
else
{
temp->data[1] = node->data[1];
temp->count = 2;
if(node->left!=NULL && node->right!=NULL && node->mid!=NULL)
{
 Node * nbr = createNode(nbr, node->data[2]);
 nbr->count=1;
 node->count = 1;
 node->data[1]=-1;
 node->data[2]=-1;
 temp->right = nbr;
 nbr->left = node->right; 
 nbr->mid = node->last;
 node->right = NULL;
 node->last = NULL;
}
else {
Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1;
temp->right = nbr;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
node->next=nbr;
nbr->prev=node;
}
}
}
else
{
if(temp->left == node)
{
temp->data[2] = temp->data[1];
temp->data[1] = temp->data[0]; 
temp->data[0] = node->data[1];
temp->count = 3;
Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
temp->last = temp->right;
temp->right = temp->mid;
temp->mid = nbr;
node->next=nbr;
nbr->prev=node;
nbr->next=temp->mid;
temp->mid->prev=nbr;
}
else if(temp->mid == node)
{
temp->data[2] = temp->data[1];
temp->data[1] = node->data[1];
temp->count = 3;
Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2; 
nbr->left = node->right;////
nbr->mid = node->last;/////
node->right = NULL;
node->last = NULL;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1;
temp->last = temp->right;
temp->right = nbr;
node->next=nbr;
nbr->prev=node;
nbr->next=temp->last;
temp->last->prev=nbr;
}
else
{
temp->data[2] = node->data[1];
temp->count = 3;
Node * nbr = createNode(nbr, node->data[1]);
nbr->data[1]=node->data[2];
nbr->count=2;
nbr->left = node->right;////
nbr->mid = node->last;////
node->right = NULL;
node->last = NULL;
node->count = 1;
node->data[1]=-1;
node->data[2]=-1; 
temp->last = nbr;
node->next=nbr;
nbr->prev=node;
}
}
return temp;
}
void print2(int l,int u,int len)
{
 Node *temp=root;
 int arr[len+1];int m=1,i;
 while(temp->left!=NULL)
 temp=temp->left;
 while(temp!=NULL)
 {
 if(temp->data[0]!=-1)
 {
 arr[m]=temp->data[0];
 m++;
 }
 if(temp->data[1]!=-1)
 {
 arr[m]=temp->data[1];
 m++;
 }
 //printf("%d %d ",temp->data[0],temp->data[1]);
 temp=temp->next;
 } 
 printf("Elements in the range from %d to %d : \n",l,u);
 for(i=l;i<=u;i++)
 {
 printf("%d ",arr[i]);
 }
 printf("\n");
}
void print(Node * node)
{
if(node == NULL)
return;
printf("Data at this node is : %d %d\n", node->data[0],node->data[1]);
print(node->left);
print(node->mid);
print(node->right);
}
int main()
{
int i=1, c, element,counter=0,lower=0,upper=0
;
while(i!=0)
{
printf("\n********************************************************\n");
printf("\n1.Insert\n2.Print(Node Structure)\n3.Print(Range Query)\n4.Exit\n\n");
printf("Enter your choice\n");
scanf("%d", &c);
switch(c)
{ 
case 1: printf("Enter element to be inserted\n");
scanf("%d", &element);
addnode(element);
counter++;
break;
case 2:
 printf("Printing the data stored at each node\n");
 print(root);
 //print2();
break;
case 3:
printf("Enter element in the range from 1 to %d\n",counter);
printf("Enter lower limit of range\n");
scanf("%d",&lower);
printf("Enter upper limit of range\n");
scanf("%d",&upper);
if(lower<1 || lower>counter || upper<1 || upper>counter || lower>upper)
{printf("Invalid range\n");}
else
{
 print2(lower,upper,counter);
}
break;
default: i = 0;
}
}
return 0;
} 