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
    int helper(TreeNode* root, int m){
        if(root==NULL) return 0;
        m = max(root->val,m);
        int left = helper(root->left,m);
        int right = helper(root->right,m);
        if(m<=root->val){
            return 1+left+right;
        }
        else return left+right;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int m = INT_MIN;
        return helper(root,m);
    }
};