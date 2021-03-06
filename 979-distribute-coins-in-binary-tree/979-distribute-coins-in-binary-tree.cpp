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
    int ans;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans+= abs(left)+abs(right);
        return root->val-1 + left+right;
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL) return 0;
        ans=0;
        helper(root);
        return ans;
    }
};