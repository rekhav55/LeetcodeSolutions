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
 long getSum(TreeNode* root, unordered_map<TreeNode*, long>& m)
    {
        if(!root) return 0;  
        return m[root] = getSum(root->left, m) + root->val + getSum(root->right, m);
    }
    
    void help(TreeNode* root, long& total, long long& ans, unordered_map<TreeNode*, long>& m)
    {
        if(!root) return;
        long long temp;
     
//         From this node either we can break from left or right so first breaking it from left
        if(root->left)
        {
            temp = (total-m[root->left])*m[root->left];
            ans = ans<temp?temp:ans;
        }
        
//         breaking it from right
        if(root->right)
        {
            temp = (total-m[root->right])*m[root->right];
            ans = ans<temp?temp:ans;
        } 
        help(root->left, total, ans, m);
        help(root->right, total, ans, m);
    }
    
public:
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, long> m;
        long total = getSum(root, m);
        long long ans=0;
        help(root, total, ans, m);
        long long mod = 1e9+7;
        return (ans % mod);
    }
};