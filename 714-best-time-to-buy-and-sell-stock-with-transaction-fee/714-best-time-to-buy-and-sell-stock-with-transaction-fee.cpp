class Solution {
public:
    int f(int idx, vector<int>&prices, int fee, int buy,vector<vector<int>>&dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
           profit = max(-prices[idx]-fee+f(idx+1,prices,fee,0,dp), f(idx+1,prices,fee,1,dp)); 
        }
        else{
            profit=max(prices[idx]+f(idx+1,prices,fee,1,dp),f(idx+1,prices,fee,0,dp));
        }
        
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,fee,1,dp);
    }
};