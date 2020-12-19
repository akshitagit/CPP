#include <bits/stdc++.h>
using namespace std;
//The node is the fundamental unit of the binary search tree. 
//It contains two pointers to point left and right child nodes and also contains data integer variable.
//It contains a function to initialise directly to the given data whenever a new node is created.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Function to insert a node according to the rules of a binary search tree.
Node* insertNode(Node* root, int d) {
    if (root == NULL) {
        return(new Node(d));
    } else if (d > root->data) {
        root->right = insertNode(root->right,d);
    } else if (d < root->data) {
        root->left = insertNode(root->left,d);
    }
    return(root);
}

//Function to find the Kth smallest element
Node* findKthSmallestElement(Node* root,int k) {
    //If root is NULL then return NULL
    if (root == NULL) {
        return(NULL);
    }
    //Check if kth smallest element is present in left subtree
    Node* left = findKthSmallestElement(root->left,k);
    //If left != NULL then kth smallest element is present in the left subtree.
    if (left != NULL) {
        return(left);
    }
    //Decrement k and check if k is 0. If k = 0 then that is the kth smallest element.
    --k;
    if (k == 0) {
        return(root);
    }
    //Find the kth smallest element in the right subtree.
    return(findKthSmallestElement(root->right,k));
}
int main() {
    //Input is in the form of array elements
    int arr[9] = {10,2,3,4,5,6,7,8,9};
    //Root initially set to NULL
    Node* root = NULL;
    //Insert array elements into the Binary Search Tree
    for (int i = 0;i < 9;i++) {
	root = insertNode(root,arr[i]);
    }
    //Set k to a particular value
    int k = 7;
    //The function findKthSmallestElement is called to get the Kth smallest element 
    Node* KthSmallestElement = findKthSmallestElement(root,k);
    //If Kth smallest element is NULL then the tree has less than K nodes else print the Kth smallest node.
    if (KthSmallestElement == NULL) {
	cout << "The tree has less than " << k << " nodes\n";
    } else {
	cout << KthSmallestElement->data << "\n";
    }
}

