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
    unordered_map<int,int>mp;
    int maxCount = INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int L = helper(root->left);
        int R = helper(root->right);
        int sum = root->val+L+R;
        maxCount = max(maxCount,++mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> result;
        
        for(auto i:mp){
            if(i.second == maxCount) result.push_back(i.first);
        }
        return result;
    }
};