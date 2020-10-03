Node *minimum(Node *p)
{
    while(p && p->left)
    p=p->left;
    return p;
}

Node *deleteNode(Node *root,  int x)
{
    if(root==NULL)
    return NULL;
    else if(x<root->data) root->left=deleteNode(root->left,x);
    else if (x>root->data) root->right=deleteNode(root->right,x);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            Node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            Node *temp=minimum(root->right);
            root->data=temp->data;
            root->right = deleteNode(root->right,root->data);
        }
        
    }
    return root;
    
}

int main()
{
	/*create tree on your own 
	and call the delete node function*/
	return 0;
}