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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        
        int cnt=0;
        int sum=0;
        while(head){
            if(st.find(head->val)!=st.end()){
                sum++;
            }
            else{
                if(sum>0){
                    cnt++;
                    sum=0;
                }
            }
            head=head->next;
        }
        if(sum>0) cnt++;
        return cnt;
    }
};