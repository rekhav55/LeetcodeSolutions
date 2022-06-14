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
class Solution {
public:
    ListNode *merge(ListNode* left, ListNode* right){
        ListNode* l1 = left;
        ListNode* l2 = right;
        if(l1->val>l2->val){
            swap(l1,l2);
        }
        ListNode* dummy = l1;
        
        while(l1 && l2){
            ListNode* temp = l1;
            while(l1 && l1->val <= l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return dummy;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left,right);
    }
};