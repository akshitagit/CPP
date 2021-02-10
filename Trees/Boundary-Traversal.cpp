/*
The Problem is to print Boundary elements of a binary tree
For Example, Lets say our tree is 
                      0
                   /     \
                  5       6 
                / \      /  \
               9    65  7   10
             /  \  /  \
            8   12 1    98

            Then its output should be
            0->5->9->8->12->1->98->7->10->6

            My approach for this problem is to split this problem into three simpler problems
            1. Printing the Left Part of boundary ( excluding the leaf in left part)
            2. Printing the leaves of tree
            3. Printing the right part in bottom up manner ( excluding the leaf in right part)

*/
#include <iostream>
#include <stack>
using namespace std;
template <typename T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T vl) // This Constructor helps in Creating a new Tree node with value vl
    {
        val = vl;
        left = NULL;
        right = NULL;
    }
    TreeNode(T vl, TreeNode *lft, TreeNode *rt)
    {
        val = vl;
        left = lft;
        right = rt;
    }
    void addChilds(T lVal, T rVal)
    {
        TreeNode *lft = new TreeNode(lVal);
        TreeNode *rt = new TreeNode(rVal);
        left = lft;
        right = rt;
    }
};

template <typename T>
void printLeftPart(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    cout << root->val << " ";
    printLeftPart(root->left);
}
template <typename T>
void printRightPart(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    printRightPart(root->right);
    cout << root->val << " ";
}
template <typename T>
void printLeaves(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}
template <typename T>
void printBoundary(TreeNode<T> *root)
{
    cout << "Boundary Elements are : ";
    printLeftPart(root);
    printLeaves(root);
    printRightPart(root->right);
    cout << "\n";
}
int main()
{
    TreeNode<int> root(0);
    root.addChilds(5, 6);
    root.left->addChilds(9, 65);
    root.left->left->addChilds(8, 12);
    root.left->right->addChilds(1, 98);
    root.right->addChilds(7, 10);
    printBoundary(&root);
    //cout << root.val << " " << root.left->val << " " << root.right->val;
    //printInorder(&root);
    return 0;
}