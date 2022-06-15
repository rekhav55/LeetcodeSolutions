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
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=NULL;
        while(head){
            ListNode* next = head->next;
            head->next=curr;
            curr=head;
            head=next;
        }
        return curr;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* t = head;
        ListNode* revhead;
        ListNode* revend;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(head){
            if(cnt==left){
                revhead=head;
            }
            if(cnt==right){
                revend=head;
                next=head->next;
                break;
            }
            if(cnt<left) prev=head;
            cnt++;
            head=head->next;
            
        }
        revend->next=NULL;
        ListNode* rev = reverse(revhead);
        if(prev!=NULL){
            prev->next=rev;
            while(rev->next){
                rev=rev->next;
            }
            rev->next=next;
            return t;
        }
            ListNode* temp=rev;
             while(temp->next){
                temp=temp->next;
             }
             temp->next=next;
             return rev;
        
        
    }
};