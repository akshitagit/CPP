#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int height(Node *node)
{
    if (node == NULL)
       return -1;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(lheight, rheight) + 1;
}

void print_level(Node *node, int level)
{
    if (node == NULL)
       return;
    else if (level == 0)
       cout << node->key << " ";
    else if (level > 0)
    {
        print_level(node->left, level-1);
        print_level(node->right, level-1);
    }
}

void levelorder_traversal(Node *root)
{
    
    for (int level=0; level <= height(root); level++)
        print_level(root, level);
}

int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);

    cout << "Levelorder Traversal using recursion: ";
    levelorder_traversal(root);
    cout << endl;
    return 0;
}