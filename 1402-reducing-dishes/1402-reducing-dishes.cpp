class Solution {
public:
    int f(int idx, int time, vector<int>&a, vector<vector<int>>&dp){
        if(idx>=a.size()) return 0;
        if(dp[idx][time]!=-1) return dp[idx][time];
        int pick=0,nopick=0;
        pick = a[idx]*time + f(idx+1,time+1,a,dp);
        nopick = f(idx+1,time,a,dp);
        return dp[idx][time]=max(pick,nopick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(505,-1));
        return f(0,1,satisfaction,dp);
    }
};