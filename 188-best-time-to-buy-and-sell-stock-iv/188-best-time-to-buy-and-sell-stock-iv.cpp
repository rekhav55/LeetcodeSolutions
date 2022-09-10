class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
         vector<vector<int>>dp(price.size()+1,vector<int>(2*k+1,-1));
        for(int i=0;i<2*k;i++) dp[price.size()][i]=0;
        for(int i=0;i<=price.size();i++) dp[i][2*k]=0;
        for(int idx=price.size()-1;idx>=0;idx--){
            for(int tra=2*k-1;tra>=0;tra--){
                int profit=INT_MIN;
                if(tra%2==0){
                   profit = max(-price[idx]+dp[idx+1][tra+1],dp[idx+1][tra]);
                 }
                 else{
                   profit = max(price[idx]+dp[idx+1][tra+1],dp[idx+1][tra]);
                  }
                  dp[idx][tra]=profit;
            }
        }
        return dp[0][0];
    }
};