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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *temp = head;
        ListNode *temp1=head;
        ListNode *temp2 = NULL;
         int count = 1;
         while(temp->next!=NULL){
            count++;
            temp=temp->next;
         }
        count-=n;
        if(count==0) return head->next;
        while(count!=0){
            temp2=temp1;
            temp1=temp1->next;
            count--;
        }
        temp2->next=temp1->next;
        delete temp1;
        return head;
    }
};