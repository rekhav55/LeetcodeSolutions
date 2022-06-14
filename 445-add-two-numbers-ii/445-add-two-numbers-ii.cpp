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
        stack<int>s1,s2;
        ListNode* t = l1;
        ListNode* t1 = l2;
        ListNode* head=NULL;
        while(t){
            s1.push(t->val);
            t=t->next;
        }
        while(t1){
            s2.push(t1->val);
            t1=t1->next;
        }
        int carry=0,first,second,sum=0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                first = s1.top();
                s1.pop();
            }
            else first=0;
            if(!s2.empty()){
                second = s2.top();
                s2.pop();
            }
            else second=0;
            int sum = first+second+carry;
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            node->next = head;
            head = node;
        }
        if(carry==1){
            ListNode* node = new ListNode(carry);
            node->next=head;
            head=node;
        }
        return head;
    }
};