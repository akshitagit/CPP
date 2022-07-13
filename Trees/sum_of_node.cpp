/* We are giving root to function sumOfNodes and this function simply return sum of nodes */
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryNode{         // class BinaryNode
    public : 
   T data;
   BinaryNode<T>*right;
   BinaryNode<T>*left;
    BinaryNode(T data){             // constructor
        this->data = data;
        right = NULL;
        left = NULL ;
    }
};

int sumOfNodes(BinaryNode<int>*root){        // function which calculates sum of nodes 
   if(root == NULL){
       return 0;}
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    
    return (root->data + leftSum + rightSum);
}
int main()
{
   BinaryNode<int>*root = new BinaryNode<int>(1); 
	root->left = new BinaryNode<int>(2); 
	root->right = new BinaryNode<int>(3); 
	root->left->left = new BinaryNode<int>(4); 
	root->left->right = new BinaryNode<int>(5); 
    
    int sumNodes = sumOfNodes(root);
    
    cout<<"Sum of Nodes : "<<sumNodes<<endl;      // printing sum of nodes of tree
}
