class Solution {
public:
    int lps(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+lps(i+1,j+1,s,t,dp);
        }
        else{
            return dp[i][j]=max(lps(i,j+1,s,t,dp),lps(i+1,j,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string temp = "";
        for(int i=s.size()-1;i>=0;i--){
            temp+=s[i];
        }
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return lps(0,0,s,temp,dp);
    }
};