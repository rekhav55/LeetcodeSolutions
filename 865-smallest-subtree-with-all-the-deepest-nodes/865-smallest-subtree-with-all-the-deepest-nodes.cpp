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
    int maxLevel=0;
    void depth(TreeNode* root,int level){
        if(!root) return;
        maxLevel=max(maxLevel,level);
        depth(root->left,level+1);
        depth(root->right,level+1);
    }
    
    TreeNode* lca(TreeNode* root, int level){
        if(!root) return NULL;
        if(level==maxLevel) return root;
        auto left = lca(root->left,level+1);
        auto right = lca(root->right,level+1);
        if(left&&right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);
        return lca(root,0);
    }
};