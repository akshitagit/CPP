#include<bits/stdc++.h>
using namespace std;

//making a binary tree node
struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int x)
  {
    data=x;
    left=right=NULL;
  }
};

//code for preorder travel for the binary tree
void Preorder(Node* root)
{
  if(root==NULL)
  return ;
  
  cout<<root->data<<" ";
  Preorder(root->left);
  Preorder(root->right);
}

Node* buildTree(int inorder[],int post[],int n);

int main()
{
  int n;
  cin>>n;
  
  int inorder[n];
  for(int i=0;i<n;i++)
  cin>>inorder[i];
  
  int postorder[n];
  for(int i=0;i<n;i++)
  cin>>postorder[i];
  
  Node* root=buildTree(inorder,postorder,n);
  preorder(root);
  cout<<"\n";
  
  return 0;
}

// to find index in inorder array
int index(int in[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==x)
        return i;
    }
    //if key not found
    return -1;
}


Node *buildTree(int in[], int post[], int n) {
    int i=n-1;
    Node* root=new Node(post[i]);
    int rootindex=index(in,n,post[i]);

    
    //left
    if(rootindex!=0)
    {
        root->left=buildTree(in,post,rootindex);
    }
    
    //right
    if(rootindex!=n-1)
    {
        root->right=buildTree(in+rootindex+1,post+rootindex,n-rootindex-1);
    }
    
    return root;
}



