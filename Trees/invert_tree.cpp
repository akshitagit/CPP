//This program inverts a Binary Tree

#include<iostream>


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

void Display(Node* root){
    if(root==nullptr){
        return;
    }
    Display(root->left);
    std::cout<<root->data<<" ";
    Display(root->right);
}

void Invert(Node* root){
    if(root==nullptr){
        return;
    }
    else{
        Node* temp;
        Invert(root->left);
        Invert(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}

int main(){
    Node* root=Insert(3);
    root->left=Insert(4);
    root->right=Insert(5);
    root->left->left=Insert(9);
    root->left->right=Insert(10);
    Display(root);
    Invert(root);
    std::cout<<"\nBinary Tree after Inversion: \n";
    Display(root);
    return 0;
}