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
class Solution {
public:
    void helper(TreeNode*root, int &ans, int curr){
        if(root){
            curr = (curr<<1) | root->val;
        if(!root->left && !root->right){
            ans+=curr;
            return;
        }
        helper(root->left,ans,curr);
        helper(root->right,ans,curr);
        }
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        helper(root,ans,0);
        return ans;
    }
};