class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        map<string,pair<int,int>>frequency;
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int minimum=INT_MAX, freq=0;
            for(int j=0;j<words[i].size();j++){
                if(words[i][j]-0<=minimum) minimum = words[i][j]-0;
            }
            for(int j=0;j<words[i].size();j++){
                if(words[i][j]-0==minimum) freq++;
            }
            if(frequency.find(words[i])!=frequency.end()){
                frequency[words[i]].first=frequency[words[i]].first+1;
            }
            else{
                frequency[words[i]]= make_pair(1,freq);
            }
        }
        
        for(int i=0;i<queries.size();i++){
            int minimum = INT_MAX, freq=0;
            for(int j=0;j<queries[i].size();j++){
                if(queries[i][j]-0 <=minimum) minimum = queries[i][j]-0;
            }
            for(int j=0;j<queries[i].size();j++){
                if(queries[i][j]-0==minimum) freq++;
            }
            int count=0;
            for(auto it: frequency){
                if(it.second.second>freq){
                    count = count + (it.second.first);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};