#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

};
node *create(int val)
{
    node *newnode = new node();

    if (!newnode)
        return nullptr;

    newnode->data = val;
    newnode->left = newnode->right = nullptr;
}
node *insertNode(int data, node *root)
{

    if (root == nullptr)
    {
        root = create(data);
        return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left != nullptr)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = create(data);
            return root;
        }
        if (temp->right != nullptr)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = create(data);
            return root;
        }
    }
}
// inorder traversal
void inorder(node *&root,vector<int>&v)
{
    if (root == nullptr)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
bool checkBST(node *&root,vector<int>&v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]) return false;
    }
    return true;
}

int main(){
    node *root = create(10);
    insertNode(20, root);
    insertNode(30, root);
    insertNode(40, root);
    insertNode(50, root);
    vector<int>v;
    inorder(root,v);
    if(checkBST(root,v)){
        cout<<"Given tree is binary search tree !";
    }
    else{
        cout<<"not a binary search tree !!";
    }

    return 0;
}