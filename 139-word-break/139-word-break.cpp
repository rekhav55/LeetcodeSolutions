class Solution {
public:
    set<string>st;
    bool f(int idx, string &s,vector<int>&dp){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        for(int j=idx;j<s.size();j++){
            string temp = s.substr(idx,j-idx+1);
            if(st.find(temp)!=st.end()){
                if(f(j+1,s,dp)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict){
            st.insert(it);
        }
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};