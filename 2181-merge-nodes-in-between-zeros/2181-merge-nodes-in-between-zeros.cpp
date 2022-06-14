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
    ListNode* mergeNodes(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* temp=dummy;
//         if(head==NULL || head->next==NULL) return NULL;
//         int sum=0;
//         ListNode* t = head->next;
//         while(t!=NULL){
//             if(t->val!=0){
//                 sum+=t->val;
//             }
//             else{
//                 ListNode* x = new ListNode(sum);
//                 temp->next = x;
//                 temp=temp->next;
//                 sum=0;
                
//             }
//             t=t->next;
//         }
//         return dummy->next;
        if(head==NULL || head->next ==NULL)
    {
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    int sum=0;
    while(fast!=NULL)
    {
        if(fast->val == 0 && fast->next!=NULL)
        {
            slow->val = sum;
            slow=slow->next;
            sum=0;
        }
        else
        {
             sum = sum+fast->val;
        }
        fast=fast->next;
    }
    slow->val =sum;
    slow->next = NULL;
    return head;

    }
};