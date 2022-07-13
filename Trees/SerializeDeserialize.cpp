class Solution
{
    public:
    
    //Function to store the nodes of tree in the list.
    void serializeUtil(Node*root,vector<int>&a)
    {
        //base case if node is null.
        if (root == NULL) {
            a.push_back(-1);
            return;
        }
        //storing the data at node in list.
        a.push_back(root->data);
        
        //calling function recursively for left and right subtrees.
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> serialized;
        serializeUtil(root,serialized);
        
        //returning the list.
        return serialized;
    }
    
    
    //Function to construct the tree.
    Node *kewl(vector<int> &a, int *index) 
    {
        //base case if there are no more elements in list.
        if (*index == a.size() or a[*index] == -1) {
            *index += 1;
            return NULL;
        }
        
        //creating new node for storing current element.
        Node *root = new Node(a[*index]);
        *index += 1;
        
        //calling function recursively for left and right subtrees. 
        root->left = kewl(a, index);
        root->right = kewl(a, index);
        return root;
    }
    
    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &a) 
    {
        int index = 0;
        //returning the tree.
        return kewl(a, &index);
    }
};
