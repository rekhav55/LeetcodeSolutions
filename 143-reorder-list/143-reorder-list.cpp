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
        ListNode* curr=NULL;
        while(head){
            ListNode* next = head->next;
            head->next=curr;
            curr=head;
            head=next;
        }
        return curr;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp=NULL;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        temp->next=NULL;
        ListNode* rev = reverse(slow);
        
        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;
        ListNode* l1 = head;
        ListNode* l2=rev;
        while(l1 && l2){
            ListNode* l1nxt = l1->next;
            ListNode* l2nxt = l2->next;
            t->next = l1;
            l1->next=l2;
            t = l2;
            l1=l1nxt;
            l2=l2nxt;
        }
        // t->next=NULL;
        
    }
};