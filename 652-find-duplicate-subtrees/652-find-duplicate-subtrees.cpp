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
    string solve(TreeNode* root, unordered_map<string, int>& map,vector<TreeNode*> &ans){
        if(root == NULL){
            return "$";
        }

        string temp = to_string(root->val) + "&"+ solve(root->left,map,ans) +"&"+ solve(root->right,map,ans);;
        map[temp]++;
        if(map[temp] == 2)
            ans.push_back(root);
        
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> map;
        vector<TreeNode*> ans;
        if(root==NULL){
            return ans;
        }
        solve(root,map,ans);

        return ans;
    }
};