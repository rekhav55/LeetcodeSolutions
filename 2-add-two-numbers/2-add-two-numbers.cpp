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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *curr = result;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int z = l1->val+l2->val+carry;
            carry = z/10;
            z = z%10;
            curr->next = new ListNode(z);
            curr = curr->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int z = l1->val + carry;
            carry = z/10;
            z = z%10;
            curr->next = new ListNode(z);
            curr = curr->next;
            l1=l1->next;
        }
         while(l2!=NULL){
            int z = l2->val + carry;
            carry = z/10;
            z = z%10;
            curr->next = new ListNode(z);
            curr = curr->next;
            l2=l2->next;
        }
        if(carry==1) curr->next = new ListNode(carry);
        return result->next;
    }
    
};