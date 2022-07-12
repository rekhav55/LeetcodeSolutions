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
     void inOrderTraversal(TreeNode* root, int& currentMin, int rootVal) {
        if (root == NULL)
            return;
        
        inOrderTraversal(root->left, currentMin, rootVal);
        
        if (root->val != rootVal) {
            if (currentMin == 0)
                currentMin = root->val;
            else
                currentMin = min(currentMin, root->val);
        }
        
        inOrderTraversal(root->right, currentMin, rootVal);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int secondMin = 0;
        
        if (root == NULL)
            return -1;
        
        inOrderTraversal(root, secondMin, root->val);
        
        return secondMin == 0 ? -1 : secondMin;
    }
};