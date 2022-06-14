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
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        if(head==NULL || head->next==NULL) return NULL;
        int sum=0;
        ListNode* t = head->next;
        while(t!=NULL){
            if(t->val!=0){
                sum+=t->val;
            }
            else{
                ListNode* x = new ListNode(sum);
                temp->next = x;
                temp=temp->next;
                sum=0;
                
            }
            t=t->next;
        }
        return dummy->next;
    }
};