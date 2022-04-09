class Solution {
public:
    bool mycomp(pair<int,int>&a, pair<int,int>&b){
        if(a.first>b.first) return true;
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        
         auto comp = [&mp](int n1, int n2) { return mp[n1] > mp[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto it:mp){
            pq.push(it.first);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>res;
        while(pq.empty()==false){
            int p = pq.top();
            res.push_back(p);
            pq.pop();
        }
        return res;
    }
};