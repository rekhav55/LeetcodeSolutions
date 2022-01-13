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
    void leafHelper(TreeNode* root, bool isLeft){
        if(isLeft && !root->left && !root->right){
            res+=root->val;
        }
        if(root->left) leafHelper(root->left,true);
        if(root->right) leafHelper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        leafHelper(root,false);
        return res;
    }
};