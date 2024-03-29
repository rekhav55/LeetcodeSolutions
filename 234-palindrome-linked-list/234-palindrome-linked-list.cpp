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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        
        temp->next=NULL;
        ListNode* rev = reverse(slow);
        ListNode* t=head;
        while(rev && t){
            if(t->val!=rev->val) return false;
            rev=rev->next;
            t=t->next;
        }
        return true;
        
    }
};