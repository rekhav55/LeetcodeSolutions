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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* btemp = before;
        ListNode* after = new ListNode(0);
        ListNode* atemp = after;
        while(head){
            if(head->val<x){
                btemp->next=head;
                btemp=head;
            }
            else{
                atemp->next=head;
                atemp=head;
            }
            
            head=head->next;
        }
        
        atemp->next=NULL;
        btemp->next=after->next;
        return before->next;
        
    }
};