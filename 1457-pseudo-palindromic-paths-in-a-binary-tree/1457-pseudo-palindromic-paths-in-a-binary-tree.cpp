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
     int ans = 0;    
    void countPaths(TreeNode* root, int path){
        if(!root) return;
        
        path ^= (1 << root->val);
        
        if(!root->left && !root->right){
            
            if((path & (path-1)) == 0) ans++;
            
            return;
        }
        
        countPaths(root->left, path);
        countPaths(root->right, path);
        
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        countPaths(root,0);
        return ans;
    }
};