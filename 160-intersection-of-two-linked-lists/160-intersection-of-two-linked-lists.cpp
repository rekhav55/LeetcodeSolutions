/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         set<ListNode*>st;
//         ListNode* temp = headA;
//         while(temp!=NULL){
//             st.insert(temp);
//             temp=temp->next;
//         }
        
//         ListNode* temp1=headB;
//         while(temp1!=NULL){
//             if(st.find(temp1)!=st.end()){
//                 return temp1;
//             }
//             else{
//                 temp1=temp1->next;
//             }
//         }
//         return NULL;
        ListNode *a=headA, *b=headB;
        int count1=0, count2=0;
		
		//counting lengths of both the linked list
        for(ListNode *curr=headA;curr!=NULL; curr=curr->next) count1++;
        for(ListNode *curr=headB;curr!=NULL; curr=curr->next) count2++;
        
		//If linked list 1 is longer, we traverse it, till it becomes equal to length of second...
        while(count1>count2) {
            count1--;
            a=a->next;
        }
        
		//If second one is longer, we traverse it, till it becomes equal to length of first...
        while(count2>count1) {
            count2--;
            b=b->next;
        }
        
		//Since length of both is now equal, we traverse them together, and break if the nodes become equal...
        while(a!=b) {
            a=a->next;
            b=b->next;
        }
        
        return a;
    
    }
};