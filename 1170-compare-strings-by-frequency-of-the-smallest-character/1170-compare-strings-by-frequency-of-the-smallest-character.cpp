class Solution {
public:
    int countFreq(string word){
        vector<int>f(26,0);
        int ans;
        for(int i=0;i<word.size();i++){
            f[word[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if(f[i]){
                return f[i];
            }
        }
        return -1;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>count(words.size(),0);
        vector<int>result;
        for(int i=0;i<words.size();i++){
            int freq=countFreq(words[i]);
            count[i]=freq;
        }
        sort(count.begin(),count.end());
        for(int i=0;i<queries.size();i++){
            int f = countFreq(queries[i]);
            int ans = upper_bound(count.begin(),count.end(),f)-count.begin();
            result.push_back(count.size()-ans);
        }
        return result;
//         map<string,pair<int,int>>frequency;
//         vector<int>ans;
//         for(int i=0;i<words.size();i++){
//             int minimum=INT_MAX, freq=0;
//             for(int j=0;j<words[i].size();j++){
//                 if(words[i][j]-0<=minimum) minimum = words[i][j]-0;
//             }
//             for(int j=0;j<words[i].size();j++){
//                 if(words[i][j]-0==minimum) freq++;
//             }
//             if(frequency.find(words[i])!=frequency.end()){
//                 frequency[words[i]].first=frequency[words[i]].first+1;
//             }
//             else{
//                 frequency[words[i]]= make_pair(1,freq);
//             }
//         }
        
//         for(int i=0;i<queries.size();i++){
//             int minimum = INT_MAX, freq=0;
//             for(int j=0;j<queries[i].size();j++){
//                 if(queries[i][j]-0 <=minimum) minimum = queries[i][j]-0;
//             }
//             for(int j=0;j<queries[i].size();j++){
//                 if(queries[i][j]-0==minimum) freq++;
//             }
//             int count=0;
//             for(auto it: frequency){
//                 if(it.second.second>freq){
//                     count = count + (it.second.first);
//                 }
//             }
//             ans.push_back(count);
//         }
//         return ans;
    }
};