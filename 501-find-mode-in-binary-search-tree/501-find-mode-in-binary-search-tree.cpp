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
    void inorder(TreeNode* root,int &prev, int &curr, int &max, vector<int>&res){
        if(!root) return;
        inorder(root->left,prev,curr,max,res);
        if(prev==root->val){
            curr++;
        }
        else{
            prev=root->val;
            curr=1;
        }
        if(curr==max){
            res.push_back(root->val);
        }
        else if(curr>max){
            res={root->val};
            max=curr;
        }
        inorder(root->right,prev,curr,max,res);
    }
    vector<int> findMode(TreeNode* root) {
        int prev=0,max=0,curr=0;
        vector<int>res;
        inorder(root,prev,curr,max,res);
        return res;
    }
};