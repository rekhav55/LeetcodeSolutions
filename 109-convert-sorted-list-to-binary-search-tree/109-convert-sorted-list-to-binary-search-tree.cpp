/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     ListNode* findTheMiddle(ListNode* head, ListNode* tail) {
        if(!head)return head;
        
        auto slow = head;
        auto fast = head;
        
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    TreeNode* buildBST(ListNode* head, ListNode* tail){
        if(!head)return nullptr;
        if(head==tail)return nullptr;
        
        auto mid = findTheMiddle(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildBST(head, mid);
        root->right = buildBST(mid->next, tail);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
        
        
    }
};