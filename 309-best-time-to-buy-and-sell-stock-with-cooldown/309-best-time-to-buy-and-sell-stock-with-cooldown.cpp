class Solution {
public:
    int f(int idx, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=INT_MIN;
        if(buy==0){
            profit = max(-prices[idx]+f(idx+1,1,prices,dp),f(idx+1,0,prices,dp));
        }
        else{
            profit = max(f(idx+1,1,prices,dp),prices[idx]+f(idx+2,0,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+5,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};