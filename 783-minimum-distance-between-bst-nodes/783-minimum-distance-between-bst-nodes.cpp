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
    int diff=INT_MAX;
    void helper(TreeNode* root,TreeNode* &prev){
        if(root==NULL) return;
        helper(root->left,prev);
        if(prev){
            diff = min(diff, abs(root->val-prev->val));
        }
        prev=root;
        helper(root->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        helper(root,prev);
        return diff;
    }
};