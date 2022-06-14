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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev;
        ListNode* nxt;
        int counter=1;
        ListNode* temp=list1;
        while(temp!=NULL){
            if(counter==a){
                prev=temp;
            }
            if(counter==b+1){
                nxt=temp;
                break;
            }
            counter++;
            temp=temp->next;
        }
        
        ListNode* h = list2;
        while(h->next!=NULL){
            h=h->next;
        }
        
        prev->next = list2;
        h->next=nxt->next;
        return list1;
    }
};