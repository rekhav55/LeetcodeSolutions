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
    int maxLevel =0;
    void explore(TreeNode* root, int level)
    {
        maxLevel = max(maxLevel,level);
        if(root->left) explore(root->left, level+1);
        if(root->right) explore(root->right, level+1);
    }
    TreeNode* getLCA(TreeNode* root, int level)
    {
        if(!root) return NULL;
        if(level == maxLevel) return root;
        auto left = getLCA(root->left, level+1);
        auto right = getLCA(root->right, level+1);
        if (left && right ) return root;
        return left?left:right?right:NULL;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    explore(root,0);
    return getLCA(root, 0);
    }
//     int depth(TreeNode* root){
//         if(!root) return 0;
//         return 1+ max(depth(root->left),depth(root->right));
//     }
//     TreeNode* lca(TreeNode* root, int level, int curr){
//         if(!root) return NULL;
//         if(level==curr) return root;
//         auto left = lca(root->left,level,curr+1);
//         auto right = lca(root->right,level,curr+1);
//         if(left&&right) return root;
//         if(left) return left;
//         if(right) return right;
//         return NULL;
//     }
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         int d = depth(root);
//         return lca(root,d,0);
        
//     }
};