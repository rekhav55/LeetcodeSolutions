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
class CBTInserter {
public:
    TreeNode * rt;
    CBTInserter(TreeNode* root) {
        rt=root;
    }
    
    int insert(int val) {
        queue<TreeNode*>q;
        q.push(rt);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left==NULL){
                    // TreeNode* curr = new TreeNode(val);
                    temp->left=new TreeNode(val);
                    return temp->val;
                }
                else q.push(temp->left);
                if(temp->right==NULL){
                    // TreeNode* curr = new TreeNode(val);
                    temp->right=new TreeNode(val);
                    return temp->val;
                }
                else q.push(temp->right);
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return rt;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */