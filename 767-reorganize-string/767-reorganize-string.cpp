class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto &it:s) mp[it]++;
        priority_queue<pair<int,char>> pq;
        for(auto &[i,j]:mp) pq.push({j,i});
        string res;
        pair<int,char> prev={0,'x'};
        while(pq.size()){
            auto cur=pq.top();pq.pop();
            res+=cur.second;
            cur.first--;
            if(prev.first>0) pq.push(prev);
            if(cur.first>0) prev=cur;
            else prev={0,'x'};
        }
        return res.size()==s.size()?res:"";
    }
};