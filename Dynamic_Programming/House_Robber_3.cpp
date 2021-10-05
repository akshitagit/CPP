/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

/*
Solution: At every node the thief has two options to rob the current node and not rob any of    its children or else he can leave the current node as it is and rob the other houses in the subtree of the current node
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,int>maxAmount(TreeNode *root)
{
    if(root==nullptr)
        return {0,0};
        
    pair<int,int>l=maxAmount(root->left);
    pair<int,int>r=maxAmount(root->right);
        
    int robberyincludingthis=root->val+l.second+r.second;
    int robberyexcludingthis=max({r.first+l.first,r.second+l.second,r.first+l.second,l.first+r.second});
        
    return {robberyincludingthis,robberyexcludingthis};
}
    
int rob(TreeNode* root) {
    pair<int,int>p=maxAmount(root);
    return max(p.second,p.first);
}