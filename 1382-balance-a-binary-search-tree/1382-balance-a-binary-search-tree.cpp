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
    vector<int>nums;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* makeTree(vector<int>num,int l, int r){
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode* newTree = new TreeNode(num[mid]);
        newTree->left = makeTree(num,l,mid-1);
        newTree->right = makeTree(num,mid+1,r);
        return newTree;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        inorder(root);
        TreeNode* newroot = makeTree(nums,0,nums.size()-1);
        return newroot;
    }
};