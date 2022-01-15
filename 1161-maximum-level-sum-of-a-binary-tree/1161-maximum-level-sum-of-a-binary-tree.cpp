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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        int ansSum = INT_MIN;
        int ans;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            level++;
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            if (sum > ansSum)
            {
                ansSum = sum;
                ans = level;
            }
        }
        return ans;
//         if(root==NULL) return 1;
//         int level =0,ans=root->val, possibleans;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             level++;
//             int res = 0;
//             for(int i=0;i<q.size();i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 res+=temp->val;
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right);
//             }
            
//             if(res>ans){
//                 ans = res;
//                 possibleans = level;
//             }
            
//         }
//         return possibleans;
    }
};