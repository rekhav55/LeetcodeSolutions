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
    int helper(TreeNode* root, int CurrMax, int CurrMin){
        if(root==NULL) return CurrMax-CurrMin;
        CurrMax = max(root->val,CurrMax);
        CurrMin = min(root->val,CurrMin);
        int left = helper(root->left,CurrMax,CurrMin);
        int right = helper(root->right,CurrMax,CurrMin);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
       if(root==NULL) return 0;
       return helper(root, root->val, root->val); 
    }
};