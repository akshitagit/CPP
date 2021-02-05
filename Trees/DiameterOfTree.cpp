/*
The question link could be found at = https://leetcode.com/problems/diameter-of-binary-tree/

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
For every tree, we would be returning a structure info, which would contains following -

left - Maximum length of the path from the current node to any leaf node on the left side.
right - Maximum length of the path from the current node to any leaf node on the right side.
maxtillnow - Answer till now

For example, for a given below binary tree

    1
   / \
  2   3
 /     \
4       5

info of 1 would contains 2 as left, 2 as right and 4 as maxtillnow
*/
class Solution {
public:
    struct info{
        int left;
        int right;
        int maxtillnow;
    };
    info solve(TreeNode*root){
        if(root==NULL){
            return {-1,-1,0};
        }
        info l = solve(root->left); 
        info r = solve(root->right);
        info f;
        f.left = max(l.left,l.right)+1; //Maximum length of the path from the left side
        f.right = max(r.left,r.right)+1; //Maximum length of the path from the right side
        f.maxtillnow = max(f.left+f.right,max(r.maxtillnow,l.maxtillnow));
        return f;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        info ans = solve(root);
        return ans.maxtillnow;
    }
};
