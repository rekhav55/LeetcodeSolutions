class Solution {
public:
    bool isPerfect(int n){
        if(ceil((double)sqrt(n))==floor((double)sqrt(n))) return true;
        return false;
    }
    int f(int n,vector<int>&dp){
        if(n==1) return 1;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int val=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ans = INT_MAX;
            // if(isPerfect(i)){
            //     ans=1+f(n-i,dp);
            //     val=min(val,ans);
            // }
            ans = 1 + f(n-(i*i),dp);
            val=min(val,ans);
        }
        return dp[n]=val;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
