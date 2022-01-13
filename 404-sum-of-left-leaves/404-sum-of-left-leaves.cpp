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
    int res=0;
    void leafHelper(TreeNode* root){
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right) res+=root->left->val;
        else{
            leafHelper(root->left);
        }
            leafHelper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        leafHelper(root);
        return res;
    }
};