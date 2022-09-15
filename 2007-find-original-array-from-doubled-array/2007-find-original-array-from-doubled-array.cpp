class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
         vector<int> v;
        if(c.size() & 1) return {};
        
        unordered_map<int, int> mp;
        for(auto x:c){
            mp[x]++;
        }
        
        sort(c.begin(), c.end());
        for(int i=0; i<c.size(); i++){
            if(mp[c[i]]==0) continue;
            if(mp[c[i]*2]==0) return {};
            mp[c[i]]--;
            mp[c[i]*2]--;
            v.push_back(c[i]);
        }
        return v;
    }
};