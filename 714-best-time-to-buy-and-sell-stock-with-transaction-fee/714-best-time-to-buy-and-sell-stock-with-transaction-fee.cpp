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
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return f(0,prices,fee,1,dp);
        dp[prices.size()][0]=dp[prices.size()][1]=0;
        for(int idx=prices.size()-1;idx>=0;idx--){
            for(int buy =0;buy<=1;buy++){
                int profit=0;
                if(buy){
           profit = max(-prices[idx]-fee+dp[idx+1][0], dp[idx+1][1]); 
        }
        else{
            profit=max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);
        }
        
        dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};