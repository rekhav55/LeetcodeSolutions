class Solution {
public:
    int helper(vector<string>&str, int m, int n, int idx,vector<vector<vector<int>>>&dp){
        if(idx>=str.size()) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int zero=0,one=0;
        for(int i=0;i<str[idx].size();i++){
            if(str[idx][i]=='1') one++;
            else zero++;
        } 
        int take = 0, no_take=0;
        if(zero<=m && one<=n && m>=0 && n>=0){
            take = 1 + helper(str,m-zero,n-one,idx+1,dp);
        }
        no_take = helper(str,m,n,idx+1,dp);
        return dp[idx][m][n]=max(take,no_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int idx = strs.size();
        vector<vector<vector<int>>>dp(idx+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,m,n,0,dp);
    }
};