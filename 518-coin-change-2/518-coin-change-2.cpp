class Solution {
public:
    int f(int idx, int amt, vector<int>&coins,vector<vector<int>>&dp){
        if(idx==coins.size()) return 0;
        if(amt==0) return 1;
        if(amt<0) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int take = f(idx,amt-coins[idx],coins,dp);
        int no_take = f(idx+1,amt,coins,dp);
        return dp[idx][amt]=take+no_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);
    }
};