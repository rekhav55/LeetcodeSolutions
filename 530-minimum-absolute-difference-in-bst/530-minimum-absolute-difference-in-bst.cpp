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
    vector<int>res;
    void preorder(TreeNode* root){
        if(root==NULL) return;
        preorder(root->left);
        res.push_back(root->val);
        preorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        preorder(root);
        int ans = INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            for(int j=i+1;j<res.size();j++){
                ans = min(ans, abs(res[i]-res[j]));
            }
        }
        return ans;
    }
};