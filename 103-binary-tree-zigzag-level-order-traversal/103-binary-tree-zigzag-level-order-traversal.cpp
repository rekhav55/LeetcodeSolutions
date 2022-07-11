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
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        int i = 0;
        q.push(root);
        vector<int> v1;
        v1.push_back(root->val);
        ans.push_back(v1);
        i++;
        while(!q.empty()){
            
            int n =  q.size();
            vector<int> temp;
           
            while(n--){
                 auto it = q.front();
                q.pop();
                
                if(i%2==0){
                    if(it->left!=NULL){
                        temp.push_back(it->left->val);
                        q.push(it->left);
                    }
                    if(it->right!=NULL){
                        temp.push_back(it->right->val);
                        q.push(it->right);
                    }
                }
                else{
                    
                      if(it->left!=NULL){
                        s.push(it->left);
                        q.push(it->left);
                    }
                    if(it->right!=NULL){
                        s.push(it->right);
                        q.push(it->right);
                    }
                }
              
                
            }
              while(!s.empty()){
                    temp.push_back(s.top()->val);
                    s.pop();
                }
            if(temp.size()>0)
            ans.push_back(temp);
            ++i;
        }
        return ans;
        
        
    }
};