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
    map<int,int>mp;
    void findele(TreeNode* root, bool x){
        if(root==NULL) return;
        if(x==true){
            root->val=0;
            mp[root->val]++;
            if(root->left){
                root->left->val=2*root->val + 1;
                mp[root->left->val]++;
                findele(root->left,false);
            }
            if(root->right){
                root->right->val=2*root->val+2;
                mp[root->right->val]++;
                findele(root->right,false);
            }
        }
        else{
            if(root->left){
                root->left->val=2*root->val + 1;
                mp[root->left->val]++;
                findele(root->left,false);
            }
            if(root->right){
                root->right->val=2*root->val+2;
                mp[root->right->val]++;
                findele(root->right,false);
            }
        }
    }
    FindElements(TreeNode* root) {
        findele(root,true);
    }
    
    bool find(int target) {
        if(mp[target]>0) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */