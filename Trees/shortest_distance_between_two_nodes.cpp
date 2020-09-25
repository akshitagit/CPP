#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

node *get_node(int val)
{
    node *temp = new node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

node *LCA(node *root, int l, int r)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == l || root->val == r)
    {
        return root;
    }

    node *left_half = LCA(root->left, l, r);
    node *right_half = LCA(root->right, l, r);

    if (left_half != NULL && right_half != NULL)
        return root;
    if (left_half == NULL)
        return right_half;
    if (right_half == NULL)
        return left_half;
}

int distance_from_root(node *root, int val)
{
    if (root == NULL)
        return -1;

    int dist = -1;
    if ((root->val == val) ||
        (dist = distance_from_root(root->left, val)) >= 0 ||
        (dist = distance_from_root(root->right, val)) >= 0)
        return dist + 1;

    return dist;
}

int distance(node *root, int a, int b)
{
    node *lca = LCA(root, a, b);

    int da = distance_from_root(root, a);
    if (da == -1)
        return -1;
    int db = distance_from_root(root, b);
    if (db == -1)
        return -1;

    int lcad = distance_from_root(root, lca->val);
    if (lcad == -1)
        lcad = 0;

    cout << da << " " << db << " " << lcad << endl;
    return da + db - (2 * lcad);
}

int main()
{
    node *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->right->left = get_node(6);
    root->right->right = get_node(7);
    cout << "Calculating LCA" << endl;
    cout << "distance of (4,5)"
         << " " << distance(root, 7, 4);
    return 0;
}