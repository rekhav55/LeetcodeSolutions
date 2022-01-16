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
    void inorder(TreeNode* root, vector<int>&tree){
        if(root==NULL) return;
        inorder(root->left,tree);
        tree.push_back(root->val);
        inorder(root->right,tree);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>tree;
        inorder(root,tree);
        int low=0,high=tree.size()-1;
        // if(tree.size()==1){
        //     if(tree[0]==k) return true;
        //     return false;
        // }
        
           while(low<high){
            if(tree[low]+tree[high]==k) return true;
            else if(tree[low]+tree[high]>k) high--;
            else low++;
           } 
        
        
        return false;
    }
};