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
    void helper(TreeNode* root, unordered_map<int,int>&mp){
        if(!root) return;
        helper(root->left,mp);
        mp[root->val]++;
        helper(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        vector<int>res;
        int maxi=INT_MIN;
        helper(root,mp);
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        for(auto it:mp){
            if(it.second==maxi) res.push_back(it.first);
        }
        return res;
    }
};