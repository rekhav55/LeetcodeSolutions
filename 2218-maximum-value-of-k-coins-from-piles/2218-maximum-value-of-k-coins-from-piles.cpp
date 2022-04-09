class Solution {
public:
    int f(int idx, int k, vector<vector<int>>&piles,vector<vector<int>>&dp){
        if(idx==piles.size() || k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int best = f(idx+1,k,piles,dp);
        // int take = INT_MIN;
        int sum =0;
        for(int i=0;i<min(k,(int)piles[idx].size());i++){
            sum+=piles[idx][i];
            best = max(best,sum+f(idx+1,k-(i+1),piles,dp));
        }
        return dp[idx][k]=best;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(), vector<int>(k+1,-1));
        return f(0,k,piles,dp);
    }
};