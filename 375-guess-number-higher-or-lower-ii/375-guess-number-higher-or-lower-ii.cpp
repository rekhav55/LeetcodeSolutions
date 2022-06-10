class Solution {
public:
    int f(int a, int b,vector<vector<int>>&dp){
        if(a>=b) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        int low=INT_MAX, high = INT_MAX,temp=INT_MAX;
        for(int i=a;i<=b;i++){
            low = i + f(a,i-1,dp);
            high = i+f(i+1,b,dp);
            temp = min(temp,max(low,high));
        }
        return dp[a][b]=temp;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,n,dp);
    }
};