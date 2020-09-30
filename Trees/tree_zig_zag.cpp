//This program implements Zig Zag traversal of a Binary Tree

//Time Complexity: O(n)

#include<iostream>
#include<stack>

struct Node{
    int data;
    Node* left,*right;
};

Node* Insert(int data){
    Node* new_node=new Node();
    new_node->data=data;
    new_node->left=nullptr;
    new_node->right=nullptr;
    return new_node;
}

void ZigZagTraversal(Node* root){
    if(!root){
        return;
    }
    std::stack<Node*> currenstack;
    std::stack<Node*> nextstack;

    currenstack.push(root);

    bool leftToright=true;
    while(!currenstack.empty()){
        Node* temp=currenstack.top();
        currenstack.pop();
        if(temp){
            std::cout<<temp->data<<" ";
            if(leftToright){
            if(temp->left){
                nextstack.push(temp->left);
            }
            if(temp->right){
                nextstack.push(temp->right);
            }
        }
        else{
           if(temp->left){
               nextstack.push(temp->left);
           }
           if(temp->right){
               nextstack.push(temp->right);
           }

        }
        }
        if(currenstack.empty()){
        leftToright=!leftToright;
        std::swap(currenstack,nextstack);

    }
        
    }
 
}

int main(){
    Node* root=Insert(3);
    root->left=Insert(4);
    root->right=Insert(5);
    root->left->left=Insert(6);
    root->left->right=Insert(2);
    root->right->left=Insert(9);
    root->right->right=Insert(10);

    std::cout<<"Zig Zag traversal of Binary Tree: "<<std::endl;

    ZigZagTraversal(root);

    return 0;
}