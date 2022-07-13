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
    vector<vector<int>>result;
    vector<int>v;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return result ;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()==false){
            int size = q.size();
            for(int j=0;j<size;j++){
                TreeNode* temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            result.push_back(v);
            v={};
            
            
        }
        return result;
    }
};