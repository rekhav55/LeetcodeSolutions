class Solution {
public:
    int f(int i,int j,string &s, string &t,vector<vector<int>>&dp){
        if(i==s.size() || j==t.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+f(i+1,j+1,s,t,dp);
        }
        else{
            return dp[i][j]=max(f(i,j+1,s,t,dp),f(i+1,j,s,t,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return f(0,0,text1,text2,dp);
    }
};