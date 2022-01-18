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
    void helper(TreeNode* root, int &diff,TreeNode* &prev){
        if(root==NULL) return;
        helper(root->left,diff,prev);
        if(prev){
            diff = min(diff, abs(root->val-prev->val));
        }
        prev=root;
        helper(root->right,diff,prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int diff=INT_MAX;
        helper(root,diff,prev);
        return diff;
    }
};