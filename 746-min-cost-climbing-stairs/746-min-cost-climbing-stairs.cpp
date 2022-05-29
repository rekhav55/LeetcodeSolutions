class Solution {
public:
    int f(int i, vector<int>&cost,vector<int>&dp){
        if(i==cost.size()) return 0;
        if(i>cost.size()) return 1e8;
        if(dp[i]!=-1) return dp[i];
        int one =INT_MAX,two=INT_MAX;
        one = cost[i]+f(i+1,cost,dp);
        two=cost[i]+f(i+2,cost,dp);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp1(cost.size()+1,-1);
        vector<int>dp2(cost.size()+1,-1);
        int ans = min(f(0,cost,dp1),f(1,cost,dp2));
        return ans;
    }
};