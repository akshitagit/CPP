#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int value) {
	    val=value;
		left=NULL;
		right=NULL;
	}
};
void inorder_traversal(Node * root) {
	if(root==NULL)
		return;
	inorder_traversal(root->left);
	cout<<root->val<<" ";
	inorder_traversal(root->right);
}

int main() 
{ 
    struct Node *root = new Node(1); 
    root->left= new Node(2); 
    root->right= new Node(3); 
    root->left->left= new Node(4); 
    root->left->right= new Node(5);  
    cout << "\nInorder traversal of binary tree is \n"; 
    inorder_traversal(root); 
    return 0; 
}
