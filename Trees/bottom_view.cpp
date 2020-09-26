#include <iostream>
#include <map>
using namespace std;

/*----------------------------------------------------------------------------
 This program will traverse and output the bottom view of a binary tree.
----------------------------------------------------------------------------*/
struct Node {
    int id;
    Node *left, * right;
    Node(int id) {
        this->id = id;
        this->left = this->right = nullptr;
    }
};
// pre order traversal of the tree; Fill our map. Our node has a horizontal length between the root of the tree and level represent level
// of the node..
void printBottom (Node* node, int len, int ro, auto & map) {
    if (node == nullptr) return;
    /*  if the cur node is greater than or equal to the largest row seen for the same horizontal distance or the horizontal distance is seen for the first time, update the map */
    if (ro >= map[len].second) {
        // update ro, len
        map[len] = { node->id, ro};
    }
    //  for the left subtree by decreasing horizontal and increasing the level
    //  distance by 1
    printBottom(node->left, len - 1, ro + 1, map);

    // the right subtree by increasing the horizontal and level by 1
    printBottom(node->right, len + 1, ro + 1, map);
}

// print
    void print (Node* root) {
    // create an empty map of {id, pair} relative to horizontal distance of the node from root node
    
        map<int, pair<int, int>> map;

    // do pre order traversal of the tree and fill te map
    printBottom(root, 0, 0, map);

    // traverse the map and print bottom view
    for (const auto &i : map)
        cout << i.second.first << " ";
};
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