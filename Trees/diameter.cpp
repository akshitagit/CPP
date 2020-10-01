#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node *left, *right;
    Node(){
        val=0;
        left=right=NULL;
    }
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
    Node(int x, Node* left, Node* right){
        val=x;
        this->left=left;
        this->right=right;
    }
};
//This will ensure the diameter of a tree has O(n) complexity
//First elem contains the diameter
//Second elem contains the height;
pair<int, int> diameter(Node* head){
    if(head==NULL) return {0, 0};
    pair<int, int> left = diameter(head->left), right = diameter(head->right);
    pair<int, int> ans;
    ans.second = max(left.second+1, right.second+1);
    ans.first = max(left.first, max(right.first, left.first+right.first+1));
    return ans;
}
int main(){

}