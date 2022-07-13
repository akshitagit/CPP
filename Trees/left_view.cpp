#include <iostream>
#include <unordered_map>
using namespace std;
/*----------------------------------------------------------------------------
 This program will traverse and output the left view of a binary tree.
 This will be a recursive approach using hashing and a pre-order traversal
 run time O(n), Space O(n)
----------------------------------------------------------------------------*/

// as always with a tree we need nodes. Lets define the node first.
struct Node {
    int id;
    Node *left, * right;
    Node(int id) {
        this->id = id;
        this->left = this->right = nullptr;
    }
};

// we'll then write a recursive left view function and a print function. Well then test it out in the main function.
void leftview(Node *root, int level ,auto &map){
    if(root == nullptr) return;

// if this is the first time level has been visited update the map.
    if(map.find(level) == map.end()){
        map[level] = root->id;
    }
    leftview(root->left, level + 1, map);
    leftview(root->right, level +1, map);
}

// print
void print(Node *root){
   unordered_map<int, int> map; // make an empty map to fill with left view values.
    leftview(root, 1, map);
    for(int i = 1; i <= map.size(); i++)
        cout << map[i] << " ";
}
// test drive
int main() {        
    Node* root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
   
        print(root);
    return 0;
}