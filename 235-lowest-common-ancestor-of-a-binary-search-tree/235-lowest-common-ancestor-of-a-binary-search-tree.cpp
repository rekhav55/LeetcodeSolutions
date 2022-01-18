/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root, TreeNode* &p, vector<TreeNode*>&path){
        if(root==NULL) return;
        path.push_back(root);
        if(root->val==p->val) return;
        if(p->val<root->val) helper(root->left,p,path);
        if(p->val>root->val) helper(root->right,p,path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        TreeNode* ans;
        helper(root,p,path1);
        helper(root,q,path2);
        int mini = min(path1.size(),path2.size());
        for(int i=0;i<mini;i++){
            if(path1[i]->val==path2[i]->val) ans=path1[i];
        }
        return ans;
    }
};