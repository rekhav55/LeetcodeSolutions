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
class FindElements {
public:
    set<int>mp;
    void findele(TreeNode* root){
        if(root==NULL) return;
            if(root->left){
                root->left->val=2*root->val + 1;
                mp.insert(root->left->val);
                findele(root->left);
            }
            if(root->right){
                root->right->val=2*root->val+2;
                mp.insert(root->right->val);
                findele(root->right);
            }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        mp.insert(root->val);
        findele(root);
    }
    
    bool find(int target) {
        return mp.find(target)!=mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */