/*Successful implementation of AVL tree with proper rotations
Code done by Parshwa Shah
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
int key;
struct node *left;
struct node *right;
int h;
};
struct node *root,*p;
int height(struct node *el)
{
if(el==NULL)
{return 0;}
else
{return el->h;}
}

int max1(int a,int b)
{
return (a>b)?a:b;
}
struct node* new(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->h= 1; // new node is initially added at leaf
	return(node);
}
struct node *leftrot(struct node *x)
{
struct node *y=x->right;
struct node *s=y->left;
y->left=x;
x->right=s;
x->h=max1(height(x->left),height(x->right))+1;
y->h=max1(height(y->left),height(y->right))+1;
return y;
}

struct node* rightrot(struct node *ele)
{
struct node *x=ele->left;
struct node *s=x->right;
x->right=ele;
ele->left=s;
ele->h=max1(height(ele->left),height(ele->right))+1;
x->h=max1(height(x->left),height(x->right))+1;
return x;
}

int getbal(struct node *s)
{
if(s==NULL)
return 0;
else
return (height(s->left)-height(s->right));
}

struct node* insert(struct node* ele,int ke)
{
int bal=0;
if(ele==NULL)
{
//printf("Key=%d Balance factor=0\n",ele->key);
return new(ke);
}
else if(ke>ele->key)
{
ele->right=insert(ele->right,ke);
}
else if(ke < ele->key)
{
ele->left=insert(ele->left,ke);
}
else
{
return ele;
}
ele->h=max1(height(ele->left),height(ele->right))+1;
bal=getbal(ele);
printf("Key=%d Balance factor=%d\n",ele->key,bal);
if(bal>1 && ke < ele->left->key)
{
printf("+++++++Left Left Rotation used+++++++\n");
return rightrot(ele);
}
else if(bal > 1 && ke > ele->left->key)
{
printf("+++++++Left Right Rotation used+++++++\n");
ele->left=leftrot(ele->left);
return rightrot(ele);
}
else if(bal<-1 && ke > ele->right->key)
{
printf("+++++++Right Right Rotation used+++++++\n");
return leftrot(ele);
}
else if(bal<-1 && ke<ele->right->key)
{
printf("+++++++Right Left Rotation used+++++++\n");
ele->right=rightrot(ele->right);
return leftrot(ele);
}
return ele;
}
struct node* inordersucc(struct node *ele)
{
struct node *curr=ele;
while(curr->left!=NULL)
{curr=curr->left;}
return curr;
}
struct node* delete(struct node *root,int key)
{
int bal=0;
if(root==NULL)
{return root;}
if(key<root->key)
{root->left=delete(root->left,key);}
else if(key>root->key)
{root->right=delete(root->right,key);}
else
{
if((root->left==NULL) || (root->right==NULL))
{
struct node *temp=root->left ? root->left:root->right;
if(temp==NULL)
{
temp=root;
root=NULL;
}
else
{
*root=*temp;
}
free(temp);
}
else
{
struct node *temp= inordersucc(root->right);
root->key=temp->key;
root->right=delete(root->right,temp->key);
}
}

if(root==NULL)
return root;

root->h=max1(height(root->left),height(root->right))+1;
bal=getbal(root);
printf("Key=%d Balance factor=%d\n",root->key,bal);
if(bal>1 && getbal(root->left)>=0)
{
printf("+++++++Left Left Rotation used+++++++\n");
return rightrot(root);
}
else if(bal > 1 && getbal(root->left)<0)
{
printf("+++++++Left Right Rotation used+++++++\n");
root->left=leftrot(root->left);
return rightrot(root);
}
else if(bal<-1 && getbal(root->right)<=0)
{
printf("+++++++Right Right Rotation used+++++++\n");
return leftrot(root);
}
else if(bal<-1 && getbal(root->right)>0)
{
printf("+++++++Right Left Rotation used+++++++\n");
root->right=rightrot(root->right);
return leftrot(root);
}
return root;
}
void inorder(struct node *root)
{
if(root==NULL)
{return;}
inorder(root->left);
printf("%d ",root->key);
inorder(root->right);
}
void main()
{
int key,m=0;
clrscr();
do
{
printf("Enter the key to insert or 0 to quit\n");
scanf("%d",&key);
if(key==0)
break;
if(m!=0)
{
printf("\n************************************\n\n");
root=insert(root,key);
printf("\n************************************\n");
}
else
{
printf("\n%d inserted\n",key);
root=insert(root,key);
m=1;
}
}
while(key!=0);
printf("Inorder traversal of tree : ");
inorder(root);
printf("\n\n");
//printf("inorder succ =%d",inordersucc(root)->key);
do
{
printf("Enter the key which you want to delete or 0 to quit\n");
scanf("%d",&key);
if(key==0)
break;
printf("\n************************************\n\n");
root=delete(root,key);
printf("\n************************************\n\n");
}
while(key!=0);
printf("Inorder traversal of tree : ");
inorder(root);
getch();
}