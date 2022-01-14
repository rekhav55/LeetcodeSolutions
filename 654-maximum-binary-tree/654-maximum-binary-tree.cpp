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
    int getIndex(vector<int>arr,int l, int r){
        int maxi = arr[l];
        int idx = l;
        for(int i=l;i<=r;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* makeTree(vector<int>arr,int l,int r){
        if(l>r) return NULL;
        int idx = getIndex(arr,l,r);
        TreeNode* newTree = new TreeNode(arr[idx]);
        newTree->left = makeTree(arr,l,idx-1);
        newTree->right = makeTree(arr,idx+1,r);
        return newTree;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        TreeNode* root = makeTree(nums,0,nums.size()-1);
        return root;
    }
};