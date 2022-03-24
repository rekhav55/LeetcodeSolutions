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
    map<int, map<int, vector<int>>> ds;
    void fillTheDs(TreeNode* root, int hz, int level){
        if(root == NULL)
            return;
        
        ds[hz][level].push_back(root->val);
        
        fillTheDs(root->left, hz-1, level+1);
        fillTheDs(root->right, hz+1, level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> result;
        ds.clear();
        
        fillTheDs(root, 0, 1);
        //cout<<ds.size()<<" ";
        
        for(auto hz : ds){  //from min hz to max hz
            vector<int> temp;
            
            for(auto level : hz.second){  //from min level to max level
                sort(level.second.begin(), level.second.end()); //each level shud be sorted
                temp.insert(temp.end(), level.second.begin(), level.second.end());               
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};