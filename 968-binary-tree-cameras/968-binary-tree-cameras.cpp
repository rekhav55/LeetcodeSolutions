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
     int cameraCount = 0;
    int needsCamera = 0;
    int hasCamera = 1;
    int covered = 2;
    int notNeeded = 3;
public:
    int getnodeStatus(TreeNode* root)
    {
        if(root==NULL)
        {
            return notNeeded;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return needsCamera;
        }
        int left = getnodeStatus(root->left);
        int right = getnodeStatus(root->right);
        if(left==needsCamera || right==needsCamera)
        {
            cameraCount++;
            return hasCamera;
        }
        if(left==hasCamera || right==hasCamera)
        {
            return covered;
        }
        return needsCamera;
    }
    int minCameraCover(TreeNode* root) {
        cameraCount = getnodeStatus(root)==needsCamera?cameraCount+1:cameraCount;
        return cameraCount;
    }
};