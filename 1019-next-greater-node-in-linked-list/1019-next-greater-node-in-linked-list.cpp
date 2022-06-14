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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>>st;
        vector<int>v(10000);
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            while(!st.empty() && st.top().first<temp->val){
                pair<int,int>t = st.top();
                st.pop();
                v[t.second]=temp->val;
            }
            st.push({temp->val,cnt});
            cnt++;
            temp=temp->next;
        }
        
        while(!st.empty()){
            pair<int,int>t = st.top();
            st.pop();
            v[t.second]=0;
        }
        v.resize(cnt);
        return v;
    }
};