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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>qu;
        qu.push(root);
        int ans;
        while(!qu.empty()){
            int size = qu.size();
            for(int i = 0; i<size; i++){
                TreeNode * curr = qu.front();
                qu.pop();
                if(i == 0){
                    ans = curr->val;
                }
                
                if(curr->left){
                    qu.push(curr->left);
                }
                
                if(curr->right){
                    qu.push(curr->right);
                }
            }
        }
        
        return ans;
    }
};