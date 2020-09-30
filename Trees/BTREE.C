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
}Node;
Node * root = NULL;
Node * createNode(Node *, int);
void addnode(int);
Node * insert(Node *, int);
Node * rootsp(Node *);
Node * divide(Node *, int);
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
temp = rootsp(temp);
root = temp;
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
Node * rootsp(Node * node)
{
Node * newroot = createNode(newroot, node->data[1]);
Node * nbr = createNode(nbr, node->data[2]);
node->count = 1;
node->data[1]=-1;
newroot->left = node;
newroot->mid = nbr;
nbr->left = node->right;
nbr->mid = node->last; 
node->right = NULL;
node->last = NULL;
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
Node * nbr = createNode(nbr, node->data[2]);
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL; 
node->count = 1;
node->data[1]=-1;
temp->right = temp->mid;
temp->mid = nbr;
}
else
{
temp->data[1] = node->data[1];
temp->count = 2;
Node * nbr = createNode(nbr, node->data[2]);
node->count = 1;
node->data[1]=-1;
temp->right = nbr;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
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
Node * nbr = createNode(nbr, node->data[2]); 
node->count = 1;
node->data[1]=-1;
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
temp->last = temp->right;
temp->right = temp->mid;
temp->mid = nbr;
}
else if(temp->mid == node)
{
temp->data[2] = temp->data[1];
temp->data[1] = node->data[1];
temp->count = 3;
Node * nbr = createNode(nbr, node->data[2]);
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
node->count = 1;
node->data[1]=-1;
temp->last = temp->right;
temp->right = nbr;
}
else
{
temp->data[2] = node->data[1]; 
temp->count = 3;
Node * nbr = createNode(nbr, node->data[2]);
nbr->left = node->right;
nbr->mid = node->last;
node->right = NULL;
node->last = NULL;
node->count = 1;
node->data[1]=-1;
temp->last = nbr;
}
}
return temp;
}
void print(Node * node)
{
if(node == NULL)
return;
printf("%d %d\n", node->data[0],node->data[1]);
print(node->left);
print(node->mid);
print(node->right);
/*if(node->count == 2)
{
printf("%d ", node->data[1]);
print(node->right);
}*/
} 
void search(Node * node, int data)
{
if(node->left == NULL)
{
if(node->data[0] == data || node->data[1] == data)
{
printf("Element found\n");
}
else
printf("Element not found\n");
return;
}
if(node->count == 1)
{
if(data < node->data[0])
search(node->left, data);
else if(data > node->data[0])
search(node->mid, data);
else
{
printf("Element found\n");
return;
}
}
else
{
if(data == node->data[0] || data == node->data[1])
{ 
printf("Element found\n");
return;
}
if(data < node->data[0])
search(node->left, data);
else if(data > node->data[1])
search(node->right, data);
else
search(node->mid, data);
}
}
int main()
{
int i=1, c, element;
while(i!=0)
{
printf("\n1.Insert\n2.Print\n3.Search\n4.Exit\n\n");
printf("Enter your choice\n");
scanf("%d", &c);
switch(c)
{
case 1: printf("Enter element to be inserted\n");
scanf("%d", &element);
addnode(element);
break;
printf("Printing the data stored at each node\n");
case 2: print(root);
break; 
case 3: printf("Enter element to be searched\n");
scanf("%d", &element);
search(root, element);
break;
default: i = 0;
}
}
return 0;
} 