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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len=0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }
        vector<int>res;
        if(len==0 ||len==1 || len==2){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        len = 2;
        while(curr->next){
            if(curr->val < prev->val && curr->val<curr->next->val){
                res.push_back(len);
            }
            else if(curr->val>prev->val && curr->val>curr->next->val){
                res.push_back(len);
            }
            prev=curr;
            curr=curr->next;
            len++;
        }
        
        if(res.size()<2){
            return {-1,-1};
        }
        vector<int>ans;
        int t = INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            t = min(res[i+1]-res[i],t);
        }
        ans.push_back(t);
        ans.push_back(res[res.size()-1]-res[0]);
        return ans;
    }
};