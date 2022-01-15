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
    vector<TreeNode*>temp;
    void helper(TreeNode* &root,vector<TreeNode*>&temp,unordered_set<int>del){
        if(root!=NULL){
            helper(root->left,temp,del);
            helper(root->right,temp,del);
            if(del.find(root->val)!=del.end()){
                if(root->left) temp.push_back(root->left);
                if(root->right) temp.push_back(root->right);
                root=NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL) return {};
        unordered_set<int> del(to_delete.begin(),to_delete.end());
        helper(root,temp,del);
        if(root) temp.push_back(root);
        return temp;
    }
};