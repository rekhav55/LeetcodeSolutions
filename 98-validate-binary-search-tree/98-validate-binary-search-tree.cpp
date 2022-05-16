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
    long long int pre=-2147483649;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = isValidBST(root->left);
        if(pre==-2147483649){
            pre=root->val;
        }
        else{
            if(pre>=root->val) return false;
            else pre=root->val;
        }
        bool right = isValidBST(root->right);
        return left&right;
    }
};