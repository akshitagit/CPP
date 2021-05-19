#include <iostream>
using namespace  std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        this->left = this->right = nullptr;
    }
};
// Function to find k smallest element
Node* kSmall (Node* root, int& k) {
    if (root == NULL) return NULL;   // base
    Node* left = kSmall(root->left, k);   // go left
    if(left != NULL) return left;  // return kth small if we find it
     k--;  if (k == 0) return root; // if the current element is the kth smallest return it
    return kSmall(root->right, k); // otherwise go right
}
// function to print the smallest element
void psmall (Node* root, int k) {
    Node* ans = kSmall(root, k);
    if(ans == NULL)
        cout << "Number of nodes is less than k" << endl;
    else
        cout << " k smallest element is: " << ans->data << endl;
}
// function to set elements 
Node* set (Node* root, int val) {
    if (root == NULL)
    return new Node(val);
    if (val < root->data)
        root->left = set(root->left, val);
        else if (val > root->data)
            root->right = set(root->right, val);
    return root;
}
// Test Drive
int main() {
    Node* root = NULL;
    int elms[] = { 13, 2, 33, 18, 99, 5, 12, 40, 21, 86, 25 };
    for (int i : elms)
        root = set(root, i);

    int kth = 5; psmall(root, kth);
    return 0;
}