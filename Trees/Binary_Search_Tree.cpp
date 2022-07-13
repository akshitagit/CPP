// Binary Search tree Implementation with insertion,peorder traversal 
// and height finding utilities
#include<bits/stdc++.h>
using namespace std;
// Structure for Node
struct node{
    struct node * left=NULL;
    struct node * right=NULL;
    int key;
}
;
//Utility to create a node
struct node *createNode(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key=data;
    return temp;
}
// Utitilty to insert a node in BST
struct node *insertBST(struct node* root,int data )
{
    if(root==NULL)
    {
        return createNode(data);
    }
    else
    {
        if(data<=root->key)
        {
            root->left=insertBST(root->left,data);
        }
        else
        {
            root->right=insertBST(root->right,data);
        }
    }
    
    return root;
}
// Utility to find the height of the BST from root
int height(struct node *root)
{
    if(root==NULL)
    return -1;
    
    else
    {
        int hleft=height(root->left);
        int hright=height(root->right);
        
        return max(hleft,hright)+1;
    }
}
// Utility to get preorder traversal of the BST
void preorder(struct node* root)
{
    if(root==NULL)
    return ;
    
    else
    {
        preorder(root->left);
       
        cout<<root->key<<" ";
        
         preorder(root->right);
        return;
    }
}
// Driver Function
int main()
{
    char ch='y';
    int x;
    cout<<"Want to enter a node in BST(Y/y)=";
    cin>>ch;
    struct node *root=NULL;
    while(ch=='y')
    {
        cin>>x;
        root=insertBST(root,x);
        cout<<endl;
        cout<<"Want to enter anothe node?(Y/y)=";
        cin>>ch;
        
        
    }
    
    int hght=height(root);
    cout<<"\nHeight of the enterd BST="<<hght;
    cout<<endl;
    
    preorder(root);
    return 0;
    
}