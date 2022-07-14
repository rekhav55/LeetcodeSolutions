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
    int inx = 0;
    TreeNode* helper(int lo, int hi, vector<int>& preorder, unordered_map<int,int> &inorder){
        if(lo > hi) {
            inx--;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[inx]);
        int indexInInorder = inorder[preorder[inx]];
        inx++;
        root->left = helper(lo, indexInInorder-1, preorder, inorder);
        inx++;
        root->right = helper(indexInInorder+1, hi, preorder, inorder);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mapp;
        for(int i = 0; i<inorder.size(); i++) mapp[inorder[i]] = i;
        return helper(0, preorder.size()-1, preorder, mapp);
    }
};