class Solution {
public:
    int f(int idx, int amt, vector<int>&coins, vector<vector<int>>&dp){
        if(idx==0){
            if(amt%coins[idx]==0) return amt/coins[idx];
            return 1e9;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int no_take = f(idx-1,amt,coins,dp);
        int take = INT_MAX;
        if(coins[idx]<=amt) take=1 + f(idx,amt-coins[idx],coins,dp);
        return dp[idx][amt]=min(take,no_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans =f(coins.size()-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};