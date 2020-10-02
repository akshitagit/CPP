#include <iostream> 
using namespace std; 
  
template <typename T>         //created a template 
class BinaryTreeNode{                              // created a class of binary tree
  public :
  T data;
  BinaryTreeNode<T>* right;
  BinaryTreeNode<T>*left;
  
  BinaryTreeNode(T data){
    this->data = data;
    right = NULL;
    left = NULL;
  }
};
  

void printInorder(BinaryTreeNode<int>* node) 
{ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
    cout << node->data << " "; 
    printInorder(node->right); 
} 
  
int main() 
{ 
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1); 
    root->left = new BinaryTreeNode<int>(2); 
    root->right = new BinaryTreeNode<int>(3); 
    root->left->left = new BinaryTreeNode<int>(4); 
    root->left->right = new BinaryTreeNode<int>(5);  
  
    cout << "Inorder traversal of binary tree is "; 
    printInorder(root);  
  
   
} 
