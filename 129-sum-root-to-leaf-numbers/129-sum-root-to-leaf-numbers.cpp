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
    void DFS(TreeNode* root, int &ans, int curr)
    {
        curr = curr*10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            ans += curr;
            return;
        }
        if(root->left != NULL)
            DFS(root->left, ans, curr);
        if(root->right != NULL)
            DFS(root->right, ans, curr);        
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        DFS(root, ans, 0);
        return ans;
    }
};