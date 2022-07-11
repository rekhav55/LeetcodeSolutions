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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool leftToRight = true; vector<vector<int>> res;
        deque<TreeNode*> q;
        q.push_back(root);
        while(q.size()){
            int n = q.size();
            vector<int> row;
            for(int i=0;i<n;i++){
                if(leftToRight) {
                    TreeNode* curr = q.front();q.pop_front();
                    row.push_back(curr->val);
                    if(curr->left)q.push_back(curr->left);
                    if(curr->right)q.push_back(curr->right);
                }else{
                    TreeNode* curr = q.back();q.pop_back();
                    row.push_back(curr->val);
                    if(curr->right)q.push_front(curr->right);
                    if(curr->left)q.push_front(curr->left);
                }
            }
            res.push_back(row);
            leftToRight=!leftToRight;
        }
        return res;
        
    }
};