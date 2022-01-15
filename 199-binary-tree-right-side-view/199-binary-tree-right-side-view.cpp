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
    int maxlevel = 0;
    void helper(TreeNode* root, vector<int>&res, int currLevel){
        if(root){
            if(currLevel>maxlevel){
                res.push_back(root->val);
                maxlevel=currLevel;
            }
            helper(root->right,res,currLevel+1);
            helper(root->left,res,currLevel+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>res;
        // if(!root) return {};
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int sz=q.size();
        //     for(int i=0;i<sz;i++){
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         if(i==sz-1) res.push_back(temp->val);
        //         if(temp->left) q.push(temp->left);
        //         if(temp->right) q.push(temp->right);
        //     }
        // }
        // return res;
        vector<int>res;
        helper(root,res,1);
        return res;
    }
};