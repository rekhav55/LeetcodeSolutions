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
    TreeNode* makeTree(vector<int>&nums, int l, int r){
        if(l>r) return NULL;
        // if(l==r) return new TreeNode(nums[l]);
        int mid = l + (r-l)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = makeTree(nums,l,mid-1);
        newNode->right = makeTree(nums,mid+1,r);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return makeTree(nums,0,nums.size()-1);
    }
};